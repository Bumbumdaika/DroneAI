// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController04.generated.h"

/**
 * 
 */
class UBehaviorTree;

UCLASS()
class DRONEAI_API AAIController04 : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIController04();
	
protected:
	virtual void OnPossess(APawn* Pawn) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
	
};
