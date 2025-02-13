// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPCAIController.h"
#include "Characters/AI_NPC1.h"


void ANPCAIController::OnPossess(APawn* InPawn)
{

    Super::OnPossess(InPawn);
    if (AAI_NPC1* const npc = Cast<AAI_NPC1>(InPawn))
    {
        if (UBehaviorTree* const tree = npc->BehaviorTree)
        {
            RunBehaviorTree(tree);
        }
    }
}
