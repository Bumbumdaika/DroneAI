// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Decorators/BTDecorator03.h"
#include "BehaviorTree/BlackboardComponent.h"


bool UBTDecorator03::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	
	if (!Blackboard)
	{
		return false;;
	}
	return true;
	
}


