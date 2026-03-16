// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController03.generated.h"

/**
 * 
 */

class UBehaviorTree;

UCLASS()
class DRONEAI_API AAIController03 : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIController03();
	
protected:
	
	virtual void OnPossess(APawn* aPawn) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
};
