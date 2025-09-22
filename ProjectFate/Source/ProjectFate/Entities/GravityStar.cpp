#include "GravityStar.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectFate/ProjectFateCharacter.h"


AGravityStar::AGravityStar()
{
	
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetCollisionObjectType(ECC_WorldDynamic);
	SphereComponent->SetSphereRadius(500);
	RootComponent = SphereComponent;

	// MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	// MovementComponent->InitialSpeed = 1000.0f;
	// MovementComponent->bRotationFollowsVelocity = true;
	// MovementComponent->bInitialVelocityInLocalSpace = true;
	
}

// Called when the game starts or when spawned
void AGravityStar::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGravityStar::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AGravityStar::InGravityStar);
}


// Called every frame
void AGravityStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerCharacter != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Gravity Star Movement"));
		GravityDir = GetActorLocation() - PlayerCharacter->GetActorLocation();
		GravityDir.Normalize();
		PlayerCharacter->GetCharacterMovement()->SetGravityDirection(GravityDir);
	}
}

void AGravityStar::InGravityStar(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerCharacter = Cast<AProjectFateCharacter>(OtherActor);
	if( PlayerCharacter != nullptr)
	{
		GravityDir = GetActorLocation() - OtherActor->GetActorLocation();
		GravityDirCache = PlayerCharacter->GetCharacterMovement()->GetGravityDirection();
		PlayerCharacter->GetCharacterMovement()->SetGravityDirection(GravityDir);
		GetWorldTimerManager().SetTimer(TimerHandle_Lifetime, this, &AGravityStar::ResetPlayer, LifeTime);
	}
}

void AGravityStar::ResetPlayer()
{
	if (PlayerCharacter != nullptr)
	{
		PlayerCharacter->GetCharacterMovement()->SetGravityDirection(GravityDirCache);
		FVector Fwd = PlayerCharacter->GetFirstPersonCameraComponent()->GetForwardVector();
		PlayerCharacter->LaunchCharacter(Fwd * ExplodeForce, false, false);
		Destroy();
	}
}
