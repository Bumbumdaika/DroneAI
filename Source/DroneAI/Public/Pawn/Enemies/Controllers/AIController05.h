// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController05.generated.h"

class UBehaviorTree;

UCLASS()
class DRONEAI_API AAIController05 : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAIController05();

protected:
	
	void OnPossess(APawn* aPawn) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;

};
