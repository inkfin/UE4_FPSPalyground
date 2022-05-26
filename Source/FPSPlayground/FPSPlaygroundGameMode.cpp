// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSPlaygroundGameMode.h"
#include "FPSPlaygroundHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSPlaygroundGameMode::AFPSPlaygroundGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSPlaygroundHUD::StaticClass();
}
