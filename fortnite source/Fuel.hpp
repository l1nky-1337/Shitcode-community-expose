//#pragma once
//#include "stdafx.hpp"
//
//namespace VariableServerExploit {
//	uint64_t Vehicle;
//	bool DisableTimeFuel;
//}
//namespace UFortVehicleFuelComponent
//{
//	constexpr auto OnFuelChanged = 0xa8; // FMulticastInlineDelegate
//	constexpr auto OnRefueledFromEmpty = 0xb8; // FMulticastInlineDelegate
//	constexpr auto OnOutOfFuel = 0xc8; // FMulticastInlineDelegate
//	constexpr auto OnLowFuel = 0xd8; // FMulticastInlineDelegate
//	constexpr auto OwnerVehicle = 0xe8; // AFortAthenaVehicle*
//	constexpr auto ServerFuel = 0xf0; // float
//	constexpr auto OutOfFuelSound = 0xf8; // USoundBase*
//	constexpr auto LowFuelSound = 0x100; // USoundBase*
//	constexpr auto LowFuelRepeatingPing = 0x108; // USoundBase*
//	constexpr auto UsesFuelSystem = 0x110; // FScalableFloat
//	constexpr auto InitializeWithStartingFuel = 0x138; // FScalableFloat
//	constexpr auto FuelTankCapacity = 0x160; // FScalableFloat
//	constexpr auto FuelPerSecondIdle = 0x188; // FScalableFloat
//	constexpr auto FuelPerSecondDriving = 0x1b0; // FScalableFloat
//	constexpr auto FuelPerSecondBoosting = 0x1d8; // FScalableFloat
//	constexpr auto MinFuelAtSpawn = 0x210; // FScalableFloat
//	constexpr auto MaxFuelAtSpawn = 0x238; // FScalableFloat
//	constexpr auto InfiniteFuel = 0x260; // FScalableFloat
//	constexpr auto LowFuelRepeatingPingDelay = 0x288; // FScalableFloat
//	constexpr auto LowFuelPercent = 0x2b0; // FScalableFloat
//	constexpr auto CustomFuelUI = 0x2d8; // TArray<FVehicleSpecificUIDetails>
//	constexpr auto FuelSubText = 0x2e8; // FText
//	constexpr auto FuelSubTextImage = 0x300; // TSoftObjectPtr<UTexture2D>
//}
//namespace InitTable {
//	//init all
//	void InitFunction()
//	{
//		if (enable_exploit_server)
//		{
//			VariableServerExploit::Vehicle = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
//		}
//	}
//}
//
//namespace VehicleExploit_hook {
//	//Infinity Fuel
//	void infinity_fuel()
//	{
//		if (enable_exploit_server)
//		{
//			if (VariableServerExploit::DisableTimeFuel)
//			{
//				if (LocalPawn_base)
//				{
//					auto EssenceCheck = ctx->read_physical_memory<uintptr_t>(VariableServerExploit::Vehicle + FortAthenaVehicle::CachedFuelComponent);
//					ctx->write_physical_memory<float>(EssenceCheck + UFortVehicleFuelComponent::ServerFuel, 500000.f);
//				}
//			}
//		}
//	}
//}