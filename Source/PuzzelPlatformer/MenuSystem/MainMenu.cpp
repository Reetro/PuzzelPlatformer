// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"

void UMainMenu::SetMenuInterface(IMenuInterface* Interface)
{
  this->MenuInterface = Interface;
}

bool UMainMenu::Initialize()
{
  bool Success = Super::Initialize();

  if (!Success) return false;

  if (!ensure(Host != nullptr)) return false;
  Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);


  return true;
}

void UMainMenu::HostServer()
{
  if (MenuInterface)
  {
    MenuInterface->Host();
  }
}
