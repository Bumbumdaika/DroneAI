// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Tasks/BTT_Task06.h"
#include "AIController.h"


UBTT_Task06::UBTT_Task06()
{
	NodeName = "BTT_Task06";
}

EBTNodeResult::Type UBTT_Task06::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner() ;
	if (!AIController)
	{
		return EBTNodeResult::Failed;
	}
	
	return EBTNodeResult::Succeeded;
}
