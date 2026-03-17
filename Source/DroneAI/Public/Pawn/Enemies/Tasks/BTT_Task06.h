// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Task06.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API UBTT_Task06 : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_Task06();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory); 
	
	
};
