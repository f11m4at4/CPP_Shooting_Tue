// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameoverUI.generated.h"

/**
 * 
 */
UCLASS()
class CPP_SHOOTING_TUE_API UGameoverUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Restart 버튼 이벤트 처리할 함수
	UFUNCTION(BlueprintCallable)
	void OnClick_Restart();
	// Quit 버튼 이벤트 처리할 함수
	UFUNCTION(BlueprintCallable)
	void OnClick_Quit();
};
