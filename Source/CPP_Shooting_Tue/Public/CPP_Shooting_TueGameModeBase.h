// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_Shooting_TueGameModeBase.generated.h"

// 열거형
// -> 특정한 숫자한테 문자로 의미를 부여하여 만든 사용자 자료형
UENUM(BlueprintType)
enum class EGameState : uint8
{
	Ready UMETA(DisplayName = "READY STATE"),
	Playing UMETA(DisplayName = "PLAYING STATE"),
	Gameover UMETA(DisplayName = "GAMEOVER STATE")
};

/**
 * 
 */
UCLASS()
class CPP_SHOOTING_TUE_API ACPP_Shooting_TueGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACPP_Shooting_TueGameModeBase();

	UPROPERTY(EditAnywhere, Category="FSM", BlueprintReadWrite)
	EGameState state = EGameState::Ready;
};
