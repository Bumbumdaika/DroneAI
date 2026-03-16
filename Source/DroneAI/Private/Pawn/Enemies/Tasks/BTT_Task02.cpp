// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTT_Task02.h"
#include "AIController.h"

UBTT_Task02::UBTT_Task02()
{
	NodeName = "BTT_Task02";
}

EBTNodeResult::Type UBTT_Task02::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();

	if (!AIController)
	{
		return EBTNodeResult::Failed;		
	}
	return EBTNodeResult::Succeeded;
}
