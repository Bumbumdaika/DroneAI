// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Components/HealthActorComponent03.h"


// Sets default values for this component's properties
UHealthActorComponent03::UHealthActorComponent03()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthActorComponent03::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CurrentHealth = MaxHealth;
}


void UHealthActorComponent03::ApplyDamage(float Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
	
	OnHealthChanged03.Broadcast(CurrentHealth);
}

// Called every frame
void UHealthActorComponent03::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

