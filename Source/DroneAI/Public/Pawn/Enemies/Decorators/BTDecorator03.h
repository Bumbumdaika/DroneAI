// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator03.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTDecorator03 : public UBTDecorator
{
	GENERATED_BODY()
	
	
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
};
