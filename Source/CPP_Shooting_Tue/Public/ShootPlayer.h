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
	//PlayerMove ÄÄÆ÷³ÍÆ® Ãß°¡
	UPROPERTY(VisibleAnywhere, Category="PlayerMove")
	class UPlayerMove* playerMove;

	UPROPERTY(VisibleAnywhere, Category = "PlayerFire")
	class UPlayerFire* playerFire;

	// ÃÑ±¸
	UPROPERTY(VisibleAnywhere, Category = "FirePosition")
	class UArrowComponent* firePosition;

	// Box Collision
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	class UBoxComponent* collision;
	// StaticMesh
	UPROPERTY(VisibleAnywhere, Category = "BodyMesh")
	class UStaticMeshComponent* bodyMesh;
};
