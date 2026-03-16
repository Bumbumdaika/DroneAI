// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService02.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTService02 : public UBTService
{
	GENERATED_BODY()
	
public:
	UBTService02();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
