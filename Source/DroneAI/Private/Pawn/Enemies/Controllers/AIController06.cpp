// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/AIController06.h"
#include "BehaviorTree/BehaviorTree.h"

AAIController06::AAIController06()
{
	
}
void AAIController06::OnPossess(APawn* aPawn)
{
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}