// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankGameAIController.generated.h"

class ATankPawn;
/**
 * 
 */
UCLASS()
class TANKGAME_API ATankGameAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		float AcceptanceRadius = 3000.f;

	

};
