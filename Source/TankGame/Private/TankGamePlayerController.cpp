// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGamePlayerController.h"

ATankPawn* ATankGamePlayerController::GetControlledTank()const
{
	return Cast<ATankPawn>(GetPawn());
}

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
		UE_LOG(LogTemp, Warning, TEXT("Possessed tank is : %s"), *ControlledTank->GetName());
	}
	
}