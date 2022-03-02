// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "Track.h"

void UTankMovementComponent::Initialise(UTrack* LeftTrackToSet, UTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		return;
	}
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Error, TEXT("Intend move forward throw : %f"), Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

