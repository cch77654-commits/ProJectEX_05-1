

#include "MyActor_01.h"


AMyActor_01::AMyActor_01()
{
 	
	PrimaryActorTick.bCanEverTick = false; //틱 사용 x

}


void AMyActor_01::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.f, 50.f, 0.f));

	for (int i = 0; i < 10; i++)
	{
		float Distance = FMath::RandRange(100.f, 300.f);
		float Angle = FMath::RandRange(0.f, 360.f);

		Move(Distance);
		Turn(Angle);
	}
}


void AMyActor_01::Move(float Distance)
{
	FVector CurrentLocation = GetActorLocation();

	// 전방 방향 기준 이동
	FVector Forward = GetActorForwardVector();
	FVector NewLocation = CurrentLocation + (Forward * Distance);

	SetActorLocation(NewLocation);

	// 화면 출력->이게 안되서 하루 통으로 날렸습니다 ㅎㅎ
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			10.f,
			FColor::Green,
			FString::Printf(TEXT("Location: X=%.1f Y=%.1f Z=%.1f"),
				NewLocation.X, NewLocation.Y, NewLocation.Z)
		);
	}
}

void AMyActor_01::Turn(float Angle)
{
	FRotator CurrentRotation = GetActorRotation();

	FRotator NewRotation = CurrentRotation;
	NewRotation.Yaw += Angle;

	SetActorRotation(NewRotation);
}

