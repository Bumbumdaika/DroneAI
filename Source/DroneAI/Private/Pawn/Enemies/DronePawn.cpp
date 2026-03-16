// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/DronePawn.h"


ADronePawn::ADronePawn()
{
}

void ADronePawn::BeginPlay()
{
	Super::BeginPlay();
	
	HomeLocation = GetActorLocation();
	// GetActorLocation() — возвращает мировую позицию актора
}
