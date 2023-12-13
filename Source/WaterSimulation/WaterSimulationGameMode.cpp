// Copyright Epic Games, Inc. All Rights Reserved.

#include "WaterSimulationGameMode.h"
#include "WaterSimulationCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWaterSimulationGameMode::AWaterSimulationGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
