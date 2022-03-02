// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGameAIController.h"
#include "TankPawn.h"

void ATankGameAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = Cast<ATankPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATankPawn>(GetPawn());

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller isnt possessing a tank pawn."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed AI tank is : %s"), *ControlledTank->GetName());
	}
	
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
	
	auto PlayerTank = Cast<ATankPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATankPawn>(GetPawn());
	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//ControlledTank->Fire();
	}
	
}



