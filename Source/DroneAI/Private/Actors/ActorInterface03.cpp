// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ActorInterface03.h"
#include "Components/StaticMeshComponent.h"
#include "Pawn/Enemies/Components/HealthActorComponent04.h"

// Sets default values
AActorInterface03::AActorInterface03()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent ->SetupAttachment(RootComponent);

	HealthActorComponent04 = CreateDefaultSubobject<UHealthActorComponent04>("HealthActorComponent04");
	
}

// Called when the game starts or when spawned
void AActorInterface03::BeginPlay()
{
	Super::BeginPlay();
	
	if (!HealthActorComponent04)
	{
		HealthActorComponent04->OnHealthChanged04.AddDynamic(this, &AActorInterface03::HadndleHealthChange);
	}
}

// Called every frame
void AActorInterface03::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorInterface03::Interracte03_Implementation()
{
	
}

void AActorInterface03::HadndleHealthChange(float NewHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("Health changed: %f"), NewHealth);
}



