// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Enemy.h"

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
	// 일정시간에 한번씩 적을 만들고 싶다.
	// 1. 시간이 흘렀으니까
	currentTime += DeltaTime;
	// 2. 생성시간이 됐으니까
	// -> 만약 경과시간이 생성시간을 초과하였다면
	if(currentTime > createTime)
	{
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		// 3. 적을 만들고 싶다.
		auto enemy = GetWorld()->SpawnActor<AEnemy>(enemyFactory, GetTransform(), param);
		// 4. 배치하고 싶다.
		if (enemy)
		{
			enemy->SetActorLocation(GetActorLocation());
			enemy->SetActorRotation(GetActorRotation());
		}
		currentTime = 0;
	}
}

