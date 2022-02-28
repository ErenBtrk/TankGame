// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameAIController.h"

void ATankGameAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller isnt possessing a tank pawn."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed AI tank is : %s"), *ControlledTank->GetName());
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller %s couldnt find the Player Tank."),*ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller %s found the Player tank : %s"), *ControlledTank->GetName() ,*PlayerTank->GetName());
	}

}

void ATankGameAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATankPawn* ATankGameAIController::GetPlayerTank()const
{
	return Cast<ATankPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATankPawn* ATankGameAIController::GetControlledTank()const
{
	return Cast<ATankPawn>(GetPawn());
}