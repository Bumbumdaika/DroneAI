// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthActorComponent03.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged03, float, NewHealth);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRONEAI_API UHealthActorComponent03 : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthActorComponent03();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(BlueprintAssignable, Category = "HealthActorComponent03")
	FOnHealthChanged03 OnHealthChanged03;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthActorComponent03")
	float MaxHealth = 100.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HealthActorComponent03")
	float CurrentHealth;

	UFUNCTION(BlueprintCallable, Category = "HealthActorComponent03")
	void ApplyDamage(float Damage);
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
