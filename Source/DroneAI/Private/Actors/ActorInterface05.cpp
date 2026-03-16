// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ActorInterface05.h"


// Sets default values
AActorInterface05::AActorInterface05()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AActorInterface05::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorInterface05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorInterface05::Interract05_Implementation()
{
	
}

