// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Task01.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTT_Task01 : public UBTTaskNode
{
	GENERATED_BODY()
	
public: 
	UBTT_Task01();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
