#include "BEM_ProceduralMesh.h"
#include "KismetProceduralMeshLibrary.h"

ABEM_ProceduralMesh::ABEM_ProceduralMesh()
	: NrRows{ 10 }
	, NrCols{ 10 }
	, PlaneSize{ 100.f }
	, m_Vertices{}
	, m_Triangles{}
    , m_UVs{}
{
	PrimaryActorTick.bCanEverTick = false;

	// Components
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	RootComponent = ProceduralMesh;
}

void ABEM_ProceduralMesh::PostActorCreated()
{
	Super::PostActorCreated();

	CreateMesh();
}

//void ABEM_ProceduralMesh::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

//void ABEM_ProceduralMesh::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//

void ABEM_ProceduralMesh::CreateMesh()
{
    // Distance between vertices
    const float deltaX{ PlaneSize / NrCols };

    // Create grid mesh
    UKismetProceduralMeshLibrary::CreateGridMeshWelded(NrCols, NrRows, m_Triangles, m_Vertices, m_UVs, deltaX);

	// Create mesh
	ProceduralMesh->CreateMeshSection(0, m_Vertices, m_Triangles, TArray<FVector>(), m_UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), false);
}