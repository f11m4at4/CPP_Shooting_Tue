// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// Log Category 추가하고 싶다.
DECLARE_LOG_CATEGORY_EXTERN(Shoot, Log, All);

//#define Multiply(x, y) ((x) * (y))
// 호출하는 함수이름과 위치(줄번호) 정보 매크로
#define APPINFO ( FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")") )

// 호출정보 찍는 함수
#define CALLINFO() UE_LOG(Shoot, Warning, TEXT("%s"), *APPINFO)

// 원하는 문구 출력하도록 하는 함수
#define PRINTLOG(fmt, ...) UE_LOG(Shoot, Warning, TEXT("%s %s"), *APPINFO, *FString::Printf(fmt, ##__VA_ARGS__))
