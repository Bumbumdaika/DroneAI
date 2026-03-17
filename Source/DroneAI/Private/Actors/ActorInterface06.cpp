// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ActorInterface06.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AActorInterface06::AActorInterface06()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	
	StaticMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AActorInterface06::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorInterface06::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorInterface06::Interract06_Implementation()
{
	
}

