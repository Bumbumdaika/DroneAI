// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Enemies/Controllers/AIController01.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Pawn/EnemyPawn.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"

const FName AAIController01::TargetActorKeyName(TEXT("TargetActor"));

AAIController01::AAIController01()
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerceptionComponent");
	
	
	
	SenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>("SightConfig");
	
	SenseConfig_Sight->SightRadius=1500.f;
	SenseConfig_Sight->LoseSightRadius=2000.f;
	SenseConfig_Sight->PeripheralVisionAngleDegrees = 90.f;
	SenseConfig_Sight->SetMaxAge(5.0f);
	
	SenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	SenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = true;
	SenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = true;
	
	AIPerceptionComponent->ConfigureSense(*SenseConfig_Sight);
	AIPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	
	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(
this,
&AAIController01::OnTargetPerceptionUpdated
);
}

void AAIController01::OnPossess(APawn* aPawn)
{
	
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
	
	if (!AIPerceptionComponent)
	{
		return;
	}
	

	

}

void AAIController01::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	UBlackboardComponent* BB = GetBlackboardComponent();
	if (!BB || !Actor)
	{
		return;
	}

	AEnemyPawn* EnemyPawn = Cast<AEnemyPawn>(GetPawn());
	if (!EnemyPawn)
	{
		return;
	}

	if (Stimulus.WasSuccessfullySensed())
	{
		BB->SetValueAsObject(TEXT("TargetActor"), Actor);
		BB->SetValueAsBool(TEXT("CanSeeTarget"), true);
		BB->SetValueAsVector(TEXT("LastKnownLocation"), Actor->GetActorLocation());

		EnemyPawn->bCanSeeTarget = true;
		EnemyPawn->TargetActor = Actor;
	}
	else
	{
		BB->SetValueAsBool(TEXT("CanSeeTarget"), false);
		BB->SetValueAsVector(TEXT("LastKnownLocation"), Actor->GetActorLocation());

		EnemyPawn->bCanSeeTarget = false;
		EnemyPawn->TargetActor = nullptr;
	}
}


void AAIController01::SetTargetActor(AActor* NewTarget)
{
	if (UBlackboardComponent* BB = GetBlackboardComponent())
	{
		BB->SetValueAsObject(TargetActorKeyName, NewTarget);
		UE_LOG(LogTemp, Warning, TEXT("TargetActor set in Blackboard: %s"), *GetNameSafe(NewTarget));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TargetActor set Failed"));
	}
}

void AAIController01::ClearTargetActor()
{
	if (UBlackboardComponent* BB = GetBlackboardComponent())
	{
		BB->ClearValue(TargetActorKeyName);
	}
}
