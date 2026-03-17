// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController06.generated.h"

/**
 * 
 */

class UBehaviorTree;

UCLASS()
class DRONEAI_API AAIController06 : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIController06();
	
protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
	
	virtual void OnPossess(APawn* Pawn) override;
	
	
	
	
};
