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

	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable)
		ATankPawn* GetControlledTank()const; 
private:
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&)const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33f;

	bool GetLookDirection(FVector2D,FVector&)const;
	bool GetLookVectorHitLocation(FVector,FVector&)const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

};
