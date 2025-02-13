// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC1AIPerceptionComponent.h"
#include "AIController.h"
#include "Characters/AI_NPC1.h"

#include "Perception/AISense_Sight.h"
#include <Kismet/GameplayStatics.h>



AActor* UNPC1AIPerceptionComponent::GetClosestEnemy() const
{
	TArray<AActor*> PercieveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PercieveActors);
	if(PercieveActors.Num() == 0) return nullptr;

	const auto Controller = Cast <AAIController>(GetOwner());
	if (!Controller) return nullptr;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn) return nullptr;

	float BestDistance = MAX_FLT;
	AActor* BestPawn = nullptr;

	for (const auto p : PercieveActors)
	{
		auto CurrentDistance = (p->GetActorLocation() - Pawn->GetActorLocation()).Size();
		if (CurrentDistance < BestDistance)
		{
			BestDistance = CurrentDistance;
			BestPawn = p;
		}
	}
	return BestPawn;
}
