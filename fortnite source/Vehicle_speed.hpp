//
//
//namespace UParticleSystemComponent
//{
//	constexpr auto Template = 0x560; // UParticleSystem*
//	constexpr auto EmitterMaterials = 0x568; // TArray<UMaterialInterface*>
//	constexpr auto SkelMeshComponents = 0x578; // TArray<USkeletalMeshComponent*>
//	constexpr auto bResetOnDetach = 0x589; // char : 1
//	constexpr auto bUpdateOnDedicatedServer = 0x589; // char : 1
//	constexpr auto bAllowRecycling = 0x589; // char : 1
//	constexpr auto bAutoManageAttachment = 0x589; // char : 1
//	constexpr auto bAutoAttachWeldSimulatedBodies = 0x589; // char : 1
//	constexpr auto bWarmingUp = 0x58a; // char : 1
//	constexpr auto bOverrideLODMethod = 0x58a; // char : 1
//	constexpr auto bSkipUpdateDynamicDataDuringTick = 0x58a; // char : 1
//	constexpr auto LODMethod = 0x595; // ParticleSystemLODMethod
//	constexpr auto RequiredSignificance = 0x596; // EParticleSignificanceLevel
//	constexpr auto InstanceParameters = 0x598; // TArray<FParticleSysParam>
//	constexpr auto OnParticleSpawn = 0x5a8; // FMulticastInlineDelegate
//	constexpr auto OnParticleBurst = 0x5b8; // FMulticastInlineDelegate
//	constexpr auto OnParticleDeath = 0x5c8; // FMulticastInlineDelegate
//	constexpr auto OnParticleCollide = 0x5d8; // FMulticastInlineDelegate
//	constexpr auto bOldPositionValid = 0x5e8; // bool
//	constexpr auto OldPosition = 0x5f0; // FVector
//	constexpr auto PartSysVelocity = 0x608; // FVector
//	constexpr auto WarmupTime = 0x620; // float
//	constexpr auto WarmupTickRate = 0x624; // float
//	constexpr auto SecondsBeforeInactive = 0x62c; // float
//	constexpr auto MaxTimeBeforeForceUpdateTransform = 0x634; // float
//	constexpr auto ReplayClips = 0x658; // TArray<UParticleSystemReplay*>
//	constexpr auto CustomTimeDilation = 0x670; // float
//	constexpr auto AutoAttachParent = 0x6c8; // TWeakObjectPtr<USceneComponent>
//	constexpr auto AutoAttachSocketName = 0x6d0; // FName
//	constexpr auto AutoAttachLocationRule = 0x6d4; // EAttachmentRule
//	constexpr auto AutoAttachRotationRule = 0x6d5; // EAttachmentRule
//	constexpr auto AutoAttachScaleRule = 0x6d6; // EAttachmentRule
//	constexpr auto OnSystemFinished = 0x728; // FMulticastInlineDelegate
//}
//
//
//uint64_t Vehicle_state;
//
//
//void definition()
//{
//  Vehicle_state = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
//}
//
//
//void StartSpeedVEH()
//{
//	if (enable_exploit_server)
//	{
//		if (LocalPawn_base)
//		{
//			if (vehicle_speed_exploit)
//			{
//				if (GetAsyncKeyState(VK_SHIFT))
//				{
//					//try 1
//					float read_vehicle = ctx->read_physical_memory<float>(Vehicle_state + Actor::CustomTimeDilation);
//					float read_pawn = ctx->read_physical_memory<float>(LocalPawn_base + Actor::CustomTimeDilation);
//					ctx->write_physical_memory<float>(read_vehicle, 10);
//					ctx->write_physical_memory<float>(read_pawn, 10);
//
//					//try 2
//					float read_vehicle_m2 = ctx->read_physical_memory<float>(Vehicle_state + UParticleSystemComponent::CustomTimeDilation);
//					float read_pawn_m2 = ctx->read_physical_memory<float>(LocalPawn_base + UParticleSystemComponent::CustomTimeDilation);
//					ctx->write_physical_memory<float>(read_vehicle_m2, 10);
//					ctx->write_physical_memory<float>(read_pawn_m2, 10);
//				}
//			}
//		}
//	}
//}


void Boatspeed_07_05_2022()
{
	if (LocalPawn_base)
	{

		if (boat_speed_toggle)
		{
			if (GetAsyncKeyState(VK_SHIFT))
			{

				uint64_t VEHICLE_STATS = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
				ctx->write_physical_memory<float>(VEHICLE_STATS + AFortAthenaVehicle::CachedSpeed, 3);//multiplier run
				//ctx->write_physical_memory<float>(VEHICLE_STATS + 0x25b8, 150);//CacheBoostFX
				//ctx->write_physical_memory<float>(VEHICLE_STATS + 0x1ad4, 150);//BoostSpeedKmh
				//ctx->write_physical_memory<float>(VEHICLE_STATS + 0x1cc, 150);//ReverseToForwardMaxSpeed
				ctx->write_physical_memory<float>(VEHICLE_STATS + AFortAthenaVehicle::TopSpeedCurrentMultiplier, 3);//multiplier run
				ctx->write_physical_memory<float>(VEHICLE_STATS + AFortAthenaVehicle::PushForceCurrentMultiplier, 3);//multiplier run
				ctx->write_physical_memory<float>(VEHICLE_STATS + AFortAthenaVehicle::WaterEffectsVehicleMaxSpeedKmh, 150);//just speed
			}

			//AFortAthenaVehicle::CachedSpeed = 0xc64
			//FortSpaghettiVehicle::CacheBoostFX = 0x23C0
			//AFortAthenaVehicle::TopSpeedCurrentMultiplier = 0x8d8
			//AFortAthenaVehicle::PushForceCurrentMultiplier = 0x8dc
			//FortVehicleConfigs::ReverseToForwardMaxSpeed = 0x1cc
			//FortSpaghettiVehicle::BoostSpeedKmh = 0x18E4
		}
	}
}
