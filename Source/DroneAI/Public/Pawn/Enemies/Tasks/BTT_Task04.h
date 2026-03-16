// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Task04.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTT_Task04 : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_Task04();
	
virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory);
	
	
};
