// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ActorInterface02.h"


// Sets default values
AActorInterface02::AActorInterface02()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SM=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));
	SM->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AActorInterface02::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorInterface02::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorInterface02::Interract02_Implementation()
{

}

