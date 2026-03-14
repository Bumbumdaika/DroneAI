// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Components/HealthComponent.h"

#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// PrimaryComponentTick — отключаем тик, потому что компоненту он не нужен

	// ...
	SetIsReplicatedByDefault(true);
	// SetIsReplicatedByDefault(true) — включает репликацию компонента
	
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CurrentHealth = MaxHealth;
	// CurrentHealth = MaxHealth — при старте выставляем полное здоровье
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::ApplyDamage(float Damage)
{
	if (Damage<=0.0f)
	{
		return;
	}
	
	if (IsDead())
	{
		return;
	}
	
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
	// FMath::Clamp — ограничивает значение в диапазоне
	
	OnDamageTaken.Broadcast(Damage);
	// Broadcast — вызывает delegate у всех подписчиков
	
	if (CurrentHealth<=0.0f)
	{
		OnDeath.Broadcast();
	}
}

void UHealthComponent::Heal(float Amount)
{
	if (Amount<=0.0f)
	{
		return;
	}
	if (IsDead())
	{
		return;
	}
	
	CurrentHealth = FMath::Clamp(CurrentHealth - Amount, 0.0f, MaxHealth);
		
}

bool UHealthComponent::IsDead() const
{
	if (CurrentHealth <= 0.0f)
	{
		return true;
	}
	else
	{
		return false;
	}


}

void UHealthComponent::OnRep_CurrentHealth()
{
	// Эта функция вызывается на клиентах при изменении CurrentHealth
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHealthComponent, CurrentHealth);
	// DOREPLIFETIME — регистрирует переменную для сетевой репликации
}

// Called every frame

