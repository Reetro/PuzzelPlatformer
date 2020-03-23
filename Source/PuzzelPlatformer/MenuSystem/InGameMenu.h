// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "InGameMenu.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class PUZZELPLATFORMER_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()
	
private:

  UPROPERTY(meta = (BindWidget))
  UButton* CancelButton;

  UPROPERTY(meta = (BindWidget))
  UButton* QuitButton;

  UFUNCTION()
  void LeaveServer();

protected:

  virtual bool Initialize() override;
};
