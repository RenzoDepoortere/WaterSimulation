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

public:
	// Settings
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	int NrRows;
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	int NrCols;
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float PlaneSize;

private:
	// Member variables
	TArray<FVector> m_Vertices;
	TArray<int32> m_Triangles;
	TArray<FVector2D> m_UVs;

	// Member functions
	void CreateMesh();
};
