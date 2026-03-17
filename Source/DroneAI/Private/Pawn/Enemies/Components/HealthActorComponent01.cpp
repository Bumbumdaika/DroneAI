// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Components/HealthActorComponent01.h"


// Sets default values for this component's properties
UHealthActorComponent01::UHealthActorComponent01()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthActorComponent01::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
}

void UHealthActorComponent01::ApplyDamage(float Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
	
	OnHealthChanged01.Broadcast(CurrentHealth);
}



