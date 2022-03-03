// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPawn.h"
#include "Barrel.h"
#include "Projectile.h"
#include "Track.h"
#include "Turret.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ATankPawn::ATankPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankMainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankMainMesh"));
	Turret = CreateDefaultSubobject<UTurret>(TEXT("Turret"));
	Barrel = CreateDefaultSubobject<UBarrel>(TEXT("Barrel"));
	Gun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun"));
	LeftTrack = CreateDefaultSubobject<UTrack>(TEXT("LeftTrack"));
	RightTrack = CreateDefaultSubobject<UTrack>(TEXT("RightTrack"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	AzimuthGimbal = CreateDefaultSubobject<USceneComponent>(TEXT("AzimuthGimbal"));
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(TEXT("TankAimingComponent"));
	TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(TEXT("TankMovementComponent"));


	RootComponent = TankMainMesh;
	Turret->AttachToComponent(TankMainMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("Turret"));
	Barrel->AttachToComponent(Turret, FAttachmentTransformRules::KeepRelativeTransform, FName("Barrel"));
	Gun->AttachToComponent(Turret, FAttachmentTransformRules::KeepRelativeTransform, FName("Gun"));
	LeftTrack->AttachToComponent(TankMainMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("LeftTrack"));
	RightTrack->AttachToComponent(TankMainMesh, FAttachmentTransformRules::KeepRelativeTransform, FName("RightTrack"));
	AzimuthGimbal->SetupAttachment(RootComponent);
	SpringArm->SetupAttachment(AzimuthGimbal);
	Camera->SetupAttachment(SpringArm);


}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();

	TankAimingComponent->Initialise(Barrel, Turret);
	TankMovementComponent->Initialise(LeftTrack, RightTrack);
}

// Called every frame
void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis(FName("LookRight"), this, &ATankPawn::LookRight);
	InputComponent->BindAxis(FName("LookUp"), this, &ATankPawn::LookUp);
	InputComponent->BindAction(FName("Fire"), EInputEvent::IE_Pressed, this, &ATankPawn::Fire);
	InputComponent->BindAxis(FName("Forward"), this->TankMovementComponent, &UTankMovementComponent::IntendMoveForward);
	InputComponent->BindAxis(FName("TurnRight"), this->TankMovementComponent, &UTankMovementComponent::IntendTurnRight);
}

void ATankPawn::LookRight(float AxisValue)
{
	AzimuthGimbal->AddLocalRotation(FRotator(0.f, GetWorld()->GetDeltaSeconds() * AxisValue * LookRightSpeed, 0.f));
}

void ATankPawn::LookUp(float AxisValue)
{
	SpringArm->AddLocalRotation(FRotator(GetWorld()->GetDeltaSeconds() * AxisValue * LookUpSpeed, 0.f, 0.f));
}

void ATankPawn::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}

void ATankPawn::Fire()
{
	bool bIsReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && bIsReloaded)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Fire function invoked."));
		FActorSpawnParameters SpawnParameters;
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")), SpawnParameters);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
	else
	{
		return;
	}

}

