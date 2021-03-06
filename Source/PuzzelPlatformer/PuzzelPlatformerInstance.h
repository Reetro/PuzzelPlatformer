// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzelPlatformerInstance.generated.h"

class UUserWidget;
class UMainMenu;
class UMenuWidget;

/**
 * 
 */
UCLASS()
class PUZZELPLATFORMER_API UPuzzelPlatformerInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:

  UPuzzelPlatformerInstance();

  UFUNCTION(exec)
  virtual void Host() override;

  UFUNCTION(exec)
  virtual void Join(const FString& Address) override;

  UFUNCTION(exec)
  virtual void LeaveGame() override;

  UFUNCTION(exec, BlueprintCallable)
  void LoadGameMenu();

  UFUNCTION(exec, BlueprintCallable)
  void LoadInGameMenu();

private:

  TSubclassOf<UUserWidget> MenuClass;

  TSubclassOf<UUserWidget> InGameMenuClass;

  UMainMenu* Menu;

  UMenuWidget* InGameMenu;
};
