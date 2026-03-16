// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pawn/Enemies/Interfaces/Interface04.h"
#include "ActorInterface04.generated.h"

class UStaticMeshComponent;

UCLASS()
class DRONEAI_API AActorInterface04 : public AActor, public IInterface04
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorInterface04();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "StaticMesh")
	UStaticMeshComponent* StaticMesh;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interract04_Implementation() override;
};
