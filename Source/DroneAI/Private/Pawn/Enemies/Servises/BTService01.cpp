// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Servises/BTService01.h"
#include "AIController.h"

UBTService01::UBTService01()
{
	NodeName = "BTService01";
}

void UBTService01::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	AAIController* AIController = OwnerComp.GetAIOwner();
	
	if (!AIController)
	{
		return;
	}
}

