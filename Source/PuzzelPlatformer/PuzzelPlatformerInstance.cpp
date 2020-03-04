// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzelPlatformerInstance.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
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
  UEngine* Engine = GetEngine();
  if (!ensure(Engine != nullptr)) { return; }

  Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));

  UWorld* World = GetWorld();
  if (!ensure(World != nullptr)) { return; }

  World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzelPlatformerInstance::Join(const FString& Address)
{
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

  UUserWidget* Menu = CreateWidget<UUserWidget>(this, MenuClass);
  if (!ensure(Menu != nullptr)) return;

  Menu->AddToViewport();
}
