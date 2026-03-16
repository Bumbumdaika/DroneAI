// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface04.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInterface04 : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DRONEAI_API IInterface04
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interract04();
};
