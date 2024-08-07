// Copyright Clevrer

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_Mana_Max.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UMMC_Mana_Max : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:

	UMMC_Mana_Max();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

	FGameplayEffectAttributeCaptureDefinition IntelligenceDef;
};
