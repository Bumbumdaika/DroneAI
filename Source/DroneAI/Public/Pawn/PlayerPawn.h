// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn/PawnBase.h"
#include "PlayerPawn.generated.h"


class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


/**
 * 
 */
UCLASS()
class DRONEAI_API APlayerPawn : public APawnBase
{
	GENERATED_BODY()
	
public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	// TObjectPtr<USpringArmComponent> — держатель камеры на расстоянии от Pawn

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> CameraComponent;
	// TObjectPtr<UCameraComponent> — камера игрока

protected:                              

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	// TObjectPtr<UInputMappingContext> — набор правил привязки ввода
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	// TObjectPtr<UInputAction> — действие движения вперед/вправо
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;
	// TObjectPtr<UInputAction> — действие поворота камеры мышью
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveUpAction;
	// TObjectPtr<UInputAction> — действие движения вверх/вниз

protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void MoveuUp(const FInputActionValue& Value);
	
};
