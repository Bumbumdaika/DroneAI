#include "Pawn/Enemies/Tasks/BTTask_FindRandomPatrolPoint.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Pawn/Enemies/DronePawn.h"

UBTTask_FindRandomPatrolPoint::UBTTask_FindRandomPatrolPoint()
{
	NodeName = TEXT("Find Random Patrol Point");
}

EBTNodeResult::Type UBTTask_FindRandomPatrolPoint::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory
)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FindRandomPatrolPoint: AIController null"));
		return EBTNodeResult::Failed;
	}

	ADronePawn* DronePawn = Cast<ADronePawn>(AIController->GetPawn());
	if (!DronePawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FindRandomPatrolPoint: DronePawn null"));
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Blackboard)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FindRandomPatrolPoint: Blackboard null"));
		return EBTNodeResult::Failed;
	}

	const FVector Origin = DronePawn->GetHomeLocation();
	// Берем не текущую позицию, а домашнюю точку патруля

	const FVector RandomOffset(
		FMath::FRandRange(-Radius, Radius),
		FMath::FRandRange(-Radius, Radius),
		FMath::FRandRange(-Radius * 0.5f, Radius * 0.5f)
	);

	const FVector TargetLocation = Origin + RandomOffset;

	Blackboard->SetValueAsVector(TEXT("TargetLocation"), TargetLocation);

	UE_LOG(LogTemp, Warning, TEXT("BTTask_FindRandomPatrolPoint: New patrol point = %s"), *TargetLocation.ToString());

	return EBTNodeResult::Succeeded;
}