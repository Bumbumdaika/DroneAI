// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DroneAIController.generated.h"

/**
 * 
 */
class UBehaviorTree;
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class DRONEAI_API ADroneAIController : public AAIController
{
	GENERATED_BODY()
	

	
public:
	ADroneAIController();
	
protected:
	virtual void OnPossess(APawn* InPawn) override;
	// OnPossess(...) — вызывается, когда контроллер получает управление над Pawn

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTreeAsset;
	// TObjectPtr<UBehaviorTree> — ссылка на Behavior Tree asset, который запускает ИИ

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponentRef;
	// TObjectPtr<UBehaviorTreeComponent> — компонент, который исполняет дерево поведения

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBlackboardComponent>BlackboardComponentRef;
	// TObjectPtr<UBlackboardComponent> — компонент, который хранит Blackboard keys

public:
	FORCEINLINE UBlackboardComponent* GetBlackboardComponentRef() const { return BlackboardComponentRef; }
	// FORCEINLINE UBlackboardComponent* — быстрый getter Blackboard компонента
};
