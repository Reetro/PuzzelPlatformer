// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
  if (!ensure(TriggerVolume != nullptr)) { return; }
  SetRootComponent(TriggerVolume);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();

  TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnComponentBeginOverlap);
  TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnComponentEndOverlap);
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlatformTrigger::OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
  for (AMovingPlatform* MovingPlatForm : PlatformsToTrigger)
  {
    MovingPlatForm->AddActiveTrigger();
  }
}

void APlatformTrigger::OnComponentEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
  for (AMovingPlatform* MovingPlatForm : PlatformsToTrigger)
  {
    MovingPlatForm->RemoveActiveTrigger();
  }
}
