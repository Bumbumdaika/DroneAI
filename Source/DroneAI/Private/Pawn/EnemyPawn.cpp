// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/EnemyPawn.h"




AEnemyPawn::AEnemyPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();

	
}


bool AEnemyPawn::HasTarget() const
{ 
	return true;
}

void AEnemyPawn::SetTarget(AActor* NewTarget)
{
}

void AEnemyPawn::ClearTarget()
{
}

AActor* AEnemyPawn::GetTarget() const
{
	return nullptr;
}

