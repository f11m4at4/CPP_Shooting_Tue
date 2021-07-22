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
	
	// readyui 생성
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

	// readyui 화면의 띄우기
	if (readyUI)
	{
		readyUI->AddToViewport();
	}
	// 상태를 ready 설정해주기
	state = EGameState::Ready;
}

void ACPP_Shooting_TueGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// 현재 상태를 콘솔에 출력해보자 
	//UEnum* enumPtr = FindObject< UEnum >(ANY_PACKAGE, TEXT("EGameState"), true);
	//if (enumPtr)
	//{
	//	// 콘솔에 출력
	//	PRINTLOG(TEXT("%s"), *enumPtr->GetNameStringByValue((uint8)state));
	//}

	// framework 설계
	// 목차작성
	switch (state)
	{
	case EGameState::Ready:
		// 페이지번호 -> 함수호출
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

// 게임오버 됐을 때 처리할 함수
void ACPP_Shooting_TueGameModeBase::OnGameoverProcess()
{
	// 마우스커서 보이도록 처리
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	// 게임일시정지
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	// 상태를 gameover 로 전환
	state = EGameState::Gameover;
	// gameover UI 띄우기
	gameoverUI->AddToViewport();
}

// 본문 함수들로 구성
// 일정시간이 지나면 상태를 Playing 으로 전환하고 싶다.
// 필요속성 : ready 대기시간, 경과시간
void ACPP_Shooting_TueGameModeBase::Ready()
{
	// 일정시간이 지나면 상태를 Playing 으로 전환하고 싶다.
	// 1. 시간이 흘러서
	currentTime += GetWorld()->DeltaTimeSeconds;
	// 2. 일정시간(대기시간)이 됐으니까
	// 	   만약 경과시간이 대기시간을 초과하였다면
	if(currentTime > readyDelayTime)
	{
		// 3. 상태를 Playing 으로 전환하고 싶다.
		state = EGameState::Playing;

		// readyui 제거하기
		readyUI->RemoveFromViewport();
		
		playingUI->AddToViewport();

		currentTime = 0;
	}
}

// ui 띄우거나... 
// 일정시간이 지나면 playing ui 안보이게 하자
// 필요속성 : 일정시간(대기시간)
void ACPP_Shooting_TueGameModeBase::Playing()
{
	// 일정시간이 지나면 playing ui 안보이게 하자
	// 1. 시간이 흘렀으니까
	currentTime += GetWorld()->DeltaTimeSeconds;
	// playing ui 가 화면에 보이고 
	// 2. 일정시간이 됐으니까
	if (playingUI->IsInViewport() && currentTime > playingUITime)
	{
		// 3. plyaingui 안보이게 하고싶다.
		playingUI->RemoveFromViewport();
		currentTime = 0;
	}
}

void ACPP_Shooting_TueGameModeBase::Gameover()
{

}
