// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TANKGAME_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* TankMainMesh = nullptr;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Turret = nullptr;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Barrel = nullptr;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Gun = nullptr;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* LeftTrack = nullptr;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* RightTrack = nullptr;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera = nullptr;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm = nullptr;
	UPROPERTY(EditAnywhere)
		USceneComponent* AzimuthGimbal = nullptr;

	void LookRight(float);
	void LookUp(float);

	UPROPERTY(EditAnywhere,Category = "Camera Rotate")
		float LookUpSpeed;
	UPROPERTY(EditAnywhere, Category = "Camera Rotate")
		float LookRightSpeed;
	
};
