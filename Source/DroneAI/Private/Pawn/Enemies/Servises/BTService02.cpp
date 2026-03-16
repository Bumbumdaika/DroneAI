// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Servises/BTService02.h"
#include "AIController.h"

UBTService02::UBTService02()
{
	NodeName = "BTService02";
}

void UBTService02::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* Controller = OwnerComp.GetAIOwner();
	
	if (!Controller)
	{
		return;
	}
}

