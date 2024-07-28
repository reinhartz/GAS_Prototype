// Copyright Clevrer


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

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

	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags) 
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// "Message.Potion.Health".MatchesTage("Message") will return True, "Message".MatchesTag("Message.Potion.Health") will return False

				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
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
