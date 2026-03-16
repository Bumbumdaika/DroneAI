// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTT_Task05.h"
#include "AIController.h"

UBTT_Task05::UBTT_Task05()
{
	NodeName = "BTT_Task05";
}

EBTNodeResult::Type UBTT_Task05::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}
	
	return EBTNodeResult::Succeeded;
}
