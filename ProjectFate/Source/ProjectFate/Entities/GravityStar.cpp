#include "GravityStar.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ProjectFate/ProjectFateCharacter.h"


AGravityStar::AGravityStar()
{
	
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetCollisionObjectType(ECC_WorldDynamic);
	SphereComponent->SetSphereRadius(500);
	RootComponent = SphereComponent;
}

void AGravityStar::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle_Lifetime, this, &AGravityStar::ResetPlayer, 2.0f);
}

void AGravityStar::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AGravityStar::InGravityStar);
}


void AGravityStar::InGravityStar(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerCharacter = Cast<AProjectFateCharacter>(OtherActor);
	if( PlayerCharacter != nullptr)
	{
		GravityDir = GetActorLocation() - PlayerCharacter->GetActorLocation();
		GravityDir.Normalize();
		PlayerCharacter->LaunchCharacter(GravityDir* ExplodeForce * 0.5f, false, false);

		PlayerCharacter->SetLocomotionMode(L_Locked);
		
		DrawDebugLine(GetWorld(),  PlayerCharacter->GetActorLocation(), GetActorLocation(), FColor::Cyan, false, 5.0f, 0, 1.0f);
	}
}


void AGravityStar::ResetPlayer()
{
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray;
	ObjectTypesArray.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
	TArray<AActor*> ActorsToIgnore;
	TArray<FHitResult> OutHits;
	
	bool bHasHit = UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), GetActorLocation(), GetActorLocation(), 500.f,
		ObjectTypesArray,false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame , OutHits, true);

	for (FHitResult Hit : OutHits)
	{
		AProjectFateCharacter* Player = Cast<AProjectFateCharacter>(Hit.GetActor());
		if (Player != nullptr)
		{
			Player->SetLocomotionMode(L_Movement);
			Player->GetCharacterMovement()->SetGravityDirection(GravityDirCache);
			const FVector Fwd = Player->GetFirstPersonCameraComponent()->GetForwardVector();
			Player->LaunchCharacter(Fwd *  ExplodeForce, false, false);
		}
	}
	
	Destroy();
}
