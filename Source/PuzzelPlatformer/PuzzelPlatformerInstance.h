// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzelPlatformerInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZELPLATFORMER_API UPuzzelPlatformerInstance : public UGameInstance
{
	GENERATED_BODY()

public:

  virtual void init();

  UFUNCTION(exec)
  void Host();

  UFUNCTION(exec)
  void Join(const FString& Address);
};
