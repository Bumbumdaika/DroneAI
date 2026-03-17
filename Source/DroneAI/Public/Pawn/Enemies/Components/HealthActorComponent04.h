// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthActorComponent04.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged04, float, NewHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONEAI_API UHealthActorComponent04 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthActorComponent04();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged04 OnHealthChanged04;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthActorComponent03")
	float MaxHealth = 100.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HealthActorComponent03")
	float CurrentHealth;
	
	UFUNCTION()
	void ApplyDamage(float Damage);
};
