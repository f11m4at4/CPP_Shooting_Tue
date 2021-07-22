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
	// Restart ��ư �̺�Ʈ ó���� �Լ�
	UFUNCTION(BlueprintCallable)
	void OnClick_Restart();
	// Quit ��ư �̺�Ʈ ó���� �Լ�
	UFUNCTION(BlueprintCallable)
	void OnClick_Quit();
};
