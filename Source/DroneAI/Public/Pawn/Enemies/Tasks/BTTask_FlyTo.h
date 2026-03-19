// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FlyTo.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTTask_FlyTo : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_FlyTo();
	
protected: 
	
protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetLocationKey;

	UPROPERTY(EditAnywhere, Category = "AI")
	float AcceptanceRadius = 100.0f;;
};
