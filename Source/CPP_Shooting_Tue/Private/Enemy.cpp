// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/ArrowComponent.h>
#include "EnemyMove.h"
#include <Kismet/GameplayStatics.h>
#include "ShootPlayer.h"
#include "CPP_Shooting_TueGameModeBase.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Factory Method
	// Collision 컴포너트 등록
	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	// 루트 컴포넌트로 등록
	RootComponent = collision;
	// Object Type 을 코드로 등록해 보자
	//collision->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	collision->SetCollisionProfileName(TEXT("Enemy"));
	// 충돌이 발생 했을 때 처리할 함수 바인딩하기
	collision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnTriggerEnter);

	// 외관
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(RootComponent);
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	// 총구
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	firePosition->SetupAttachment(RootComponent);

	enemyMove = CreateDefaultSubobject<UEnemyMove>(TEXT("EnemyMove"));

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	// 생명력
	//SetLifeSpan(3);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int Plus(int a, int b)
{
	return a + b;
}
void AEnemy::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 만약 부딪힌 녀석이 Enemy 라면 
	//if(OtherActor->GetName().Contains(TEXT("Enemy")))
	//auto enemy = Cast<AEnemy>(OtherActor);
	//if(enemy)
	//{
	//	// 처리하지 않겠다.
	//	return;
	//}
	 
	// 부딪힌 녀석이 Player 라면 상태를 gameover 로 전환하고 싶다. 
	auto player = Cast<AShootPlayer>(OtherActor);
	if (player)
	{
		auto gameMode = Cast<ACPP_Shooting_TueGameModeBase>(GetWorld()->GetAuthGameMode());
		gameMode->OnGameoverProcess();
	}

	// 폭발효과 재생
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionFactory, GetTransform());

	// 폭발 사운드 재생
	UGameplayStatics::PlaySound2D(GetWorld(), explosionSound);

	// 너도 죽고
	OtherActor->Destroy();
	// 나도 죽자
	Destroy();
}

