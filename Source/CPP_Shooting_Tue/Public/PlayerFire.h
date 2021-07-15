// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerFire.generated.h"

// ����ڰ� �߻��ư�� ������ �Ѿ��� �߻��ϰ� �ʹ�.
// �ʿ�Ӽ� : �ѱ�, �Ѿ˰���

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

	// ����ڰ� �߻� ��ư�� ������ �� ȣ��� �Լ�
	void Fire();

	// �ʿ�Ӽ� : �ѱ�, �Ѿ˰���
	UPROPERTY()
	class UArrowComponent* firePosition;

	UPROPERTY(EditDefaultsOnly, Category="Bullet Factory")
	TSubclassOf<class ABullet> bulletFactory;

	UPROPERTY()
	class AShootPlayer* me;
	
	// �Ѿ˻���
	UPROPERTY(EditDefaultsOnly, Category="Bullet Sound")
	class USoundBase* bulletSound;
};
