// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPP_Shooting_Tue.h"
#include "GameFramework/Pawn.h"
#include "ShootPlayer.generated.h"

UCLASS()
class CPP_SHOOTING_TUE_API AShootPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShootPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//PlayerMove 컴포넌트 추가
	UPROPERTY(VisibleAnywhere, Category="Component")
	class UPlayerMove* playerMove;
};
