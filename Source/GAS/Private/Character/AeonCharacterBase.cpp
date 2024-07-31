// Copyright Clevrer


#include "Character/AeonCharacterBase.h"
#include "AbilitySystemComponent.h"

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

void AAeonCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);

	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}
