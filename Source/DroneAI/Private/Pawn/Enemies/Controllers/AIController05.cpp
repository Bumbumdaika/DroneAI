// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/AIController05.h"
#include "BehaviorTree/BehaviorTree.h"

// Sets default values
AAIController05::AAIController05()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AAIController05::OnPossess(APawn* aPawn)
{
	if (BehaviorTree)
	{
		if (BehaviorTree)
		{
			RunBehaviorTree(BehaviorTree);
		}
	}
}

