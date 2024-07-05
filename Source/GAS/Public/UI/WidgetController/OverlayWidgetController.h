// Copyright Clevrer

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealth_ChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealth_Max_ChangedSignature, float, NewHealth_Max);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMana_ChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMana_Max_ChangedSignature, float, NewMana_Max);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GAS_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;

	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealth_ChangedSignature OnHealth_Changed;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealth_Max_ChangedSignature OnHealth_Max_Changed;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMana_ChangedSignature OnMana_Changed;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMana_Max_ChangedSignature OnMana_Max_Changed;

protected:
	void Health_Changed(const FOnAttributeChangeData& Data) const;
	void Health_Max_Changed(const FOnAttributeChangeData& Data) const;

	void Mana_Changed(const FOnAttributeChangeData& Data) const;
	void Mana_Max_Changed(const FOnAttributeChangeData& Data) const;
};
