#include "BEM_ProceduralMesh.h"
#include "KismetProceduralMeshLibrary.h"
#include "BEM_Solver.h"

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

	BEM_Solver = CreateDefaultSubobject<UBEM_Solver>(TEXT("BemSolver"));
}

//void ABEM_ProceduralMesh::PostActorCreated()
//{
//	Super::PostActorCreated();
//
//	CreateMesh();
//}

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
	// Reset variables
	m_Vertices.Empty();
	m_Triangles.Empty();
	m_UVs.Empty();

	ProceduralMesh->ClearAllMeshSections();

    // Create grid mesh
    const float deltaX{ PlaneSize / NrCols };
    UKismetProceduralMeshLibrary::CreateGridMeshWelded(NrCols, NrRows, m_Triangles, m_Vertices, m_UVs, deltaX);

	ProceduralMesh->CreateMeshSection(0, m_Vertices, m_Triangles, TArray<FVector>(), m_UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), false);
}