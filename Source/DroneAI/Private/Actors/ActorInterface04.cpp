// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ActorInterface04.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AActorInterface04::AActorInterface04()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AActorInterface04::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorInterface04::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorInterface04::Interract04_Implementation()
{
	
}

