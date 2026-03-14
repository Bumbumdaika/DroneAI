// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/EnemyPawn.h"

#include "Pawn/Enemies/Components/HealthComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"

AEnemyPawn::AEnemyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	SetReplicateMovement(true);
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	// CreateDefaultSubobject — создаёт компонент внутри актора
	
	/*
AI Perception component
*/
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	// UAIPerceptionComponent — система сенсоров AI

	/*
	Sight configuration
	*/
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	// UAISenseConfig_Sight — конфигурация зрения AI

	SightConfig->SightRadius = DetectionRadius;
	// SightRadius — дистанция обнаружения

	SightConfig->LoseSightRadius = LoseTargetRadius;
	// LoseSightRadius — дистанция потери цели

	SightConfig->PeripheralVisionAngleDegrees = 90.f;
	// угол обзора

	SightConfig->SetMaxAge(5.0f);
	// сколько секунд хранится информация о цели

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	/*
	Attach sight to perception component
	*/
	PerceptionComponent->ConfigureSense(*SightConfig);

	PerceptionComponent->SetDominantSense(UAISense_Sight::StaticClass());
	// основной сенсор

	/*
	Register callback
	*/
	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(
		this,
		&AEnemyPawn::OnPerceptionUpdated
	);
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

void AEnemyPawn::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (!Actor)
	{
		return;
	}

	if (Stimulus.WasSuccessfullySensed())
	{
		SetTarget(Actor);
	}
	else
	{
		ClearTarget();
	}
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