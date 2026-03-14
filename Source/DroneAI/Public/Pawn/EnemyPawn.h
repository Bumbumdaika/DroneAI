// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/PawnBase.h"
#include "EnemyPawn.generated.h"


/**
 * 
 */
class AActor;
class UHealthComponent;

UCLASS()
class DRONEAI_API AEnemyPawn : public APawnBase
{
	GENERATED_BODY()

public:
	AEnemyPawn();

protected:
	virtual void BeginPlay() override;

public:
	/*
	Returns true if this enemy currently has a valid target
	Возвращает true, если у врага сейчас есть цель
	*/
	UFUNCTION(BlueprintCallable, Category = "Enemy")
	bool HasTarget() const;

	/*
	Assigns a new target actor
	Назначает новую цель врагу
	*/
	UFUNCTION(BlueprintCallable, Category = "Enemy")
	virtual void SetTarget(AActor* NewTarget);

	/*
	Clears current target
	Очищает текущую цель
	*/
	UFUNCTION(BlueprintCallable, Category ="Enemy")
	virtual void ClearTarget();

	/*
	Returns current target actor
	Возвращает текущую цель
	*/
	UFUNCTION(BlueprintCallable, Category ="Enemy")
	AActor* GetTarget() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Enemy | AI")
	float DetectionRadius = 1500.0f;
	// float — дистанция, на которой враг замечает цель

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy | AI")
	float LoseTargetRadius = 2000.0f;
	// float — дистанция, после которой враг теряет цель
};
