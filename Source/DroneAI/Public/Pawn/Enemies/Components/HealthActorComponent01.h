// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthActorComponent01.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged01, float, NewHealth);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRONEAI_API UHealthActorComponent01 : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthActorComponent01();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(BlueprintAssignable, Category = "HealthActorComponent01")
	FOnHealthChanged01 OnHealthChanged01;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthActorComponent01")
	float MaxHealth = 100.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HealthActorComponent01t")
	float CurrentHealth;
	
	UFUNCTION(BlueprintCallable, Category = "HealthActorComponent01")
	void ApplyDamage(float Damage);

};
