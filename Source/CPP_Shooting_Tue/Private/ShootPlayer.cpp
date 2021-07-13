// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayer.h"
#include "PlayerMove.h"
#include "PlayerFire.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/ArrowComponent.h>

// Sets default values
AShootPlayer::AShootPlayer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Factory Method(Function)
	// BoxCollision  컴포넌트 등록
	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	// 루트컴포넌트가 되어야 한다.
	RootComponent = collision;
	collision->SetCollisionProfileName(TEXT("BlockAll"));

	// bodymesh 컴포넌트 등록
	// Root 의 자식으로 등록
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(RootComponent);
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 동적으로 파일(애셋) 을 로드하여 할당하기
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// 데이터로드가 성공했다면
	if (tempMesh.Succeeded())
	{
		// bodyMesh 에 할당해주기
		bodyMesh->SetStaticMesh(tempMesh.Object);
	}

	// 총구 컴포넌트 만들어서 붙이기
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	firePosition->SetupAttachment(RootComponent);

	// Actor 를 이루는 컴포넌트를 붙이도록 한다.
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerFire = CreateDefaultSubobject<UPlayerFire>(TEXT("PlayerFire"));
	
}

// Called when the game starts or when spawned
void AShootPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	//CALLINFO();
	PRINTLOG(TEXT("%s %d"), TEXT("Hello World"), 100);
}

// Called every frame
void AShootPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShootPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// PlayerMove 컴포넌트의 SetupPlayer 함수를 호출하고 싶다. 
	playerMove->SetupPlayerInputComponent(PlayerInputComponent);
	playerFire->SetupPlayerInputComponent(PlayerInputComponent);
}

