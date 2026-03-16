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

	virtual EBTNodeResult::Type ExecuteTask(
		UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory
	) override;

public:

	UPROPERTY(EditAnywhere, Category="AI")
	float Radius = 1000.f;
protected:
	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Drone|AI")
	FVector HomeLocation;
	// FVector — точка, вокруг которой дрон патрулирует
	
public:

	FORCEINLINE FVector GetHomeLocation() const
	{
		return HomeLocation;
	}
};
