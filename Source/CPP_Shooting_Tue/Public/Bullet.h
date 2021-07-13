// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

// ��� ���� �̵��ϰ� �ʹ�.
// �ʿ�Ӽ� : �̵��ӵ�

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
	
	// �ʿ�Ӽ� : �̵��ӵ�
	UPROPERTY(EditAnywhere, Category="Setting")
	float speed = 1000;
};
