// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


/*
Delegate вызывается при получении урона
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTaken, float, Damage);

/*
Delegate вызывается при смерти
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONEAI_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*
	Наносит урон
	*/
	UFUNCTION(BlueprintCallable, Category = "Health")
	void ApplyDamage(float Damage);
	
	/*
	Лечит
	*/
	UFUNCTION(BlueprintCallable, Category="Health")
	void Heal(float Amount);
	
	/*
	Проверка на смерть
	*/
	UFUNCTION(BlueprintCallable, Category="Health")
	bool IsDead() const;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth = 100.f;
	// float — максимальное здоровье актора
	
		
protected:
	
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Heath")
	float CurrentHealth;
	// float - текущее здоровье, реплицируется клиентами
	
	UFUNCTION()
	void OnRep_CurrentHealth();
	// OnRep_CurrentHealth() — вызывается на клиентах при изменении CurrentHealth

public: 
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDamageTaken OnDamageTaken;
	// FOnDamageTaken — multicast delegate, уведомляет о получении урона

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDeath OnDeath;
	// FOnDeath — multicast delegate, уведомляет о смерти
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	// GetLifetimeReplicatedProps(...) — регистрирует переменные для сетевой репликации

	
};
