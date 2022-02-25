// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameAIController.h"

ATankPawn* ATankGameAIController::GetControlledTank()const
{
	return Cast<ATankPawn>(GetPawn());
}

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

}