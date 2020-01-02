// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZELPLATFORMER_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:

  AMovingPlatform();

  UPROPERTY(EditAnywhere)
  float MovementSpeed;

protected:

  virtual void Tick(float DeltaSeconds) override;
	
};
