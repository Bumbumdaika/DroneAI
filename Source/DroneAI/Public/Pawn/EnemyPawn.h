// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies/Interfaces/CombatInterface.h"
#include "Pawn/PawnBase.h"
#include "EnemyPawn.generated.h"


struct FAIStimulus;
/**
 * 
 */
class AActor;
class UHealthComponent;
class UAIPerceptionComponent;
class UAISenseConfig_Sight;

UCLASS()
class DRONEAI_API AEnemyPawn : public APawnBase, public ICombatInterface
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
	
protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componets")
	TObjectPtr<UHealthComponent> HealthComponent;
	// TObjectPtr<UHealthComponent> — компонент системы здоровья

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<AActor> TargetActor;
	// TObjectPtr<AActor> — текущая цель врага

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UAIPerceptionComponent> PerceptionComponent;
	// основной компонент системы восприятия AI
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UAISenseConfig_Sight> SightConfig;
	// конфигурация зрения AI
	
	/*
	Called when health reaches zero
	Вызывается когда здоровье заканчивается
	*/
	
protected:

	UFUNCTION()
	void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
	// вызывается при обнаружении или потере цели
	UFUNCTION()
	void HandleDeath();
	
public:
	virtual void OnEnemyDeath_Implementation() override;
};
