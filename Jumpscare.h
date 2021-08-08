//Developing by https://github.com/hammerinformation

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Jumpscare.generated.h"

UCLASS()
class CPPEXAMPLE_API AJumpscare : public AActor
{
	GENERATED_BODY()
	
public:	
	AJumpscare();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Object;

	UPROPERTY(VisibleAnywhere)
		class	UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere)
		class	USoundBase* Sound;

	UFUNCTION()
		void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
};
