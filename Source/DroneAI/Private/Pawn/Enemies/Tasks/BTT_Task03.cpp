// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTT_Task03.h"
#include "AIController.h"

UBTT_Task03::UBTT_Task03()
{
	NodeName = "BTT_Task03";
}

EBTNodeResult::Type UBTT_Task03::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}
	
	return EBTNodeResult::Succeeded;
}
