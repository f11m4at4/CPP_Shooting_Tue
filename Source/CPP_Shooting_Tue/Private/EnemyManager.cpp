// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Enemy.h"
#include "CPP_Shooting_TueGameModeBase.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto gameMode = Cast<ACPP_Shooting_TueGameModeBase>(GetWorld()->GetAuthGameMode());
	bool isPlaying = gameMode->state != EGameState::Playing;
	// 2. ���ǽ��� �־�� �Ѵ�.
	if (isPlaying)
	{
		// �Ʒ� ������ ó���ϰ� ���� �ʴ�.
		return;
	}

	// �����ð��� �ѹ��� ���� ����� �ʹ�.
	// 1. �ð��� �귶���ϱ�
	currentTime += DeltaTime;
	// 2. �����ð��� �����ϱ�
	// -> ���� ����ð��� �����ð��� �ʰ��Ͽ��ٸ�
	if(currentTime > createTime)
	{
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		// 3. ���� ����� �ʹ�.
		auto enemy = GetWorld()->SpawnActor<AEnemy>(enemyFactory, GetTransform(), param);
		// 4. ��ġ�ϰ� �ʹ�.
		if (enemy)
		{
			enemy->SetActorLocation(GetActorLocation());
			enemy->SetActorRotation(GetActorRotation());
		}
		currentTime = 0;
	}
}

