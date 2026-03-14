// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/EnemyPawn.h"

#include "Pawn/Enemies/Components/HealthComponent.h"


AEnemyPawn::AEnemyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	SetReplicateMovement(true);
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	// CreateDefaultSubobject — создаёт компонент внутри актора
}

void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();

	if (HealthComponent)
	{
		HealthComponent->OnDeath.AddDynamic(this, &AEnemyPawn::HandleDeath);
		// AddDynamic — подписка на multicast delegate
	}
	
}


bool AEnemyPawn::HasTarget() const
{ 
	return IsValid(TargetActor);
	// IsValid — безопасная проверка UObject
}

void AEnemyPawn::SetTarget(AActor* NewTarget)
{
	TargetActor = NewTarget;
}

void AEnemyPawn::ClearTarget()
{
	TargetActor = nullptr;
}

AActor* AEnemyPawn::GetTarget() const
{
	return TargetActor.Get();
}

void AEnemyPawn::HandleDeath()
{
	OnEnemyDeath();
	// вызываем интерфейс
}

void AEnemyPawn::OnEnemyDeath_Implementation()
{
	Destroy();
	// Destroy — уничтожает актор
}