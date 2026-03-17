// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pawn/Enemies/Interfaces/Interface02.h"
#include "ActorInterface02.generated.h"

class UStaticMeshComponent;
class UHealthActorComponent03;

UCLASS()
class DRONEAI_API AActorInterface02 : public AActor, public IInterface02
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AActorInterface02();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SM")
	UStaticMeshComponent* SM;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HealthActorComponent03")
	UHealthActorComponent03* HealthActorComponent03;

public:
	UFUNCTION()
	void HandleChangedHealth(float NewHealth);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interract02_Implementation() override;
	
};
