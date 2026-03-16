// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTT_Task01.h"
#include "AIController.h"

UBTT_Task01::UBTT_Task01()
{
	NodeName = "BTT_Task01";
	
}

EBTNodeResult::Type UBTT_Task01::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Succeeded;
}

