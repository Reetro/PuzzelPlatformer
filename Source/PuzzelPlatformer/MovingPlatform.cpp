// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
  PrimaryActorTick.bCanEverTick = true;

  SetMobility(EComponentMobility::Movable);

  MovementSpeed = 5.0f;
}

void AMovingPlatform::BeginPlay()
{
  Super::BeginPlay();

  if (HasAuthority())
  {
    SetReplicates(true);
    SetReplicateMovement(true);
  }

  GlobalStartLocation = GetActorLocation();
  GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
  Super::Tick(DeltaSeconds);

  if (HasAuthority())
  {
    FVector Location = GetActorLocation();

    float Journeylength = (GlobalTargetLocation - GlobalStartLocation).Size();
    float JourneyTravelled = (Location - GlobalStartLocation).Size();

    if (JourneyTravelled >= Journeylength)
    {
      FVector Swap = GlobalStartLocation;
      GlobalStartLocation = GlobalTargetLocation;
      GlobalTargetLocation = Swap;
    }

    FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

    Location += MovementSpeed * DeltaSeconds * Direction;

    SetActorLocation(Location);
  }
}
