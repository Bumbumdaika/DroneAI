// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Servises/BTService04.h"
#include "AIController.h"


UBTService04::UBTService04()
{
	NodeName = "BTService04";
}

void UBTService04::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	
	if (!AIController)
	{
		return;
	}
}



