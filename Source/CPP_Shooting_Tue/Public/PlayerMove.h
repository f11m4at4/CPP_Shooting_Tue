


#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMove.generated.h"

// ����� �Է¿� ���� �����¿�� �̵��ϰ� �ʹ�.
// �ʿ�Ӽ� : �̵��ӵ�

UCLASS( ClassGroup=(HO), meta=(BlueprintSpawnableComponent) )
class CPP_SHOOTING_TUE_API UPlayerMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	void Horizontal(float value);
	void Vertical(float value);
	
public:
	// �ʿ�Ӽ� : �̵��ӵ�
	UPROPERTY(EditAnywhere, Category = "Setting", BlueprintReadOnly)
	float speed = 500;

private:
	UPROPERTY()
	class AShootPlayer* me;

	// ����Ű �Է� ����� ���� �Ӽ�
	float h;
	float v;
};
