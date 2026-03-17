// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pawn/Enemies/Interfaces/Interface06.h"
#include "ActorInterface06.generated.h"


class UStaticMeshComponent;

UCLASS()
class DRONEAI_API AActorInterface06 : public AActor, public IInterface06
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorInterface06();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "StaticMesh")
	TObjectPtr<UStaticMeshComponent> StaticMesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interract06_Implementation() override;
};
