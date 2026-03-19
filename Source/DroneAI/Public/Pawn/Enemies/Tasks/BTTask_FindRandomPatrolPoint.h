// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindRandomPatrolPoint.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTTask_FindRandomPatrolPoint : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_FindRandomPatrolPoint();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "AI")
	float RadiusXY = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "AI")
	float RadiusZ = 300.0f;

	UPROPERTY(EditAnywhere, Category = "AI")
	float MinDistance = 300.0f;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetLocationKey;
};
