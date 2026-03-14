// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTTask_FindRandomPatrolPoint.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindRandomPatrolPoint::UBTTask_FindRandomPatrolPoint()
{
	NodeName = TEXT("Find Random Point 3D");
}
EBTNodeResult::Type UBTTask_FindRandomPatrolPoint::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory
)
{
	AAIController* AIController = OwnerComp.GetAIOwner();

	if (!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController null"));
		return EBTNodeResult::Failed;
	}

	APawn* Pawn = AIController->GetPawn();

	if (!Pawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn null"));
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	if (!Blackboard)
	{
		UE_LOG(LogTemp, Warning, TEXT("Blackboard null"));
		return EBTNodeResult::Failed;
	}

	FVector Origin = Pawn->GetActorLocation();

	FVector RandomOffset = FVector(
		FMath::FRandRange(-Radius, Radius),
		FMath::FRandRange(-Radius, Radius),
		FMath::FRandRange(-Radius * 0.5f, Radius * 0.5f)
	);

	FVector TargetLocation = Origin + RandomOffset;

	Blackboard->SetValueAsVector("TargetLocation", TargetLocation);

	return EBTNodeResult::Succeeded;
}
