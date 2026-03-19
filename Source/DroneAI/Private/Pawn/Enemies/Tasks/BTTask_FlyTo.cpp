#include "Pawn/Enemies/Tasks/BTTask_FlyTo.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FlyTo::UBTTask_FlyTo()
{
	NodeName = TEXT("Fly To");
	bNotifyTick = true;
	
	TargetLocationKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FlyTo, TargetLocationKey));

}

EBTNodeResult::Type UBTTask_FlyTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FlyTo: AIController is null"));
		return EBTNodeResult::Failed;
	}

	APawn* ControlledPawn = AIController->GetPawn();
	if (!ControlledPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FlyTo: ControlledPawn is null"));
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FlyTo: BlackboardComp is null"));
		return EBTNodeResult::Failed;
	}

	const FVector TargetLocation = BlackboardComp->GetValueAsVector(TargetLocationKey.SelectedKeyName);

	if (TargetLocation.IsNearlyZero())
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FlyTo: TargetLocation is zero"));
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::InProgress;
}

void UBTTask_FlyTo::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds
)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	APawn* ControlledPawn = AIController->GetPawn();
	if (!ControlledPawn)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	const FVector CurrentLocation = ControlledPawn->GetActorLocation();
	const FVector TargetLocation = BlackboardComp->GetValueAsVector(TargetLocationKey.SelectedKeyName);

	const float DistanceToTarget = FVector::Dist(CurrentLocation, TargetLocation);

	if (DistanceToTarget <= AcceptanceRadius)
	{
		UE_LOG(LogTemp, Log, TEXT("BTTask_FlyTo: Reached target"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}

	const FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
	ControlledPawn->AddMovementInput(Direction, 1.0f);
}