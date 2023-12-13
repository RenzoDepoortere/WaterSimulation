#include "BEM_ProceduralMesh.h"

ABEM_ProceduralMesh::ABEM_ProceduralMesh()
	: m_Vertices{}
	, m_Triangles{}
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
	// Add vertices
	m_Vertices.Add(FVector(0, 0, 0));
	m_Vertices.Add(FVector(100, 0, 0));
	m_Vertices.Add(FVector(0, 100, 0));

	// Add indices
	m_Triangles.Add(0);
	m_Triangles.Add(1);
	m_Triangles.Add(2);

	// Create mesh
	ProceduralMesh->CreateMeshSection(0, m_Vertices, m_Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), false);
}