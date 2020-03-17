// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

class UButton;
class UWidgetSwitcher;
class UWidget;
class UEditableTextBox;

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
  UButton* HostButton;
	
  UPROPERTY(meta = (BindWidget))
  UButton* JoinButton;

  UPROPERTY(meta = (BindWidget))
  UButton* JoinServerButton;

  UPROPERTY(meta = (BindWidget))
  UButton* CancelButton;

  UPROPERTY(meta = (BindWidget))
  UWidgetSwitcher* MenuSwitcher;

  UPROPERTY(meta = (BindWidget))
  UWidget* JoinMenu;

  UPROPERTY(meta = (BindWidget))
  UWidget* MainMenu;

  UPROPERTY(meta = (BindWidget))
  UEditableTextBox* IPBox;

  IMenuInterface* MenuInterface;

  UFUNCTION()
  void HostServer();

  UFUNCTION()
  void JoinServer();

  UFUNCTION()
  void OpenJoinMenu();

  UFUNCTION()
  void GoBackToMainMenu();

  APlayerController* PlayerController;
};
