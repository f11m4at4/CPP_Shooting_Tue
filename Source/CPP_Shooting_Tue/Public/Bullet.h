// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

// 계속 위로 이동하고 싶다.
// 필요속성 : 이동속도

UCLASS()
class CPP_SHOOTING_TUE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Box Collision
	UPROPERTY(VisibleAnywhere, Category="Collision")
	class UBoxComponent* collision;
	// StaticMesh
	UPROPERTY(VisibleAnywhere, Category = "BodyMesh")
	class UStaticMeshComponent* bodyMesh;
	
	// 필요속성 : 이동속도
	UPROPERTY(EditAnywhere, Category="Setting")
	float speed = 1000;
};
