// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Servises/BTService03.h"
#include "AIController.h"

UBTService03::UBTService03()
{
	NodeName = "BTService03";
}

void UBTService03::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* Controller = OwnerComp.GetAIOwner();
	
	if (!Controller)
	{
		return;
	}
}
