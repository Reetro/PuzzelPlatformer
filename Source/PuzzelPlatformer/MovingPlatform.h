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

  virtual void BeginPlay() override;

  UPROPERTY(EditAnywhere)
  float MovementSpeed;

  UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
  FVector TargetLocation;

  void AddActiveTrigger();
  void RemoveActiveTrigger();

protected:

  virtual void Tick(float DeltaSeconds) override;

private:

  FVector GlobalTargetLocation;

  FVector GlobalStartLocation;

  UPROPERTY(EditAnywhere, Category = "Platform Settings")
  int32 ActiveTriggers = 1;
};
