// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthActorComponent02.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged02, float, NewHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONEAI_API UHealthActorComponent02 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthActorComponent02();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable, Category = "HealthActorComponent02")
	FOnHealthChanged02 OnHealthChanged02;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthActorComponent02")
	float MaxHealth;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthActorComponent02")
	float CurrentHealth;
	
	UFUNCTION(BlueprintCallable, Category = "HealthActorComponent02")
	void ApplyDamage(float Damage);
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
