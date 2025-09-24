#include "FateWeaponBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "ProjectFate/CoreHelpers/CoreStructs.h"
#include "ProjectFate/ProjectFateProjectile.h"

class UEnhancedInputComponent;

AFateWeaponBase::AFateWeaponBase()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	WeaponMesh->SetupAttachment(RootComponent);

	PickupComponent = CreateDefaultSubobject<UProjectFatePickUpComponent>("PickupComponent");
	PickupComponent->SetupAttachment(WeaponMesh);
	PrimaryActorTick.bCanEverTick = true;
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
	
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
	QueryParams.AddIgnoredActor(this);
	
}

void AFateWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

void AFateWeaponBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

/**
 * Attach Weapon to player
 * @param TargetCharacter Owner Player that's picking up the gun
 * @return if they can attach the weapon or not
 */
bool AFateWeaponBase::AttachWeapon(AProjectFateCharacter* TargetCharacter)
{
	if (TargetCharacter != nullptr)
	{
		if (TargetCharacter->CurrentWeapon != nullptr)
		{
			return false;
		} 
	}
	SetOwningPawn(TargetCharacter);
	QueryParams.AddIgnoredActor(Character);
	
	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<AFateWeaponBase>())
	{
		return false;
	}
	
	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	//check what is what
	if (Character->IsLocallyControlled())
	{
		AttachToComponent(Character->GetMesh1P(), AttachmentRules, SocketName);
	}
	else
	{
		AttachToComponent(Character->GetMesh3P(),AttachmentRules, FName(TEXT("hand_rSocket")));
	}
	return true;
}



/**
 * Sets owning pawn for networking/RPC purposes
 * @param NewPawn Parent to set owning pawn
 */
void AFateWeaponBase::SetOwningPawn(AProjectFateCharacter* NewPawn)
{
	if ( Character != NewPawn)
	{
		SetInstigator(NewPawn);
		Character = NewPawn;

		SetOwner(Character);
	}
}

/**
 * Fire method for weapons, do not override this method, override the projectile + hitscan methods
 * @param OwningCharacter Fire method, that calls both the server and related switch case
 */
void AFateWeaponBase::Fire(const AProjectFateCharacter* OwningCharacter)
{
	//client code
	if (!HasAuthority())
	{
		DoShootFlair();
		DoUIFlair();
	}
	//server code
	else
	{
		switch (WeaponType)
		{
		case EWeaponType::L_Projectile:
			FireProjectile();
			break;
		case EWeaponType::L_HitScan:
			FireHitScan();
			break;
		default:
				//default handling
				break;
		}
		//if locally controlled then play sound Anim
		if (OwningCharacter->IsLocallyControlled())
		{
			DoShootFlair();
			DoUIFlair();
		}
	}
}

void AFateWeaponBase::DoShootFlair() const
{
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, Character->GetActorLocation());
	}
	
	if (FireAnimation != nullptr)
	{
		UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
	
}

//can be overriden 
void AFateWeaponBase::FireProjectile()
{
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			const FVector  SpawnLocation = WeaponMesh->GetSocketLocation("Muzzle");
				
			World->SpawnActor<AProjectFateProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}
}

//can be overriden as well
void AFateWeaponBase::FireHitScan()
{
	
}

void AFateWeaponBase::DoUIFlair_Implementation()
{
}

