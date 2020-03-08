// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzelPlatformerInstance.generated.h"

class UUserWidget;
class UMainMenu;

/**
 * 
 */
UCLASS()
class PUZZELPLATFORMER_API UPuzzelPlatformerInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:

  UPuzzelPlatformerInstance();

  virtual void Init() override;

  UFUNCTION(exec)
  void Host();

  UFUNCTION(exec)
  void Join(const FString& Address);

  UFUNCTION(exec, BlueprintCallable)
  void LoadGameMenu();

private:

  TSubclassOf<UUserWidget> MenuClass;

  UMainMenu* Menu;
};
