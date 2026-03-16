// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Decorators/BTDecorator05.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UBTDecorator05::CalculateRawConditionValue(UBehaviorTreeComponent& ownerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackboardComponent= ownerComp.GetBlackboardComponent();
	
	if (!BlackboardComponent)
	{
		return false;
	}
	
	return true;
}



