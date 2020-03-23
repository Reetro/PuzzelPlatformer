// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "GameFramework/PlayerController.h"

void UMenuWidget::SetMenuInterface(IMenuInterface* Interface)
{
  this->MenuInterface = Interface;
}

void UMenuWidget::Setup()
{
  this->bIsFocusable = true;

  this->AddToViewport(); // Displays the menu on screen

  UWorld* World = GetWorld();
  if (!ensure(World != nullptr)) return;

  // Get Player controller
  PlayerController = World->GetFirstPlayerController();
  if (!ensure(PlayerController != nullptr)) return;

  // Construct Mouse Data
  FInputModeUIOnly InputData;
  InputData.SetWidgetToFocus(this->TakeWidget());
  InputData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
  PlayerController->SetInputMode(InputData);

  // Show mouse
  PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::TearDown()
{
  this->bIsFocusable = false;

  this->RemoveFromViewport();

  FInputModeGameOnly InputData;

  PlayerController->SetInputMode(InputData);

  PlayerController->bShowMouseCursor = false;
}
