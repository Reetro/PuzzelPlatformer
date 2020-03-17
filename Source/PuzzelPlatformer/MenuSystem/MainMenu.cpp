// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

void UMainMenu::SetMenuInterface(IMenuInterface* Interface)
{
  this->MenuInterface = Interface;
}

void UMainMenu::Setup()
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

void UMainMenu::TearDown()
{
  this->bIsFocusable = false;

  this->RemoveFromViewport();

  FInputModeGameOnly InputData;

  PlayerController->SetInputMode(InputData);

  PlayerController->bShowMouseCursor = false;
}

bool UMainMenu::Initialize()
{
  bool Success = Super::Initialize();

  if (!Success) return false;

  if (!ensure(HostButton != nullptr)) return false;
  HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

  if (!ensure(JoinButton != nullptr)) return false;
  JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

  if (!ensure(CancelButton != nullptr)) return false;
  CancelButton->OnClicked.AddDynamic(this, &UMainMenu::GoBackToMainMenu);

  return true;
}

void UMainMenu::HostServer()
{
  if (MenuInterface)
  {
    MenuInterface->Host();
  }
}

void UMainMenu::OpenJoinMenu()
{
  if (!ensure(MenuSwitcher != nullptr)) { return; }
  if (!ensure(JoinMenu != nullptr)) { return; }

  MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::GoBackToMainMenu()
{
  if (!ensure(MenuSwitcher != nullptr)) { return; }
  if (!ensure(MainMenu != nullptr)) { return; }

  MenuSwitcher->SetActiveWidget(MainMenu);
}
