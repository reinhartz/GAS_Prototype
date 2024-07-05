// Copyright Clevrer


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealth_Changed.Broadcast(AuraAttributeSet->GetHealth());
	OnHealth_Max_Changed.Broadcast(AuraAttributeSet->GetHealth_Max());
	
	OnMana_Changed.Broadcast(AuraAttributeSet->GetMana());
	OnMana_Max_Changed.Broadcast(AuraAttributeSet->GetMana_Max());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::Health_Changed);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealth_MaxAttribute()).AddUObject(this, &UOverlayWidgetController::Health_Max_Changed);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::Mana_Changed);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMana_MaxAttribute()).AddUObject(this, &UOverlayWidgetController::Mana_Max_Changed);
}

void UOverlayWidgetController::Health_Changed(const FOnAttributeChangeData& Data) const
{
	OnHealth_Changed.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::Health_Max_Changed(const FOnAttributeChangeData& Data) const
{
	OnHealth_Max_Changed.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::Mana_Changed(const FOnAttributeChangeData& Data) const
{
	OnMana_Changed.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::Mana_Max_Changed(const FOnAttributeChangeData& Data) const
{
	OnMana_Max_Changed.Broadcast(Data.NewValue);
}
