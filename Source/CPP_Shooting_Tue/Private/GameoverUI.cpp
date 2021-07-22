// Fill out your copyright notice in the Description page of Project Settings.


#include "GameoverUI.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "CPP_Shooting_TueGameModeBase.h"

void UGameoverUI::OnClick_Restart()
{
	// 레벨 다시로드
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("ShootingMap"));
	// gameoverui 제거
	auto gamemode = Cast<ACPP_Shooting_TueGameModeBase>(GetWorld()->GetAuthGameMode());
	if (gamemode)
	{
		gamemode->gameoverUI->RemoveFromViewport();
	}
}

void UGameoverUI::OnClick_Quit()
{
	// 어플종료
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
