// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void RotateTurret(float);
private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 5.f;
	UPROPERTY(EditAnywhere)
		float MaxRotation = 180.f;
	UPROPERTY(EditAnywhere)
		float MinRotation = -180.f;
};
