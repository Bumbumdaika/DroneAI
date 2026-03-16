// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/AIController02.h"
#include "BehaviorTree/BehaviorTree.h"

AAIController02::AAIController02()
{
	
}

void AAIController02::OnPossess(APawn* aPawn)
{
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}