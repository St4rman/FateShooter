#include "FateRocket.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ProjectFate/ProjectFateCharacter.h"

AFateRocket::AFateRocket()
{
	GetCollisionComp()->SetSphereRadius(500.0f);
	PrimaryActorTick.bCanEverTick = true;
}

void AFateRocket::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GetCollisionComp()->OnComponentHit.AddDynamic(this, &AFateRocket::OnExplode);
}
void AFateRocket::BeginPlay()
{
	Super::BeginPlay();
	if (!HasAuthority())
	{
		Destroy();
	}
	GetWorldTimerManager().SetTimer(TimerHandle_Lifetime, this, &AFateRocket::PostLifeTimeExpired, 2.0f);
}

// Called every frame
void AFateRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFateRocket::PostLifeTimeExpired()
{
	Destroy();
}

void AFateRocket::OnExplode(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!HasAuthority())
	{
		return;
	}
	if (AProjectFateCharacter* OActor =Cast<AProjectFateCharacter>(OtherActor))
	{
		if (OActor == GetShooter())
		{
			return;
		}
		OActor->GetStatComp()->LowerHealth(DirectHitDamage, GetShooter());
		Destroy();
	}

	else
	{
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray;
		ObjectTypesArray.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
		TArray<AActor*> ActorsToIgnore;
		TArray<FHitResult> OutHits;

		bool bHasHit = UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), GetActorLocation(), GetActorLocation(), 500.0f,
			ObjectTypesArray, false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, OutHits, true);

		for (FHitResult Hit : OutHits)
		{
			AProjectFateCharacter* Player = Cast<AProjectFateCharacter>(Hit.GetActor());
			
			if (Player != nullptr )
			{
				if (Player == GetShooter())
				{
					FVector Dir = GetActorLocation() - Player->GetActorLocation();
					Dir.Normalize();
					Player->LaunchCharacter(-Dir * ExplodeForce, false, false);
				}
				else
				{
					Player->GetStatComp()->LowerHealth(SplashDamage, GetShooter());
				}
			}
		}
	}
	Destroy();
}