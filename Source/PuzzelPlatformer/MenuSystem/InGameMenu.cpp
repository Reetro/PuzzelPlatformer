// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
  bool Success = Super::Initialize();

  if(!Success) return false;

  if (!ensure(CancelButton != nullptr)) return false;
  CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::TearDown);

  if (!ensure(QuitButton != nullptr)) return false;
  QuitButton->OnClicked.AddDynamic(this, &UInGameMenu::LeaveServer);

  return true;
}

void UInGameMenu::LeaveServer()
{
  if (MenuInterface)
  {
    MenuInterface->LeaveGame();
  }
}
