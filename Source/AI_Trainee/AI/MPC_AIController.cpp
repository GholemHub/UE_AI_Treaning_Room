// Fill out your copyright notice in the Description page of Project Settings.


#include "MPC_AIController.h"
#include "Characters/AI_NPC1.h"

void AMPC_AIController::BeginPlay()
{
    Super::BeginPlay();

    if (BehaviorTree) // Ensure BehaviorTree is set
    {
        RunBehaviorTree(BehaviorTree);
        

    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("BehaviorTree is NULL!"));
    }
    
}

void AMPC_AIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    if (AAI_NPC1* const npc = Cast<AAI_NPC1>(InPawn))
    {
        if (UBehaviorTree* const tree = npc->BehaviorTree)
        {
            UBlackboardComponent* b;
            UseBlackboard(tree->BlackboardAsset, b);
            Blackboard = b;
            RunBehaviorTree(tree);
        }
    }
}

AMPC_AIController::AMPC_AIController(FObjectInitializer const&)
{
}
