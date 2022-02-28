// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGamePlayerController.h"

void ATankGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Controller isnt possessing a tank pawn."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Possessed tank is : %s"), *ControlledTank->GetName());
	}
	
}

void ATankGamePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}

ATankPawn* ATankGamePlayerController::GetControlledTank()const
{
	return Cast<ATankPawn>(GetPawn());
}

void ATankGamePlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	
}

bool ATankGamePlayerController::GetSightRayHitLocation(FVector& HitLocation)const
{
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		UE_LOG(LogTemp,Warning,TEXT("Look Direction : %s"),*LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, HitLocation);
		
	}
	

	return true;
}

bool ATankGamePlayerController::GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection)const 
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}

bool ATankGamePlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const
{
	FHitResult OutHit;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
	FCollisionQueryParams QueryParams;
	FCollisionResponseParams ResponseParams;
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor(255, 0, 0), false, -1, 0, 5.f);
	if (GetWorld()->LineTraceSingleByChannel(OutHit, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility, QueryParams,ResponseParams))
	{
		HitLocation = OutHit.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}