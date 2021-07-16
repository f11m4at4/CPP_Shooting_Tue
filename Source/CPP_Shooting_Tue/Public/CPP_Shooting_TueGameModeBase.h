// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_Shooting_TueGameModeBase.generated.h"

// ������
// -> Ư���� �������� ���ڷ� �ǹ̸� �ο��Ͽ� ���� ����� �ڷ���
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
