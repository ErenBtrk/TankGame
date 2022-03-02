// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class ATankPawn;
class UTrack;
/**
 *
 */
UCLASS()
class TANKGAME_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	void IntendMoveForward(float);

	void Initialise(UTrack*, UTrack*);
private:
	UTrack* LeftTrack = nullptr;
	UTrack* RightTrack = nullptr;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float Speed = 50.f;
};
