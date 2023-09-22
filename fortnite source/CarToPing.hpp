//#pragma once
//#include "stdafx.hpp"
//
//bool EnableCarToPing;
//namespace AFortSplineGroundPath
//{
//	constexpr auto MaxDistanceBetweenPathwayPoints = 0x9d8; // float
//	constexpr auto EvenlySpacedPointsDistance = 0x9dc; // float
//	constexpr auto TangentDistance = 0x9e0; // float
//	constexpr auto PathUpdateSecondIntervals = 0x9e4; // float
//	constexpr auto PathTestRadius = 0x9e8; // float
//	constexpr auto MinDistanceForAddingRawPoint = 0x9ec; // float
//	constexpr auto bDrawDebugRawPoints = 0x9f0; // char : 1
//	constexpr auto bDrawDebugRawEnd = 0x9f0; // char : 1
//	constexpr auto bDrawDebugReppedPoints = 0x9f0; // char : 1
//	constexpr auto bDrawDebugEvenlySizedSegments = 0x9f0; // char : 1
//	constexpr auto bDrawDebugTangents = 0x9f0; // char : 1
//	constexpr auto bDrawDebugCollision = 0x9f0; // char : 1
//	constexpr auto bDrawDebugSplineEnd = 0x9f0; // char : 1
//	constexpr auto CleanupTime = 0x9f4; // float
//	constexpr auto PathwayPointOffset = 0x9f8; // FVector
//	constexpr auto LerpScaleRate = 0xa10; // float
//	constexpr auto GrowthSmoothingStrength = 0xa14; // float
//	constexpr auto MostRecentlyAddedLocation = 0xa18; // FVector
//	constexpr auto MostRecentlyAddedTime = 0xa30; // float
//	constexpr auto FortReppedPointList = 0xa38; // FFortReppedPointList
//	constexpr auto RawPoints = 0xb58; // TArray
//	constexpr auto ServerIndexToAssign = 0xb68; // int32_t
//	constexpr auto EvenlySizedSegments = 0xb70; // TArray
//	constexpr auto FrontEndCurrentScale = 0xb80; // FVector2D
//	constexpr auto FrontEndDestScale = 0xb90; // FVector2D
//	constexpr auto ReppedLastServerIndexToReppedPointIndices = 0xba0; // TArray
//	constexpr auto RawPointsToLastServerIndicesPlusAlpha = 0xbb0; // TArray
//	constexpr auto StaticMesh = 0xbc0; // UStaticMesh*
//	constexpr auto Material = 0xbc8; // UMaterial*
//	constexpr auto StaticMeshScaleStart = 0xbd0; // FVector2D
//	constexpr auto StaticMeshScaleTarget = 0xbe0; // FVector2D
//	constexpr auto ForwardAxis = 0xbf0; // ESplineMeshAxis
//	constexpr auto LerpLocationRate = 0xbf4; // float
//	constexpr auto bMostRecentLocationHasBeenSet = 0xbf8; // bool
//	constexpr auto bHasWarnedOfArrayOverfill = 0xbf9; // bool
//	constexpr auto bHasWarnedOfUnableToRepDestroy = 0xbfa; // bool
//	constexpr auto FirstActiveEvenlySizedSegmentIndex = 0xbfc; // int32_t
//	constexpr auto MaxReppedPointsBeforeOverfill = 0xc00; // int32_t
//	constexpr auto LerpedMostRecentLocation = 0xc08; // FVector
//	constexpr auto DistanceRemainingToNextEvenlySpacedPoint = 0xc30; // float
//	constexpr auto PositionFinalizedParameterName = 0xc34; // FName
//	constexpr auto GrowthParameterName = 0xc38; // FName
//	constexpr auto ShrinkParameterName = 0xc3c; // FName
//	constexpr auto OpacityParameterName = 0xc40; // FName
//	constexpr auto TotalFadeInTime = 0xc44; // float
//	constexpr auto TotalFadeOutTime = 0xc48; // float
//	constexpr auto SectionsLifeTime = 0xc4c; // float
//	constexpr auto ShrinkTimeMultWhenFading = 0xc50; // float
//	constexpr auto ShrinkTimeMultWhenBurning = 0xc54; // float
//	constexpr auto GrowthTimeMult = 0xc58; // float
//	constexpr auto LocationLerpTimeMult = 0xc5c; // float
//	constexpr auto CurrentFadeInTime = 0xc60; // float
//	constexpr auto CurrentFadeOutTime = 0xc64; // float
//	constexpr auto TotalSplineMeshesToFadeIn = 0xc68; // int32_t
//	constexpr auto LowestUninitializedRawLastServerIndex = 0xc6c; // int32_t
//	constexpr auto LowestUninitializedReppedIndex = 0xc70; // int32_t
//	constexpr auto NumIgnitedSections = 0xc88; // int32_t
//	constexpr auto bSomeSectionsAreFadingOut = 0xc8c; // bool
//}
//
//void CarToPing_hook()
//{
//    if (enable_exploit_server)
//    {
//		uint64_t Vehicle = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
//		DWORD_PTR VehicleRootComp = ctx->read_physical_memory<DWORD_PTR>(Vehicle + Actor::RootComponent);
//		DWORD_PTR PawnRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Actor::RootComponent);
//		//Vector3 read_pos = ctx->read_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation + AFortSplineGroundPath::PathwayPointOffset);
//		auto read_pos_vehcle = ctx->read_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation);
//		//Vector3 read_pos = ctx->read_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation);
//		//printf("ping: %0.0f, %0.0f, %0.0f", read_pos.x, read_pos.y, read_pos.z);
//        if (EnableCarToPing) {
//      
//			DWORD_PTR VehicleRootComp = ctx->read_physical_memory<DWORD_PTR>(Vehicle + Actor::RootComponent);
//			char cache = ctx->read_physical_memory<char>(VehicleRootComp + Actor::RootComponent);
//		
//			
//		      	Vector3 Ping = read_pos_vehcle;
//              
//                    ctx->write_physical_memory<char>(VehicleRootComp + Actor::RootComponent, 0);
//             //       ctx->write_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation, AFortSplineGroundPath::PathwayPointOffset);
//					ctx->write_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation, Vector3{ Ping.x, Ping.y, Ping.z + 100 });
//					ctx->write_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation, Vector3{ Ping.x, Ping.y, Ping.z + 100 });
//					ctx->write_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation, Vector3{ Ping.x, Ping.y, Ping.z + 100 });
//                   // ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation, AFortSplineGroundPath::PathwayPointOffset +  FVector::Y);
//                    //ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation, AFortSplineGroundPath::PathwayPointOffset +  FVector::Z);
//			//		ctx->write_physical_memory<double>(VehicleRootComp + 0x260, AFortSplineGroundPath::PathwayPointOffset + FVector::X);
//			//		ctx->write_physical_memory<double>(VehicleRootComp + 0x260, AFortSplineGroundPath::PathwayPointOffset + FVector::Y);
//			//		ctx->write_physical_memory<double>(VehicleRootComp + 0x260, AFortSplineGroundPath::PathwayPointOffset + FVector::Z);
//					
//			//		
//			//		ctx->write_physical_memory<char>(PawnRootComp + AActor::RootComponent, 0);
//			//		ctx->write_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation, AFortSplineGroundPath::PathwayPointOffset + FVector::X);
//			//		ctx->write_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation, AFortSplineGroundPath::PathwayPointOffset + FVector::Y);
//			//		ctx->write_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation, AFortSplineGroundPath::PathwayPointOffset + FVector::Z);*/
//                
//               
//            
//        }
//    }
//}