// Copyright Clevrer


#include "AeonCharacterBase.h"

// Sets default values
AAeonCharacterBase::AAeonCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAeonCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAeonCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAeonCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

