#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "BEM_ProceduralMesh.generated.h"

UCLASS()
class WATERSIMULATION_API ABEM_ProceduralMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	ABEM_ProceduralMesh();

	virtual void PostActorCreated() override;
	//virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

public:
	// Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UProceduralMeshComponent* ProceduralMesh;

private:
	// Member variables
	TArray<FVector> m_Vertices;
	TArray<int32> m_Triangles;

	// Member functions
	void CreateMesh();
};
