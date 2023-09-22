#pragma once

// Enum Engine.EViewModeIndex
enum class EViewModeIndex : uint8 {
	VMI_BrushWireframe = 0,
	VMI_Wireframe = 1,
	VMI_Unlit = 2,
	VMI_Lit = 3,
	VMI_Lit_DetailLighting = 4,
	VMI_LightingOnly = 5,
	VMI_LightComplexity = 6,
	VMI_ShaderComplexity = 8,
	VMI_LightmapDensity = 9,
	VMI_LitLightmapDensity = 10,
	VMI_ReflectionOverride = 11,
	VMI_VisualizeBuffer = 12,
	VMI_StationaryLightOverlap = 14,
	VMI_CollisionPawn = 15,
	VMI_CollisionVisibility = 16,
	VMI_LODColoration = 18,
	VMI_QuadOverdraw = 19,
	VMI_PrimitiveDistanceAccuracy = 20,
	VMI_MeshUVDensityAccuracy = 21,
	VMI_ShaderComplexityWithQuadOverdraw = 22,
	VMI_HLODColoration = 23,
	VMI_GroupLODColoration = 24,
	VMI_MaterialTextureScaleAccuracy = 25,
	VMI_RequiredTextureResolution = 26,
	VMI_PathTracing = 27,
	VMI_RayTracingDebug = 28,
	VMI_VisualizeNanite = 29,
	VMI_VirtualTexturePendingMips = 30,
	VMI_VisualizeLumen = 31,
	VMI_VisualizeVirtualShadowMap = 32,
	VMI_VisualizeGPUSkinCache = 33,
	VMI_VisualizeSubstrate = 34,
	VMI_VisualizeGroom = 35,
	VMI_Max = 36,
	VMI_Unknown = 255
};

char BWireframe = 1; // 0x194(0x01) - static
uintptr_t Wireframe = 0x194; // 0x194(0x01) - static var Wireframe;
uintptr_t SkeletalMeshes = 0x56b0; // 0x56b0(0x10)
uintptr_t PawnMaterials_ALL = 0x56c0; // 0x56c0(0x10)

