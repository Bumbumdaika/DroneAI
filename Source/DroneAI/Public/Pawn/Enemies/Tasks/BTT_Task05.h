// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Task05.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTT_Task05 : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_Task05();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
