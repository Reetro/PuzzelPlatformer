// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"


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

  if (!ensure(JoinServerButton != nullptr)) return false;
  JoinServerButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

  return true;
}

void UMainMenu::HostServer()
{
  if (MenuInterface)
  {
    MenuInterface->Host();
  }
}

void UMainMenu::JoinServer()
{
  if (MenuInterface)
  {
    if (!ensure(IPBox != nullptr)) { return; }

    const FString Address = IPBox->GetText().ToString();
    MenuInterface->Join(Address);
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
