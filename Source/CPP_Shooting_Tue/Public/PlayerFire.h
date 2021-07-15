// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerFire.generated.h"

// 사용자가 발사버튼을 누르면 총알을 발사하고 싶다.
// 필요속성 : 총구, 총알공장

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_SHOOTING_TUE_API UPlayerFire : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerFire();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// 사용자가 발사 버튼을 눌렀을 때 호출될 함수
	void Fire();

	// 필요속성 : 총구, 총알공장
	UPROPERTY()
	class UArrowComponent* firePosition;

	UPROPERTY(EditDefaultsOnly, Category="Bullet Factory")
	TSubclassOf<class ABullet> bulletFactory;

	UPROPERTY()
	class AShootPlayer* me;
	
	// 총알사운드
	UPROPERTY(EditDefaultsOnly, Category="Bullet Sound")
	class USoundBase* bulletSound;
};
