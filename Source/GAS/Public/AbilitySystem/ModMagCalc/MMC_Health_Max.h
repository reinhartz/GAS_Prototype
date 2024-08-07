// Copyright Clevrer

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_Health_Max.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UMMC_Health_Max : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	
	UMMC_Health_Max();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

	FGameplayEffectAttributeCaptureDefinition VigorDef;
};
