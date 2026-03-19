#include "Pawn/Enemies/Tasks/BTTask_FindRandomPatrolPoint.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Pawn/Enemies/DronePawn.h"

UBTTask_FindRandomPatrolPoint::UBTTask_FindRandomPatrolPoint()
{
	NodeName = TEXT("Find Random Point");
}

EBTNodeResult::Type UBTTask_FindRandomPatrolPoint::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory
)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FindRandomPoint3D: AIController is null"));
		return EBTNodeResult::Failed;
	}

	APawn* ControlledPawn = AIController->GetPawn();
	if (!ControlledPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FindRandomPoint3D: ControlledPawn is null"));
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FindRandomPoint3D: BlackboardComp is null"));
		return EBTNodeResult::Failed;
	}

	const FVector Origin = ControlledPawn->GetActorLocation();

	FVector RandomOffset;
	FVector TargetLocation;
	bool bFoundValidPoint = false;

	for (int32 Attempt = 0; Attempt < 10; ++Attempt)
	{
		RandomOffset = FVector(
			FMath::FRandRange(-RadiusXY, RadiusXY),
			FMath::FRandRange(-RadiusXY, RadiusXY),
			FMath::FRandRange(-RadiusZ, RadiusZ)
		);

		if (RandomOffset.Size() < MinDistance)
		{
			continue;
		}

		TargetLocation = Origin + RandomOffset;
		bFoundValidPoint = true;
		break;
	}

	if (!bFoundValidPoint)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FindRandomPoint3D: Failed to find valid random point"));
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsVector(TargetLocationKey.SelectedKeyName, TargetLocation);

	UE_LOG(LogTemp, Log, TEXT("BTTask_FindRandomPoint3D: TargetLocation = %s"), *TargetLocation.ToString());

	return EBTNodeResult::Succeeded;
}