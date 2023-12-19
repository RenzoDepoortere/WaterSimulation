// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "surftrack.h"
#include "BEM_Solver.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WATERSIMULATION_API UBEM_Solver : public UActorComponent, public LosTopos::SurfTrack::SolidVerticesCallback,
										public LosTopos::T1Transition::VelocityFieldCallback, public LosTopos::SurfTrack::MeshEventCallback
{
	GENERATED_BODY()

public:	
	UBEM_Solver();
	virtual ~UBEM_Solver();

	//virtual void BeginPlay() override;
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
public:
	// Public functions
	void Initialize(const TArray<FVector>& vectors, const TArray<int32>& triangles, const TArray<FVector2D>& triangleLabels,
					const TArray<char>& solids, const TArray<FVector>& velocities);

protected:
	// Virtual functions
	virtual bool generate_collapsed_position(LosTopos::SurfTrack& st, size_t v0, size_t v1, LosTopos::Vec3d& pos) override;
	virtual bool generate_split_position(LosTopos::SurfTrack& st, size_t v0, size_t v1, LosTopos::Vec3d& pos) override;
	virtual bool generate_snapped_position(LosTopos::SurfTrack& st, size_t v0, size_t v1, LosTopos::Vec3d& pos) override;
	virtual LosTopos::Vec3c generate_collapsed_solid_label(LosTopos::SurfTrack& st, size_t v0, size_t v1, const LosTopos::Vec3c& label0, const LosTopos::Vec3c& label1) override;
	virtual LosTopos::Vec3c generate_split_solid_label(LosTopos::SurfTrack& st, size_t v0, size_t v1, const LosTopos::Vec3c& label0, const LosTopos::Vec3c& label1) override;
	virtual LosTopos::Vec3c generate_snapped_solid_label(LosTopos::SurfTrack& st, size_t v0, size_t v1, const LosTopos::Vec3c& label0, const LosTopos::Vec3c& label1) override;
	virtual bool generate_edge_popped_positions(LosTopos::SurfTrack& st, size_t oldv, const LosTopos::Vec2i& cut, LosTopos::Vec3d& pos_upper, LosTopos::Vec3d& pos_lower) override;
	virtual bool generate_vertex_popped_positions(LosTopos::SurfTrack& st, size_t oldv, int A, int B, LosTopos::Vec3d& pos_a, LosTopos::Vec3d& pos_b) override;
	virtual bool solid_edge_is_feature(const LosTopos::SurfTrack& st, size_t edge) override;

	virtual LosTopos::Vec3d sampleVelocity(LosTopos::Vec3d& pos) override;

public:
	// Settings
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	double TimeStep;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double ProximityDistance;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double MergeDistance;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double DropletMergeDistance;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	bool PerformSmoothing;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double AdjacentTargetEdgeLengthRatio;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double CurvatureCoefficient;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double VelocityCoefficient;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double MinTargetEdgeLength;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double MaxTargetEdgeLength;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	bool RefineSolid;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	bool RefineTripleJunction;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double MaxVolumeChange;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double MinTriangleAngle;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double MaxTriangleAngle;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double LargestTriangleSplit;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double MinTriangleArea;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	bool AllowNonManifold;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	bool AllowTopologyChanges;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	bool EnableT1Transition;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	double PullApartDistance;
	UPROPERTY(EditDefaultsOnly, Category = "Settings|LosTopos")
	bool SmoothSubdivision;

private:
	// Member variables
	std::vector<LosTopos::Vec3d> m_Vertices;
	std::vector<LosTopos::Vec3st> m_Triangles;
	std::vector<LosTopos::Vec2i> m_TriangleLabels;
	std::vector<char> m_Solids;
	std::vector<FVector> m_Velocities;

	LosTopos::SurfTrack* m_pSurfTrack;
	LosTopos::NonDestructiveTriMesh::VertexData<FVector>* m_pVertexData;

	// Member functions
	void InitLosTopos();
};