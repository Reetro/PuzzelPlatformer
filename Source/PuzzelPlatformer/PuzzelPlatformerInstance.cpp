// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzelPlatformerInstance.h"
#include "Engine/Engine.h"
#include "Components/Widget.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuSystem/MainMenu.h"
#include "Blueprint/UserWidget.h"

UPuzzelPlatformerInstance::UPuzzelPlatformerInstance()
{
  ConstructorHelpers::FClassFinder<UUserWidget> MainMenuBPClass(TEXT("/Game/MenuSystem/MainMenu_WBP")); // String needed to find blueprint Game = Content folder
  if (!ensure(MainMenuBPClass.Class != nullptr)) { return; }

  MenuClass = MainMenuBPClass.Class;
}

void UPuzzelPlatformerInstance::Init()
{
  
}

void UPuzzelPlatformerInstance::Host()
{
  if (Menu)
  {
    Menu->TearDown();
  }

  UEngine* Engine = GetEngine();
  if (!ensure(Engine != nullptr)) { return; }

  Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));

  UWorld* World = GetWorld();
  if (!ensure(World != nullptr)) { return; }

  World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzelPlatformerInstance::Join(const FString& Address)
{
  if (Menu)
  {
    Menu->TearDown();
  }

  UEngine* Engine = GetEngine();
  if (!ensure(Engine != nullptr)) { return; }

  Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining: %s"), *Address));

  APlayerController* PlayerController = GetFirstLocalPlayerController(); 
  if (!ensure(PlayerController != nullptr)) { return; }

  PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UPuzzelPlatformerInstance::LoadGameMenu()
{
  if (!ensure(MenuClass != nullptr)) return;

  Menu = CreateWidget<UMainMenu>(this, MenuClass); // Creates the actual menu
  if (!ensure(Menu != nullptr)) return;

  Menu->Setup();

  Menu->SetMenuInterface(this);
}
