
//Developing by https://github.com/hammerinformation

#include "Jumpscare.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
AJumpscare::AJumpscare()
{
	PrimaryActorTick.bCanEverTick = true;
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));


	RootComponent = Trigger;
	Object = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Object"));
	Object->AttachTo(RootComponent);

}

void AJumpscare::BeginPlay()
{
	Super::BeginPlay();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AJumpscare::OnComponentBeginOverlap);
	Object->SetHiddenInGame(true);
	Object->AddRelativeLocation(FVector(20, 0, 0));
	Object->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AJumpscare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJumpscare::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player")) {
		if (Sound && Object) {
			UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
			Object->SetHiddenInGame(false);
			Object->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

			UE_LOG(LogTemp, Error, TEXT("Player is here "));
			
			SetLifeSpan(2.0f);
		}

	}
}

