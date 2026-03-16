// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/EnemyPawn.h"
#include "DronePawn.generated.h"

/**
 * 
 */
UCLASS()
class DRONEAI_API ADronePawn : public AEnemyPawn
{
	GENERATED_BODY()
	
public:
	ADronePawn();
	
protected:
	
	virtual void BeginPlay() override;
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	float IdleRadius = 1000.f;
	//float - радиус случайного патруля
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	float AcceptanceRadius = 100.f;
	//float - дистанция достижения цели. 
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Drone|AI")
	FVector HomeLocation;
	// FVector — точка, вокруг которой дрон патрулирует
	
public:

	FORCEINLINE FVector GetHomeLocation() const
	{
		return HomeLocation;
	}
	// FORCEINLINE — просим компилятор встроить маленькую функцию напрямую
};
