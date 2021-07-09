// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayer.h"
#include "PlayerMove.h"

// Sets default values
AShootPlayer::AShootPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Actor 를 이루는 컴포넌트를 붙이도록 한다.
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	
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
}

