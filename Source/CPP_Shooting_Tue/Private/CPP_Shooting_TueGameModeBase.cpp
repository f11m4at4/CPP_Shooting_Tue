// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_Shooting_TueGameModeBase.h"
#include <Components/BoxComponent.h>
#include "CPP_Shooting_Tue.h"


ACPP_Shooting_TueGameModeBase::ACPP_Shooting_TueGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
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

		currentTime = 0;
	}
}

// ui 띄우거나... 
void ACPP_Shooting_TueGameModeBase::Playing()
{

}

void ACPP_Shooting_TueGameModeBase::Gameover()
{

}
