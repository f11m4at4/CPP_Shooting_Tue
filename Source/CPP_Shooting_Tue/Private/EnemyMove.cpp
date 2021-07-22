// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMove.h"
#include "Enemy.h"
#include <Kismet/GameplayStatics.h>
#include "ShootPlayer.h"
#include "CPP_Shooting_TueGameModeBase.h"

// Sets default values for this component's properties
UEnemyMove::UEnemyMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyMove::BeginPlay()
{
	Super::BeginPlay();

	// 이 컴포넌트를 소유하고 있는 액터를 반환
	me = Cast<AEnemy>(GetOwner());
	
	// 타겟 찾아오기
	// AShootPlayer 설계도로 만들어진 레벨에 있는(인스턴스) 를 찾아 오겠다.
	target = UGameplayStatics::GetActorOfClass(GetWorld(), AShootPlayer::StaticClass());

	// 랜덤으로 숫자 하나 뽑아서 50 이하면 아래로 그렇지 않으면 타겟쪽으로
	// -> 타겟이 죽었으면 그냥 아래로

	int32 ratio = FMath::RandRange(1, 100);

	// 타겟으로 향하는 방향구하기
	v = FVector::DownVector * speed;
	if (target && ratio > 50)
	{
		v = target->GetActorLocation() - me->GetActorLocation();
		v.Normalize();
		v *= speed;
	}
}


// Called every frame
void UEnemyMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto gameMode = Cast<ACPP_Shooting_TueGameModeBase>(GetWorld()->GetAuthGameMode());
	bool isPlaying = gameMode->state != EGameState::Playing;
	// 2. 조건식이 있어야 한다.
	if (isPlaying)
	{
		// 아래 내용은 처리하고 싶지 않다.
		return;
	}

	// 아래로 계속 이동하고 싶다.
	// P = P0 + vt
	
	FVector P = me->GetActorLocation() + v * DeltaTime;

	me->SetActorLocation(P, true);
}

