// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSPlaygroundHUD.generated.h"

UCLASS()
class AFPSPlaygroundHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFPSPlaygroundHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

