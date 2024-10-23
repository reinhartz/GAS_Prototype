// Copyright Clevrer


#include "AbilitySystem/AbilityTasks/TargetDataFromReticle.h"

UTargetDataFromReticle* UTargetDataFromReticle::CreateTargetDataFromReticle(UGameplayAbility* OwningAbility)
{
	UTargetDataFromReticle* MyObj = NewAbilityTask<UTargetDataFromReticle>(OwningAbility);

	return MyObj;
}

void UTargetDataFromReticle::Activate()
{
	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHit;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	ValidData.Broadcast(CursorHit.Location);
}
