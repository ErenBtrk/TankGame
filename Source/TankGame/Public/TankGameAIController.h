// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankPawn.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankGameAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankGameAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	ATankPawn* GetControlledTank()const;
};
