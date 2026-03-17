// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ActorComponent_Test01.h"
#include "Pawn/Enemies/Components/HealthActorComponent01.h"

// Sets default values
AActorComponent_Test01::AActorComponent_Test01()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HealthComponent = CreateDefaultSubobject<UHealthActorComponent01>(TEXT("HealthComponent"));
	
}

// Called when the game starts or when spawned
void AActorComponent_Test01::BeginPlay()
{
	Super::BeginPlay();

	if (HealthComponent)
	{
		HealthComponent->OnHealthChanged01.AddDynamic(this, &AActorComponent_Test01::HandleHealthChanged);
	}
	
}

void AActorComponent_Test01::HandleHealthChanged(float NewHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("Health changed: %f"), NewHealth);
}

// Called every frame
void AActorComponent_Test01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

