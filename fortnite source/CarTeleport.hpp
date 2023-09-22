#pragma once
namespace Addresses {
	static Vector3 CameraLocation;
	static Vector3 CameraRotation;
}


void test_tp()
{
	uint64_t Vehicle = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
	DWORD_PTR VehicleRootComp = ctx->read_physical_memory<DWORD_PTR>(Vehicle + Actor::RootComponent);
	DWORD_PTR PawnRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Actor::RootComponent);
    Vector3 read_pos = ctx->read_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation);
	auto read_pos_vehcle = ctx->read_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation);
    Vector3 pos_draw = (read_pos.x, read_pos.y, read_pos.z);
	
	//	 static float vehicleflyspeed = 15;

	if (Vehicle)
	{

		if (megachest)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, -47771); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, 38491);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 77);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, -47771);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, 38491);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, -3);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, -47771); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, 38491);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 77);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, -47771);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, 38491);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, -3);
			}
		}

		if (megachestexit)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, -29364); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, 61944);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 6234);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, -29364);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, 61944);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 6159);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, -29364); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, 61944);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 6234);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, -29364);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, 61944);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 6159);
			}
		}


		if (Templechest)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, -18337); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, -8960);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, -670);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, -18337);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, -8960);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, -749);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, -18337); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, -8960);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, -670);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, -18337);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, -8960);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, -749);
			}
		}

		if (Templechest2)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, -19934); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, -9128);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, -670);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, -19934);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, -9128);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, -749);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, -19934); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, -9128);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, -670);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, -19934);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, -9128);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, -749);
			}
		}


		if (Templechestexit)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, -19934); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, -9128);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, -380);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, -19934);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, -9128);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, -380);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, -19934); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, -9128);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, -380);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, -19934);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, -9128);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, -380);
			}
		}


		if (Icechest)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, 65143); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, 32704);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 4693);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, 65143);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, 32704);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 4618);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, 65143); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, 32704);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 4693);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, 65143);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, 32704);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 4618);
			}
		}


		if (Icechestexit)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, 65143); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, 32704);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 5461);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, 65143);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, 32704);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 5461);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, 65143); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, 32704);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 5461);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, 65143);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, 32704);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 5461);
			}
		}

		if (Castlechest)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, 4617); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, 32827);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 1926);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, 4617);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, 32827);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 2007);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, 4617); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, 32827);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 1926);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, 4617);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, 32827);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 2007);
			}
		}

		if (Castlechestexit)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, 2189); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, 33670);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 2747);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, 2189);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, 33670);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 2673);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, 2189); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, 33670);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 2747);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, 2189);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, 33670);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 2673);
			}
		}

		if (Citadellechest)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, 58437); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, -58800);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 4693);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, 58437);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, -58800);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 4618);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, 58437); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, -58800);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 4693);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, 58437);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, -58800);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 4618);
			}
		}

		if (Citadellechestexit)
		{
			if (MouseController::GetAsyncKeyState(0x46))
			{
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, 58437); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, -58800);
				ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 5464);

				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, 58437);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, -58800);
				ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 5390);

				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, 58437); //13214, -62154, 7792
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, -58800);
				ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 5464);

				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, 58437);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, -58800);
				ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 5390);
			}
		}
	}


	 

}



