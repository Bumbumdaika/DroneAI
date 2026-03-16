// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Servises/BTService05.h"
#include "AIController.h"

UBTService05::UBTService05()
{
	NodeName = "BTService05";
}

void UBTService05::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	
	if (!AIController)
	{
		return;
	}
}
