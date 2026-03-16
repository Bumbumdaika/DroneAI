// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/AIController04.h"
#include "BehaviorTree/BehaviorTree.h"

AAIController04::AAIController04()
{
	
}

void AAIController04::OnPossess(APawn* aPawn)
{
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}
