// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WaterSimulation : ModuleRules
{
	public WaterSimulation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ProceduralMeshComponent" });

		PublicIncludePaths.AddRange(new string[] { "LosTopos/LosTopos3D", "LosTopos/common" });
		PrivateIncludePaths.AddRange(new string[] { "LosTopos/LosTopos3D", "LosTopos/common" });

        //PrivateDefinitions.Add("LosTopos/LosTopos3D/accelerationgrid.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/broadphasegrid.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/collisionpipeline.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/dynamicsurface.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/edgecollapser.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/edgeflipper.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/edgesplitter.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/facesplitter.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/impactzonesolver.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/iomesh.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/meshcutter.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/meshmerger.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/meshpincher.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/meshsmoother.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/meshsnapper.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/nondestructivetrimesh.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/subdivisionscheme.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/surftrack.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/t1transition.cpp");
        //PrivateDefinitions.Add("LosTopos/LosTopos3D/trianglequality.cpp");

        //PrivateDefinitions.Add("LosTopos/common/newsparse/dense_matrix.cpp");
        //PrivateDefinitions.Add("LosTopos/common/newsparse/krylov_solvers.cpp");
        //PrivateDefinitions.Add("LosTopos/common/newsparse/sparse_matrix.cpp");

        //PrivateDefinitions.Add("LosTopos/common/tunicate/expansion.cpp");
        //PrivateDefinitions.Add("LosTopos/common/tunicate/intersection.cpp");
        //PrivateDefinitions.Add("LosTopos/common/tunicate/interval.cpp");
        //PrivateDefinitions.Add("LosTopos/common/tunicate/neg.cpp");
        //PrivateDefinitions.Add("LosTopos/common/tunicate/orientation.cpp");
        //PrivateDefinitions.Add("LosTopos/common/tunicate/rootparitycollisiontest.cpp");
        //PrivateDefinitions.Add("LosTopos/common/tunicate/sos_intersection.cpp");
        //PrivateDefinitions.Add("LosTopos/common/tunicate/sos_orientation.cpp");

        //PrivateDefinitions.Add("LosTopos/common/bfstream.cpp");
        //PrivateDefinitions.Add("LosTopos/common/collisionqueries.cpp");
        //PrivateDefinitions.Add("LosTopos/common/cubic_ccd_wrapper.cpp");
        //PrivateDefinitions.Add("LosTopos/common/marching_tiles_hires.cpp");
        //PrivateDefinitions.Add("LosTopos/common/predicates.cpp");
        //PrivateDefinitions.Add("LosTopos/common/root_parity_ccd_wrapper.cpp");
        //PrivateDefinitions.Add("LosTopos/common/runstats.cpp");
        //PrivateDefinitions.Add("LosTopos/common/wallclocktime.cpp");
    }
}
