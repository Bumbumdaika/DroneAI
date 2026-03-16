// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pawn/Enemies/Interfaces/Interface01.h"
#include "ActorInterface01.generated.h"

class UStaticMeshComponent;

UCLASS()
class DRONEAI_API AActorInterface01 : public AActor, public IInterface01
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorInterface01();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SM")
	UStaticMeshComponent* SM;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact01_Implementation() override;
};
