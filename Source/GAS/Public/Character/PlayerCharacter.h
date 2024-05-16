// Copyright Clevrer

#pragma once

#include "CoreMinimal.h"
#include "Character/AeonCharacterBase.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API APlayerCharacter : public AAeonCharacterBase
{
	GENERATED_BODY()
public:
	APlayerCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState();
private:
	void InitAbilityActorInfo();
};
