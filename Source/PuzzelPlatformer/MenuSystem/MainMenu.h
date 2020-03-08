// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class PUZZELPLATFORMER_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:

  void SetMenuInterface(IMenuInterface* Interface);

  void Setup();

  void TearDown();

protected:

  virtual bool Initialize() override;

private:

  UPROPERTY(meta = (BindWidget))
  UButton* Host;
	
  UPROPERTY(meta = (BindWidget))
  UButton* Join;

  IMenuInterface* MenuInterface;

  UFUNCTION()
  void HostServer();

  APlayerController* PlayerController;
};
