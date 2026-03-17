// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController01.generated.h"

/**
 * 
 */

class UBehaviorTree;
class UAIPerceptionComponent;
//class UAISense_Sight;
class UAISenseConfig_Sight;

UCLASS()
class DRONEAI_API AAIController01 : public AAIController
{
	GENERATED_BODY()
	
public:
	static const FName TargetActorKeyName;
	AAIController01();
	
protected:
	
	virtual void OnPossess(APawn* aPawn) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UAIPerceptionComponent* AIPerceptionComponent ;
	

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TObjectPtr<UAISenseConfig_Sight> SenseConfig_Sight;
	
	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	
		
	void SetTargetActor(AActor* NewTarget);
	void ClearTargetActor();
};
