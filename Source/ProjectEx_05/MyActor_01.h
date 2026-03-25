//MyActor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor_01.generated.h"

UCLASS()
class PROJECTEX_05_API AMyActor_01 : public AActor
{
	GENERATED_BODY()
	
public:	

	AMyActor_01();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	//virtual void Tick(float DeltaTime) override;

private:
	void Move(float Distance);
	void Turn(float Angle);

	int32 MoveCount;
};
