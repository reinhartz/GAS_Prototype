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

USTRUCT(Blueprintable)
struct FEffectProperties
{
	GENERATED_BODY()

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;
	
	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

// typedef is specific to FGameplayAttribute() signature, but TStaticFunPtr is generic to any signature
// typedef TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultDelegateUserPolicy>::FFuncPtr FAttributeFuncPtr;
template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

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

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;

	/*
	* Primary Attributes
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);

	/*
	* Vital Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	/*
	* Meta Attributes
	*/

	UPROPERTY(BlueprintReadOnly, Category = "Meta Attributes")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, IncomingDamage);

	/*
	* Secondary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health_Max, Category = "Secondary Attributes")
	FGameplayAttributeData Health_Max;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health_Max);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health_Regen, Category = "Secondary Attributes")
	FGameplayAttributeData Health_Regen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health_Regen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana_Max, Category = "Secondary Attributes")
	FGameplayAttributeData Mana_Max;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana_Max);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana_Regen, Category = "Secondary Attributes")
	FGameplayAttributeData Mana_Regen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana_Regen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor_Penetration, Category = "Secondary Attributes")
	FGameplayAttributeData Armor_Penetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor_Penetration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Block, Category = "Secondary Attributes")
	FGameplayAttributeData Block;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Block);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Critical_Hit, Category = "Secondary Attributes")
	FGameplayAttributeData Critical_Hit;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Critical_Hit);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Critical_Resistance, Category = "Secondary Attributes")
	FGameplayAttributeData Critical_Resistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Critical_Resistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Critical_Damage, Category = "Secondary Attributes")
	FGameplayAttributeData Critical_Damage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Critical_Damage);

	//Vital OnReps

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	//Primary OnReps
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	// Secondary OnReps

	UFUNCTION()
	void OnRep_Health_Max(const FGameplayAttributeData& OldHealth_Max) const;

	UFUNCTION()
	void OnRep_Health_Regen(const FGameplayAttributeData& OldHealth_Regen) const;

	UFUNCTION()
	void OnRep_Mana_Max(const FGameplayAttributeData& OldMana_Max) const;

	UFUNCTION()
	void OnRep_Mana_Regen(const FGameplayAttributeData& OldMana_Regen) const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_Armor_Penetration(const FGameplayAttributeData& OldArmor_Penetration) const;

	UFUNCTION()
	void OnRep_Block(const FGameplayAttributeData& OldBlock) const;

	UFUNCTION()
	void OnRep_Critical_Hit(const FGameplayAttributeData& OldCritical_Hit) const;

	UFUNCTION()
	void OnRep_Critical_Resistance(const FGameplayAttributeData& OldCritical_Resistance) const;

	UFUNCTION()
	void OnRep_Critical_Damage(const FGameplayAttributeData& OldCritical_Damage) const;

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
