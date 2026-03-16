// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pawn/Enemies/Interfaces/Interface05.h"
#include "ActorInterface05.generated.h"

class UStaticMeshComponent;

UCLASS()
class DRONEAI_API AActorInterface05 : public AActor, public IInterface05
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorInterface05();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "StaticMesh")
	UStaticMeshComponent* StaticMesh;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interract05_Implementation() override;
};
