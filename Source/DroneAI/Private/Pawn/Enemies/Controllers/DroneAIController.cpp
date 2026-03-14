// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/DroneAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"


ADroneAIController::ADroneAIController()
{
	BlackboardComponentRef = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponentRef"));
	// CreateDefaultSubobject<T>(...) — создает встроенный UObject-компонент актора

	BehaviorTreeComponentRef = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponentRef"));
	// UBehaviorTreeComponent — исполняет узлы и логику Behavior Tree
	
}

void ADroneAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (!HasAuthority())
	{
		return;
	}
	// HasAuthority() — проверяет, что логика выполняется на сервере

	if (!BehaviorTreeAsset)
	{
		UE_LOG(LogTemp, Warning, TEXT("DroneAIController: BehaviorTreeAsset is null"));
		return;
	}
	// UE_LOG(...) — вывод сообщения в Output Log Unreal
	
	if (!BehaviorTreeAsset->BlackboardAsset)
	{
		UE_LOG(LogTemp, Warning, TEXT("DroneAIController: BlackboardAsset is null inside BehaviorTreeAsset"));
		return;
	}
	
	UBlackboardComponent* CreatedBlackboard = nullptr;
	// UBlackboardComponent* — указатель на blackboard, который вернет UseBlackboard(...)

	const bool bBlackboardInitialized = UseBlackboard(BehaviorTreeAsset->BlackboardAsset, CreatedBlackboard);
	// UseBlackboard(...) — создает/инициализирует Blackboard на основе BlackboardAsset

	if (!bBlackboardInitialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("DroneAIController: Failed to initialize blackboard"));
		return;
	}

	RunBehaviorTree(BehaviorTreeAsset);
	// RunBehaviorTree(...) — запускает дерево поведения для этого AIController
}
