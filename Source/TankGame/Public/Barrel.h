// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Barrel.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API UBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float);
};
