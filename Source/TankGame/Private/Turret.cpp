// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"

void UTurret::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = GetRelativeRotation().Yaw + RotationChange;
	auto ClampedRotation = FMath::Clamp<float>(RawNewRotation, MinRotation, MaxRotation);
	SetRelativeRotation(FRotator(0.f, ClampedRotation, 0.f));
}