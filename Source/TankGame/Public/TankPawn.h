// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UTankAimingComponent;
class UBarrel;
class UTurret;
class AProjectile;
class UTrack;
class UTankMovementComponent;

UCLASS()
class TANKGAME_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();

	void AimAt(FVector);

	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(EditAnywhere)
		UTankMovementComponent* TankMovementComponent = nullptr;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* TankMainMesh = nullptr;
	UPROPERTY(EditAnywhere)
		UTurret* Turret = nullptr;
	UPROPERTY(EditAnywhere)
		UBarrel* Barrel = nullptr;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Gun = nullptr;
	UPROPERTY(EditAnywhere)
		UTrack* LeftTrack = nullptr;
	UPROPERTY(EditAnywhere)
		UTrack* RightTrack = nullptr;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera = nullptr;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm = nullptr;
	UPROPERTY(EditAnywhere)
		USceneComponent* AzimuthGimbal = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	void LookRight(float);
	void LookUp(float);

	UPROPERTY(EditAnywhere, Category = "Camera Rotate")
		float LookUpSpeed;
	UPROPERTY(EditAnywhere, Category = "Camera Rotate")
		float LookRightSpeed;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 100000;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float ReloadTimeInSeconds = 3.f;

	double LastFireTime = 0;



};
