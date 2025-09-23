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
	// SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AGravityStar::OutGravityStar);
}


// Called every frame
void AGravityStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// UE_LOG(LogTemp, Warning, TEXT("%f"), GetWorldTimerManager().GetTimerRemaining(TimerHandle_Lifetime));

	if (bIsActive)
	{
		PlayerCharacter->SetActorLocation(GetActorLocation());
	}
}

void AGravityStar::InGravityStar(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerCharacter = Cast<AProjectFateCharacter>(OtherActor);
	if( PlayerCharacter != nullptr)
	{
		GravityDir = GetActorLocation() - PlayerCharacter->GetActorLocation();
		GravityDirCache = PlayerCharacter->GetCharacterMovement()->GetGravityDirection();
		PlayerCharacter->GetCharacterMovement()->SetGravityDirection(GravityDir);

		GetWorldTimerManager().SetTimer(TimerHandle_Lifetime, this, &AGravityStar::ResetPlayer, 3.0f);
		bIsActive = true;
		DrawDebugLine(GetWorld(),  PlayerCharacter->GetActorLocation(), GetActorLocation(), FColor::Cyan, false, 5.0f, 0, 1.0f);
	}
}


void AGravityStar::ResetPlayer()
{
	if (PlayerCharacter != nullptr)
	{
		bIsActive = false;
		PlayerCharacter->GetCharacterMovement()->SetGravityDirection(GravityDirCache);
		const FVector Fwd = PlayerCharacter->GetFirstPersonCameraComponent()->GetForwardVector();
		PlayerCharacter->LaunchCharacter(Fwd * ExplodeForce, false, false);
		Destroy();
	}
}
