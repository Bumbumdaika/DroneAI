// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Decorators/BTDecorator04.h"
#include "BehaviorTree/BlackBoardComponent.h"

bool UBTDecorator04::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	
	if (!Blackboard)
	{
		
	}
	return true;
}


