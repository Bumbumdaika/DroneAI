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
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FlyTo: AIController null"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	APawn* Pawn = AIController->GetPawn();
	if (!Pawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FlyTo: Pawn null"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Blackboard)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}
	
	if (!Blackboard)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FlyTo: Blackboard null"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}

	const FVector TargetLocation = Blackboard->GetValueAsVector(TEXT("TargetLocation"));
	const FVector CurrentLocation = Pawn->GetActorLocation();

	const float Distance = FVector::Dist(CurrentLocation, TargetLocation);

	if (Distance <= AcceptanceRadius)
	{
		UE_LOG(LogTemp, Warning, TEXT("BTTask_FlyTo: Reached target"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}

	const FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();

	Pawn->AddMovementInput(Direction, 1.0f);
}