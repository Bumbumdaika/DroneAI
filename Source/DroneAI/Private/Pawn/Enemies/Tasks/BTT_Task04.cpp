// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTT_Task04.h"
#include "AIController.h"

UBTT_Task04::UBTT_Task04()
{
	NodeName = "BTT_Task04";
}

EBTNodeResult::Type UBTT_Task04::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComponent.GetAIOwner();
	
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}
	
	return EBTNodeResult::Succeeded;
	
}



