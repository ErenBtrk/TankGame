// Fill out your copyright notice in the Description page of Project Settings.

#include "Barrel.h"
#include "Turret.h"
#include "TankPawn.h"
#include "TankAimingComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ATankPawn::ATankPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TankMainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankMainMesh"));
	Turret = CreateDefaultSubobject<UTurret>(TEXT("Turret"));
	Barrel = CreateDefaultSubobject<UBarrel>(TEXT("Barrel"));
	Gun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun"));
	LeftTrack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftTrack"));
	RightTrack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightTrack"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	AzimuthGimbal = CreateDefaultSubobject<USceneComponent>(TEXT("AzimuthGimbal"));
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(TEXT("TankAimingComponent"));

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

	TankAimingComponent->SetBarrelReference(Barrel);
	TankAimingComponent->SetTurretReference(Turret);
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
	TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
	
}