// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/NPCMoveTo.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "NavigationSystem.h"

UNPCMoveTo::UNPCMoveTo(FObjectInitializer const&)
{
	NodeName = "NEXT LOCATION";
}

EBTNodeResult::Type UNPCMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto BlackBoard = OwnerComp.GetBlackboardComponent();

	if (!Controller || !BlackBoard) return EBTNodeResult::Failed;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn)return EBTNodeResult::Failed;

	const auto NavSys = UNavigationSystemV1::GetCurrent(Pawn);
	FNavLocation NavLocation;
	const auto Found = NavSys->GetRandomReachablePointInRadius(Pawn->GetActorLocation(), Radius, NavLocation);
	if (!Found) return EBTNodeResult::Failed;

	BlackBoard->SetValueAsVector(AimLocationKey.SelectedKeyName, NavLocation.Location);

	FVector Start = NavLocation.Location;
	FVector End(NavLocation.Location.X, NavLocation.Location.Y, NavLocation.Location.Z + 100);
	
	DrawDebugLine(GetWorld(), NavLocation.Location, End, FColor::Red, false, 1.0f, 21.0f);

	return EBTNodeResult::Succeeded;

}
