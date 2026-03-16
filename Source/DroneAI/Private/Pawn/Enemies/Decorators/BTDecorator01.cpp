// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Decorators/BTDecorator01.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator01::UBTDecorator01()
{
	NodeName = "BTDecorator01";
}

bool UBTDecorator01::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	
	if (!BlackboardComponent)
	{
		return false;
	}
	
	return true;
}

