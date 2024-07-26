// Copyright Clevrer


#include "Character/AeonCharacterBase.h"

AAeonCharacterBase::AAeonCharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAeonCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAeonCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAeonCharacterBase::InitAbilityActorInfo()
{
}
