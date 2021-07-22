// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_Shooting_TueGameModeBase.h"
#include <Components/BoxComponent.h>
#include "CPP_Shooting_Tue.h"
#include <Blueprint/UserWidget.h>
#include <Kismet/GameplayStatics.h>


ACPP_Shooting_TueGameModeBase::ACPP_Shooting_TueGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_Shooting_TueGameModeBase::BeginPlay()
{
	Super::BeginPlay();

}

void ACPP_Shooting_TueGameModeBase::InitGameState()
{
	Super::InitGameState();
	
	// readyui ����
	if (readyUI == nullptr)
	{
		readyUI = CreateWidget<UUserWidget>(GetWorld(), readyUIFactory);
	}

	if (playingUI == nullptr)
	{
		playingUI = CreateWidget<UUserWidget>(GetWorld(), playingUIFactory);
	}
	if (gameoverUI == nullptr)
	{
		gameoverUI = CreateWidget<UUserWidget>(GetWorld(), gameoverUIFactory);
	}

	// readyui ȭ���� ����
	if (readyUI)
	{
		readyUI->AddToViewport();
	}
	// ���¸� ready �������ֱ�
	state = EGameState::Ready;
}

void ACPP_Shooting_TueGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// ���� ���¸� �ֿܼ� ����غ��� 
	//UEnum* enumPtr = FindObject< UEnum >(ANY_PACKAGE, TEXT("EGameState"), true);
	//if (enumPtr)
	//{
	//	// �ֿܼ� ���
	//	PRINTLOG(TEXT("%s"), *enumPtr->GetNameStringByValue((uint8)state));
	//}

	// framework ����
	// �����ۼ�
	switch (state)
	{
	case EGameState::Ready:
		// ��������ȣ -> �Լ�ȣ��
		Ready();
		break;
	case EGameState::Playing: 
		Playing();
		break;
	case EGameState::Gameover:
		Gameover();
		break;
	}
}

// ���ӿ��� ���� �� ó���� �Լ�
void ACPP_Shooting_TueGameModeBase::OnGameoverProcess()
{
	// ���콺Ŀ�� ���̵��� ó��
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	// �����Ͻ�����
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	// ���¸� gameover �� ��ȯ
	state = EGameState::Gameover;
	// gameover UI ����
	gameoverUI->AddToViewport();
}

// ���� �Լ���� ����
// �����ð��� ������ ���¸� Playing ���� ��ȯ�ϰ� �ʹ�.
// �ʿ�Ӽ� : ready ���ð�, ����ð�
void ACPP_Shooting_TueGameModeBase::Ready()
{
	// �����ð��� ������ ���¸� Playing ���� ��ȯ�ϰ� �ʹ�.
	// 1. �ð��� �귯��
	currentTime += GetWorld()->DeltaTimeSeconds;
	// 2. �����ð�(���ð�)�� �����ϱ�
	// 	   ���� ����ð��� ���ð��� �ʰ��Ͽ��ٸ�
	if(currentTime > readyDelayTime)
	{
		// 3. ���¸� Playing ���� ��ȯ�ϰ� �ʹ�.
		state = EGameState::Playing;

		// readyui �����ϱ�
		readyUI->RemoveFromViewport();
		
		playingUI->AddToViewport();

		currentTime = 0;
	}
}

// ui ���ų�... 
// �����ð��� ������ playing ui �Ⱥ��̰� ����
// �ʿ�Ӽ� : �����ð�(���ð�)
void ACPP_Shooting_TueGameModeBase::Playing()
{
	// �����ð��� ������ playing ui �Ⱥ��̰� ����
	// 1. �ð��� �귶���ϱ�
	currentTime += GetWorld()->DeltaTimeSeconds;
	// playing ui �� ȭ�鿡 ���̰� 
	// 2. �����ð��� �����ϱ�
	if (playingUI->IsInViewport() && currentTime > playingUITime)
	{
		// 3. plyaingui �Ⱥ��̰� �ϰ�ʹ�.
		playingUI->RemoveFromViewport();
		currentTime = 0;
	}
}

void ACPP_Shooting_TueGameModeBase::Gameover()
{

}
