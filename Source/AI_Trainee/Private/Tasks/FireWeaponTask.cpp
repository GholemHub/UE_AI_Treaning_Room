// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/FireWeaponTask.h"
#include "AIController.h"
#include "../../Public/Characters/AI_NPC1.h"


UFireWeaponTask::UFireWeaponTask(FObjectInitializer const&)
{
	NodeName = "Fire";

}

EBTNodeResult::Type UFireWeaponTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	//const auto BlackBoard = OwnerComp.GetBlackboardComponent();
	if (!Controller) return EBTNodeResult::Failed;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn)return EBTNodeResult::Failed;
	AAI_NPC1* Character = Cast<AAI_NPC1>(Pawn);
	Character->Fire();

	return EBTNodeResult::Succeeded;
}
