// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/AIController01.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

AAIController01::AAIController01()
{
	
}

void AAIController01::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}