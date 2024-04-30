// Copyright Clevrer

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AeonCharacterBase.generated.h"

UCLASS(Abstract)
class GAS_API AAeonCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAeonCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
