// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Track.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API UTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void SetThrottle(float);

	UPROPERTY(EditAnywhere)
		float TrackMaxDrivingForce = 400000.f;
};
