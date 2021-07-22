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

	virtual void BeginPlay() override;

	virtual void InitGameState() override;

	virtual void Tick( float DeltaSeconds ) override;

	// ���ӿ��� ���� �� ó���� �Լ�
	void OnGameoverProcess();


	UPROPERTY(EditAnywhere, Category="FSM", BlueprintReadWrite)
	EGameState state = EGameState::Ready;

	// �ʿ�Ӽ� : ready ���ð�, ����ð�
	UPROPERTY(EditAnywhere, Category="FSM")
	float readyDelayTime = 2;

	UPROPERTY()
	float currentTime = 0;


	// ReadyUI ����
	UPROPERTY(EditDefaultsOnly, Category=UI)
	TSubclassOf<class UUserWidget> readyUIFactory;

	// readyui �ν��Ͻ� ĳ��
	UPROPERTY()
	class UUserWidget* readyUI;

	// PlayingUI ����
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUserWidget> playingUIFactory;

	// PlayingUI �ν��Ͻ� ĳ��
	UPROPERTY()
	class UUserWidget* playingUI;

	// gameoverUI ����
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUserWidget> gameoverUIFactory;

	// gameoverUI �ν��Ͻ� ĳ��
	UPROPERTY()
	class UUserWidget* gameoverUI;

	// �ʿ�Ӽ� : �����ð�(���ð�)
	UPROPERTY(EditDefaultsOnly, Category=UI)
	float playingUITime = 1;

private:
	void Gameover();
	void Playing();
	void Ready();
};
