// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ActorInterface01.h"
#include "Components/StaticMeshComponent.h"
#include "Pawn/Enemies/Components/HealthActorComponent02.h"

// Sets default values
AActorInterface01::AActorInterface01()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM"));
	SM->SetupAttachment(RootComponent);
	
	HealthComponent02 = CreateDefaultSubobject<UHealthActorComponent02>(TEXT("Health Component02"));
	
}

// Called when the game starts or when spawned
void AActorInterface01::BeginPlay()
{
	Super::BeginPlay();
	
	if (HealthComponent02)
	{
		HealthComponent02->OnHealthChanged02.AddDynamic(this, &AActorInterface01::HandleHealthChanged);
	}
}

void AActorInterface01::HandleHealthChanged(float NewHealth)
{
	UE_LOG(LogTemp, Warning, TEXT("Health changed: %f"), NewHealth);
}

// Called every frame
void AActorInterface01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorInterface01::Interact01_Implementation()
{

}

