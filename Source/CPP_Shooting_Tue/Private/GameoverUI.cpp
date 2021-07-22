// Fill out your copyright notice in the Description page of Project Settings.


#include "GameoverUI.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "CPP_Shooting_TueGameModeBase.h"

void UGameoverUI::OnClick_Restart()
{
	// ���� �ٽ÷ε�
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("ShootingMap"));
	// gameoverui ����
	auto gamemode = Cast<ACPP_Shooting_TueGameModeBase>(GetWorld()->GetAuthGameMode());
	if (gamemode)
	{
		gamemode->gameoverUI->RemoveFromViewport();
	}
}

void UGameoverUI::OnClick_Quit()
{
	// ��������
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
