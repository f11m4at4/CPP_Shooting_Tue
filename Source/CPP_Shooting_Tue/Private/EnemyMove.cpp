// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMove.h"
#include "Enemy.h"
#include <Kismet/GameplayStatics.h>
#include "ShootPlayer.h"

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
}


// Called every frame
void UEnemyMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 아래로 계속 이동하고 싶다.
	// P = P0 + vt
	FVector v = FVector::DownVector * speed;
	if(target)
	{
		v = target->GetActorLocation() - me->GetActorLocation();
		v.Normalize();
		v *= speed;
	}
	FVector P = me->GetActorLocation() + v * DeltaTime;

	me->SetActorLocation(P);
}

