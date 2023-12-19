#include "BEM_Solver.h"

#include "subdivisionscheme.h"



UBEM_Solver::UBEM_Solver()
    // Settings
    : TimeStep{ 0.1 }

    , ProximityDistance{ 1 }
    , MergeDistance{ 0.1 }
    , DropletMergeDistance{ 0.1 }
    , PerformSmoothing{ false }
    , AdjacentTargetEdgeLengthRatio{ 1.5 }
    , CurvatureCoefficient{ 0.05 }
    , VelocityCoefficient{ 0.01 }
    , MinTargetEdgeLength{ 0.01 }
    , MaxTargetEdgeLength{ 0.05 }
    , RefineSolid{ false }
    , RefineTripleJunction{ false }
    , MaxVolumeChange{ 0.02 }
    , MinTriangleAngle{ 3.0 }
    , MaxTriangleAngle{ 177.0 }
    , LargestTriangleSplit{ 160.0 }
    , MinTriangleArea{ 0.05 }
    , AllowNonManifold{ true }
    , AllowTopologyChanges{ true }
    , EnableT1Transition{ true }
    , PullApartDistance{ 0.3 }
    , SmoothSubdivision{ false }

    // Privates
    , m_Vertices{}
    , m_Triangles{}
    , m_TriangleLabels{}

    , m_pSurfTrack{}
    , m_pVertexData{}
{
	PrimaryComponentTick.bCanEverTick = false;

}
UBEM_Solver::~UBEM_Solver()
{
    if (m_pSurfTrack) delete m_pSurfTrack;
}

//void UBEM_Solver::BeginPlay()
//{
//	Super::BeginPlay();
//
//}

//void UBEM_Solver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//}

void UBEM_Solver::Initialize(const TArray<FVector>& vectors, const TArray<int32>& triangles, const TArray<FVector2D>& triangleLabels,
                             const TArray<char>& solids, const TArray<FVector>& velocities)
{
    // Init variables
    m_Vertices.reserve(vectors.Num());
    LosTopos::Vec3d vertex{};
    for (int32 idx{}; idx < vectors.Num(); ++idx)
    {
        vertex = { vectors[idx].X, vectors[idx].Y, vectors[idx].Z };
        m_Vertices.emplace_back(vertex);
    }

    m_Triangles.reserve(triangles.Num());
    LosTopos::Vec3st triangle{};
    for (int32 idx{}; idx < triangles.Num(); ++idx)
    {
        triangle = LosTopos::Vec3st{ static_cast<size_t>(triangles[idx]) };
        m_Triangles.emplace_back(triangle);
    }

    m_TriangleLabels.reserve(triangleLabels.Num());
    LosTopos::Vec2i triangleLabel{};
    for (int32 idx{}; idx < triangleLabels.Num(); ++idx)
    {
        triangleLabel = { static_cast<int>(triangleLabels[idx].X), static_cast<int>(triangleLabels[idx].Y) };
        m_TriangleLabels.emplace_back(triangleLabel);
    }

    for (int32 idx{}; idx < solids.Num(); ++idx) m_Solids.push_back(solids[idx]);
    for (int32 idx{}; idx < velocities.Num(); ++idx) m_Velocities.push_back(velocities[idx]);

    // Init functions
    InitLosTopos();
}

bool UBEM_Solver::generate_collapsed_position(LosTopos::SurfTrack& st, size_t v0, size_t v1, LosTopos::Vec3d& pos)
{
    return false;
}
bool UBEM_Solver::generate_split_position(LosTopos::SurfTrack& st, size_t v0, size_t v1, LosTopos::Vec3d& pos)
{
    return false;
}
bool UBEM_Solver::generate_snapped_position(LosTopos::SurfTrack& st, size_t v0, size_t v1, LosTopos::Vec3d& pos)
{
    return false;
}
LosTopos::Vec3c UBEM_Solver::generate_collapsed_solid_label(LosTopos::SurfTrack& st, size_t v0, size_t v1, const LosTopos::Vec3c& label0, const LosTopos::Vec3c& label1)
{
    return {};
}
LosTopos::Vec3c UBEM_Solver::generate_split_solid_label(LosTopos::SurfTrack& st, size_t v0, size_t v1, const LosTopos::Vec3c& label0, const LosTopos::Vec3c& label1)
{
    return {};
}
LosTopos::Vec3c UBEM_Solver::generate_snapped_solid_label(LosTopos::SurfTrack& st, size_t v0, size_t v1, const LosTopos::Vec3c& label0, const LosTopos::Vec3c& label1)
{
    return {};
}
bool UBEM_Solver::generate_edge_popped_positions(LosTopos::SurfTrack& st, size_t oldv, const LosTopos::Vec2i& cut, LosTopos::Vec3d& pos_upper, LosTopos::Vec3d& pos_lower)
{
    return false;
}
bool UBEM_Solver::generate_vertex_popped_positions(LosTopos::SurfTrack& st, size_t oldv, int A, int B, LosTopos::Vec3d& pos_a, LosTopos::Vec3d& pos_b)
{
    return false;
}
bool UBEM_Solver::solid_edge_is_feature(const LosTopos::SurfTrack& st, size_t edge)
{
    return false;
}

LosTopos::Vec3d UBEM_Solver::sampleVelocity(LosTopos::Vec3d& pos)
{
    return {};
}

void UBEM_Solver::InitLosTopos()
{
 //   // Parameters
 //   // ----------

	//LosTopos::SurfTrackInitializationParameters parameters{};

 //   parameters.m_proximity_epsilon = ProximityDistance;
 //   parameters.m_merge_proximity_epsilon = MergeDistance;
 //   parameters.m_merge_proximity_epsilon_for_liquid_sheet_puncture = DropletMergeDistance;
 //   parameters.m_allow_vertex_movement_during_collapse = true;
 //   parameters.m_perform_smoothing = static_cast<int>(PerformSmoothing);
 //   parameters.m_max_adjacent_target_edge_length_ratio = AdjacentTargetEdgeLengthRatio;
 //   parameters.m_target_edge_length_coef_curvature = CurvatureCoefficient;
 //   parameters.m_target_edge_length_coef_velocity = VelocityCoefficient / TimeStep;
 //   parameters.m_min_target_edge_length = MinTargetEdgeLength;
 //   parameters.m_max_target_edge_length = MaxTargetEdgeLength;
 //   parameters.m_refine_solid = RefineSolid;
 //   parameters.m_refine_triple_junction = RefineTripleJunction;
 //   parameters.m_max_volume_change = MaxVolumeChange;
 //   parameters.m_min_triangle_angle = MinTriangleAngle;
 //   parameters.m_max_triangle_angle = MaxTriangleAngle;
 //   parameters.m_large_triangle_angle_to_split = LargestTriangleSplit;
 //   parameters.m_min_triangle_area = MinTriangleArea;
 //   parameters.m_verbose = false;
 //   parameters.m_allow_non_manifold = AllowNonManifold;
 //   parameters.m_allow_topology_changes = AllowTopologyChanges;
 //   parameters.m_collision_safety = true;
 //   parameters.m_remesh_boundaries = true;
 //   parameters.m_t1_transition_enabled = EnableT1Transition;
 //   parameters.m_pull_apart_distance = PullApartDistance;
 //   parameters.m_velocity_field_callback = NULL;

 //   if (SmoothSubdivision)  parameters.m_subdivision_scheme = new LosTopos::ButterflyScheme();
 //   else                    parameters.m_subdivision_scheme = new LosTopos::MidpointScheme();

 //   parameters.m_use_curvature_when_collapsing = false;
 //   parameters.m_use_curvature_when_splitting = false;


 //   // Created surfTracks
 //   // ------------------

 //   std::vector<LosTopos::Vec3d> masses(m_Vertices.size(), LosTopos::Vec3d{1, 1, 1});
 //   for (size_t idx{}; idx < m_Vertices.size(); idx++)
 //   {
 //       masses[idx] = LosTopos::Vec3d{ 1, 1, m_Solids[idx] ? std::numeric_limits<double>::infinity() : 1 };
 //   }
 //   
 //   m_pSurfTrack = new LosTopos::SurfTrack{ m_Vertices, m_Triangles, m_TriangleLabels, masses, parameters };
 //   m_pSurfTrack->m_solid_vertices_callback = this;
 //   m_pSurfTrack->m_mesheventcallback = this;

 //   
 //   // Initialize the dynamics quantities
 //   // ----------------------------------

 //   m_pVertexData = new LosTopos::NonDestructiveTriMesh::VertexData<FVector>{ &(m_pSurfTrack->m_mesh) };
 //   
 //   for (size_t idx{}; idx < m_pSurfTrack->m_mesh.nv(); idx++)
 //   {
 //       (*m_pVertexData)[idx] = m_Velocities[idx];
 //   }

    //m_pre_stepping_geometry = VecXd::Zero(nv() * 3);
    //for (size_t i = 0; i < nv(); i++)
    //    m_pre_stepping_geometry.segment<3>(i * 3) = pos(i);

    //m_intermediate_v_selector = 0;
    //m_intermediate_v.push_back(std::pair<VecXd, std::string>(velv(), "Scene initial velocity"));
}