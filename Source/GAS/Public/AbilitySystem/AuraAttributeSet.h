// Copyright Clevrer

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \

/**
 * 
 */
UCLASS()
class GAS_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health_Max, Category = "Vital Attributes")
	FGameplayAttributeData Health_Max;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health_Max);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana_Max, Category = "Vital Attributes")
	FGameplayAttributeData Mana_Max;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana_Max);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_Health_Max(const FGameplayAttributeData& OldHealth_Max) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_Mana_Max(const FGameplayAttributeData& OldMana_Max) const;
};
