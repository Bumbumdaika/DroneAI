// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/PawnBase.h"
#include "EnemyPawn.generated.h"

/**
 * 
 */
class AActor;

UCLASS()
class DRONEAI_API AEnemyPawn : public APawnBase
{
	GENERATED_BODY()
	
public:
	AEnemyPawn();
	
protected:
	virtual void BeginPlay() override;
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	float DetectionRadius = 1500.f;
	// float — дистанция обнаружения цели
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	float LoseTargetRadius = 2000.f;
	// float — дистанция потери цели
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category ="AI")
	TObjectPtr<AActor> TargetActor;
	
	// TObjectPtr<AActor> — текущая цель врага
	
	
};
