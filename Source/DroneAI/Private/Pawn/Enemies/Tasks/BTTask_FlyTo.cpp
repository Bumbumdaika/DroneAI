// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTTask_FlyTo.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FlyTo::UBTTask_FlyTo()
{
	NodeName = TEXT("Fly To");

	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_FlyTo::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory
)
{
	return EBTNodeResult::InProgress;
}

void UBTTask_FlyTo::TickTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory,
	float DeltaSeconds
)
{
	AAIController* AIController = OwnerComp.GetAIOwner();

	if (!AIController)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	APawn* Pawn = AIController->GetPawn();

	if (!Pawn)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	FVector TargetLocation = Blackboard->GetValueAsVector("TargetLocation");

	FVector CurrentLocation = Pawn->GetActorLocation();

	float Distance = FVector::Dist(CurrentLocation, TargetLocation);

	if (Distance <= AcceptanceRadius)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}

	FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();

	Pawn->AddMovementInput(Direction, 1.0f);
}

