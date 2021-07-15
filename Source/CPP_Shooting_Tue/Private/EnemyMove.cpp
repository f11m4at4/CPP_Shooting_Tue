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

	// �� ������Ʈ�� �����ϰ� �ִ� ���͸� ��ȯ
	me = Cast<AEnemy>(GetOwner());
	
	// Ÿ�� ã�ƿ���
	// AShootPlayer ���赵�� ������� ������ �ִ�(�ν��Ͻ�) �� ã�� ���ڴ�.
	target = UGameplayStatics::GetActorOfClass(GetWorld(), AShootPlayer::StaticClass());
}


// Called every frame
void UEnemyMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// �Ʒ��� ��� �̵��ϰ� �ʹ�.
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

