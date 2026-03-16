// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator01.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTDecorator01 : public UBTDecorator
{
	GENERATED_BODY()
	
public: 
	UBTDecorator01();
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
	
};
