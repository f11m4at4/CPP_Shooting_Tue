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

	virtual void BeginPlay() override;

	virtual void InitGameState() override;

	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, Category="FSM", BlueprintReadWrite)
	EGameState state = EGameState::Ready;

	// 필요속성 : ready 대기시간, 경과시간
	UPROPERTY(EditAnywhere, Category="FSM")
	float readyDelayTime = 2;

	UPROPERTY()
	float currentTime = 0;


	// ReadyUI 공장
	UPROPERTY(EditDefaultsOnly, Category=UI)
	TSubclassOf<class UUserWidget> readyUIFactory;

	// readyui 인스턴스 캐싱
	UPROPERTY()
	class UUserWidget* readyUI;

private:
	void Gameover();
	void Playing();
	void Ready();
};
