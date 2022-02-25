// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankPawn.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	ATankPawn* GetControlledTank()const;

	
};
