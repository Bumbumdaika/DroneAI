// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController02.generated.h"

/**
 * 
 */

class UBehaviorTree;
UCLASS()
class DRONEAI_API AAIController02 : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIController02();
	
protected:
	virtual void OnPossess(APawn* Pawn) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;
};
