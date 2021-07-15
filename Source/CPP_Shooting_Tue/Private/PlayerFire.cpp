// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFire.h"
#include "Bullet.h"
#include <Components/ArrowComponent.h>
#include "ShootPlayer.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UPlayerFire::UPlayerFire()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerFire::BeginPlay()
{
	Super::BeginPlay();

	// 총구 가져오기
	// 1. ShootPlayer 가 있어야한다.
	// 이 컴포넌트를 소유하고 있는 액터를 반환
	me = Cast<AShootPlayer>(GetOwner());

	// 2. ShootPlayer 객체에 있는 총구를 가져오고 싶다.
	auto fp = me->GetDefaultSubobjectByName(TEXT("FirePosition"));
	// 3. 총구를 내 속성변수인 firePosition 에 할당하고 싶다.
	firePosition = Cast<UArrowComponent>(fp);
}


// Called every frame
void UPlayerFire::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerFire::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// 사용자의 입력과 처리할 함수를 Binding
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UPlayerFire::Fire);
}

// 사용자가 발사 버튼을 눌렀을 때 호출될 함수
void UPlayerFire::Fire()
{
	// 총알을 발사하고 싶다.
	// 1. 총알이 필요
	auto bullet = GetWorld()->SpawnActor<ABullet>(bulletFactory);
	// 2. 총알을 배치
	if (bullet)
	{
		bullet->SetActorLocation(firePosition->GetComponentLocation());
		bullet->SetActorRotation(firePosition->GetComponentRotation());
	}

	// 총알 사운드 재생
	UGameplayStatics::PlaySound2D(GetWorld(), bulletSound);
}

