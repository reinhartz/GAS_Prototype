// Copyright Clevrer

#pragma once

#include "CoreMinimal.h"
#include "Character/AeonCharacterBase.h"
#include "Interaction/HoverInterface.h"
#include "NPC.generated.h"

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
protected:
	virtual void BeginPlay() override;
};
