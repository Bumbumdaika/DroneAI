// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/AIController03.h"
#include "BehaviorTree/BehaviorTree.h"

AAIController03::AAIController03()
{
	
}

void AAIController03::OnPossess(APawn* aPawn)
{
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}


