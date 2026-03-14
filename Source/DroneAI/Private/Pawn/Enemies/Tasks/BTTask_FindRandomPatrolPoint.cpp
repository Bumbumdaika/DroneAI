// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTTask_FindRandomPatrolPoint.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindRandomPatrolPoint::UBTTask_FindRandomPatrolPoint()
{
	NodeName = TEXT("Find Random Patrol Point");
}

EBTNodeResult::Type UBTTask_FindRandomPatrolPoint::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();

	if (!AIController)
		return EBTNodeResult::Failed;

	APawn* Pawn = AIController->GetPawn();

	if (!Pawn)
		return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem =
		FNavigationSystem::GetCurrent<UNavigationSystemV1>(Pawn->GetWorld());

	if (!NavSystem)
		return EBTNodeResult::Failed;

	FNavLocation RandomLocation;

	bool bFound = NavSystem->GetRandomReachablePointInRadius(
		Pawn->GetActorLocation(),
		SearchRadius,
		RandomLocation
	);

	if (bFound)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(
			PatrolPointKey.SelectedKeyName,
			RandomLocation.Location
		);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
