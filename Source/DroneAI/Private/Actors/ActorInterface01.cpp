// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ActorInterface01.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AActorInterface01::AActorInterface01()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM"));
	SM->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AActorInterface01::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorInterface01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorInterface01::Interact01_Implementation()
{
	
}

