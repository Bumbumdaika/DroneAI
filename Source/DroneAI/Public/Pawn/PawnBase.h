// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

/*
 * APawnBase
 *
 * Это базовый класс для всех Pawn в проекте.
 * Pawn — это актор, которым может управлять Controller (PlayerController или AIController).
 *
 * В отличие от Character, Pawn не имеет встроенной системы передвижения,
 * поэтому движение нужно реализовывать самостоятельно или через компоненты.
 */

class USphereComponent;
class UStaticMeshComponent;
class UFloatingPawnMovement;

UCLASS()
class DRONEAI_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Конструктор
	APawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/*
	 * Root компонент.
	 * От него наследуются все остальные компоненты.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> CollisionComponent;
	// TObjectPtr<T> — UE5 smart pointer для UObject, который безопасно отслеживается Garbage Collector
	
	/*Visual mesh of the pawn Отвечает только за внешний вид */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	// TObjectPtr<UStaticMeshComponent> — указатель на компонент меша управляемый системой GC Unreal

	/*
	Simple movement component for floating pawns
	Позволяет Pawn двигаться через AddMovementInput
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UFloatingPawnMovement> MovementComponent;
	// TObjectPtr<UFloatingPawnMovement> — компонент отвечающий за базовую летающую физику Pawn

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	

	
};
