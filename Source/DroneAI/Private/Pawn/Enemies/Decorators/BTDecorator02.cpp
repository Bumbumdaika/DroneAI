// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Decorators/BTDecorator02.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UBTDecorator02::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	
	if (!BlackboardComponent)
	{
		return false;
	}
	return true;
}
