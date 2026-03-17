// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Components/HealthActorComponent02.h"


// Sets default values for this component's properties
UHealthActorComponent02::UHealthActorComponent02()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthActorComponent02::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	CurrentHealth = MaxHealth;
}




// Called every frame
void UHealthActorComponent02::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthActorComponent02::ApplyDamage(float Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
	
	OnHealthChanged02.Broadcast(CurrentHealth);
}

