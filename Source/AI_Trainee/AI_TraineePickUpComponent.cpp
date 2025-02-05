// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI_TraineePickUpComponent.h"

UAI_TraineePickUpComponent::UAI_TraineePickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UAI_TraineePickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UAI_TraineePickUpComponent::OnSphereBeginOverlap);
}

void UAI_TraineePickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AAI_TraineeCharacter* Character = Cast<AAI_TraineeCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
