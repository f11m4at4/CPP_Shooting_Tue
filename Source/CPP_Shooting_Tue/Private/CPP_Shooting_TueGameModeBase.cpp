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

		currentTime = 0;
	}
}

// ui ���ų�... 
void ACPP_Shooting_TueGameModeBase::Playing()
{

}

void ACPP_Shooting_TueGameModeBase::Gameover()
{

}
