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
	// BoxCollision  ������Ʈ ���
	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	// ��Ʈ������Ʈ�� �Ǿ�� �Ѵ�.
	RootComponent = collision;
	collision->SetCollisionProfileName(TEXT("BlockAll"));

	// bodymesh ������Ʈ ���
	// Root �� �ڽ����� ���
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(RootComponent);
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// �������� ����(�ּ�) �� �ε��Ͽ� �Ҵ��ϱ�
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// �����ͷε尡 �����ߴٸ�
	if (tempMesh.Succeeded())
	{
		// bodyMesh �� �Ҵ����ֱ�
		bodyMesh->SetStaticMesh(tempMesh.Object);
	}

	// �ѱ� ������Ʈ ���� ���̱�
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	firePosition->SetupAttachment(RootComponent);

	// Actor �� �̷�� ������Ʈ�� ���̵��� �Ѵ�.
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

	// PlayerMove ������Ʈ�� SetupPlayer �Լ��� ȣ���ϰ� �ʹ�. 
	playerMove->SetupPlayerInputComponent(PlayerInputComponent);
	playerFire->SetupPlayerInputComponent(PlayerInputComponent);
}

