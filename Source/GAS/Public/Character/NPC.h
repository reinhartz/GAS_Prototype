// Copyright Clevrer

#pragma once

#include "CoreMinimal.h"
#include "Character/AeonCharacterBase.h"
#include "Interaction/HoverInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "NPC.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class GAS_API ANPC : public AAeonCharacterBase, public IHoverInterface
{
	GENERATED_BODY()
public:
	ANPC();
		
	/** Hover Interface **/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
	/** end Hover Interface memebrs **/

	/** Combat Interface **/
	virtual int32 GetCharacterLevel() override;
	/** end Combat Interface **/

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealth_MaxChanged;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo();
	virtual void InitializeDefaultAttributes() const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
