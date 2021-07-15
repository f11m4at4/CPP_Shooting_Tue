// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

UCLASS()
class CPP_SHOOTING_TUE_API AEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// Box Collision
	UPROPERTY(VisibleAnywhere, Category="Collision")
	class UBoxComponent* collision;
	// StaticMesh
	UPROPERTY(VisibleAnywhere, Category = "BodyMesh")
	class UStaticMeshComponent* bodyMesh;
	// FirePosition
	UPROPERTY(VisibleAnywhere, Category = "FirePosition")
	class UArrowComponent* firePosition;

	//EnemyMove
	UPROPERTY(VisibleAnywhere, Category = "EnemyMove")
	class UEnemyMove* enemyMove;

	UFUNCTION()
	void OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Æø¹ßÈ¿°ú
	UPROPERTY(EditDefaultsOnly, Category="Explosion Factory")
	class UParticleSystem* explosionFactory;

	// Æø¹ß»ç¿îµå
	UPROPERTY(EditDefaultsOnly, Category = "Explosion Sound")
	class USoundBase* explosionSound;
};
