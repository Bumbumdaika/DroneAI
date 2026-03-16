// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/AIController05.h"


// Sets default values
AAIController05::AAIController05()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAIController05::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIController05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

