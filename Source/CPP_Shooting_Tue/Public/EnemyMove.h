// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyMove.generated.h"


// 아래로 계속 이동하고 싶다.
// 필요속성 : 이동속도

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_SHOOTING_TUE_API UEnemyMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// 필요속성 : 이동속도
	UPROPERTY(EditAnywhere, Category="Setting")
	float speed = 500;

	UPROPERTY()
	class AEnemy* me;

	// 따라다닐 타겟
	UPROPERTY()
	class AActor* target;

	FVector v;
};
