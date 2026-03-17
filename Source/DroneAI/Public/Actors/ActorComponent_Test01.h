// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorComponent_Test01.generated.h"

class UHealthActorComponent01;

UCLASS()
class DRONEAI_API AActorComponent_Test01 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorComponent_Test01();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Health Actor Component")
	TObjectPtr<UHealthActorComponent01> HealthComponent;
	
	UFUNCTION()
	void HandleHealthChanged(float NewHealth);
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
