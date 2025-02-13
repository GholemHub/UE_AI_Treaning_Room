// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_FindEnemyService.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC1AIPerceptionComponent.h"



UNPC_FindEnemyService::UNPC_FindEnemyService()
{
	NodeName = "Find Enemy";
}

void UNPC_FindEnemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	auto BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard)
	{
	
		auto Controller = OwnerComp.GetAIOwner();
		if (Controller)
		{
			
			UNPC1AIPerceptionComponent* PerceptionComponent = Controller->FindComponentByClass<UNPC1AIPerceptionComponent>();
			if (PerceptionComponent) 
			{
				BlackBoard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerceptionComponent->GetClosestEnemy());
			}
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
