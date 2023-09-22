
#include "stdafx.hpp"

void crosshairglow()
{
	if (external_def::g_crossh_int)
	{
		if (LocalPawn_base)
		{
	
			DrawLineV2((float)(DriverVar::width / 2), (float)(DriverVar::height / 2) - 8, (float)(DriverVar::width / 2), (float)(DriverVar::height / 2) + 8, IM_COL32(crosshair_r, crosshair_g, crosshair_b, 255), 4);
			DrawLineV2((float)(DriverVar::width / 2) - 8, (float)(DriverVar::height / 2), (float)(DriverVar::width / 2) + 8, (float)(DriverVar::height / 2), IM_COL32(crosshair_r, crosshair_g, crosshair_b, 255), 4);
		}
	
	}

}



void crosshair()
{
	if (external_def::Settings::cross_hair) {
		if (LocalPawn_base)
		{
			
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(DriverVar::width / 2.01f - 14, DriverVar::height / 2), ImVec2(DriverVar::width / 2.01f + 1, DriverVar::height / 2), ImColor(0, 0, 0, 255), 0.5f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(DriverVar::width / 1.99f + 14, DriverVar::height / 2), ImVec2(DriverVar::width / 1.99f + 1, DriverVar::height / 2), ImColor(0, 0, 0, 255), 0.5f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(DriverVar::width / 2, DriverVar::height / 2.01f - 14), ImVec2(DriverVar::width / 2, DriverVar::height / 2.01f), IM_COL32(crosshair_r, crosshair_g, crosshair_b, 255), 0.5f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(DriverVar::width / 2, DriverVar::height / 1.99f + 14), ImVec2(DriverVar::width / 2, DriverVar::height / 1.99f), IM_COL32(crosshair_r, crosshair_g, crosshair_b, 255), 0.5f);
		}
	}

}
float BOG_TO_GRD(float BOG) {
	return (180 / M_PI) * BOG;
}

float GRD_TO_BOG(float GRD) {
	return (M_PI / 180) * GRD;
}
void crosshair_nazi()
{
	if (external_def::Settings::cross_hair_nazi) {
		if (LocalPawn_base)
		{

			POINT Screen; int oodofdfo, jbjfdbdsf;
			Screen.x = GetSystemMetrics(0);
			Screen.y = GetSystemMetrics(1);
			//Middle POINT
			POINT Middle; Middle.x = (int)(Screen.x / 2); Middle.y = (int)(Screen.y / 2);
			int a = (int)(Screen.y / 2 / 30);
			float gamma = atan(a / a);
			external_def::Settings::faken_rot++;
			int Drehungswinkel = external_def::Settings::faken_rot;

			int i = 0;
			while (i < 4)
			{
				std::vector <int> p;
				p.push_back(a * sin(GRD_TO_BOG(Drehungswinkel + (i * 90))));                                    //p[0]        p0_A.x
				p.push_back(a * cos(GRD_TO_BOG(Drehungswinkel + (i * 90))));                                    //p[1]        p0_A.y
				p.push_back((a / cos(gamma)) * sin(GRD_TO_BOG(Drehungswinkel + (i * 90) + BOG_TO_GRD(gamma))));    //p[2]        p0_B.x
				p.push_back((a / cos(gamma)) * cos(GRD_TO_BOG(Drehungswinkel + (i * 90) + BOG_TO_GRD(gamma))));    //p[3]        p0_B.y

				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(Middle.x, Middle.y), ImVec2(Middle.x + p[0], Middle.y - p[1]), IM_COL32(crosshair_r, crosshair_g, crosshair_b, 255));
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(Middle.x + p[0], Middle.y - p[1]), ImVec2(Middle.x + p[2], Middle.y - p[3]), IM_COL32(crosshair_r, crosshair_g, crosshair_b, 255));

				i++;
			}	
		}
	}

}


void Watermark_Product()
{
	ImU32 cc = IM_COL32(cross_r, cross_g, cross_b, 255);
	ImVec2 watermark_size = ImGui::CalcTextSize(("Zartix"));
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ImVec2(watermark_size.x + 13, watermark_size.y + 10), ImColor(0, 0, 0, 100));
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ImVec2(3, watermark_size.y + 10), IM_COL32(cross_r, cross_g, cross_b, 255));
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ImVec2(3, watermark_size.y + 10), IM_COL32(cross_r, cross_g, cross_b, 255));
	ImGui::GetBackgroundDrawList()->AddText(ImVec2(7, 5), ImColor(255, 255, 255), ("Zartix"));

	//ImVec2 watermark_size2 = ImGui::CalcTextSize((const char*)DriverVar::module);
	//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ImVec2(watermark_size2.x + 13, watermark_size2.y + 10), ImColor(0, 0, 0, 100));
	//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ImVec2(3, watermark_size2.y + 10), IM_COL32(cross_r, cross_g, cross_b, 255));
	//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ImVec2(3, watermark_size2.y + 10), IM_COL32(cross_r, cross_g, cross_b, 255));
	//ImGui::GetBackgroundDrawList()->AddText(ImVec2(7, 5), ImColor(255, 255, 255), ((const char*)DriverVar::module));

	//open cheat instruction
	RGBA RGBAColor;
	RGBAColor = Col.silverwhite_;
	if (!menu_key)
	{
		DrawString2(19, 50,110, &RGBAColor, true, true, "Open : F2");
	}
	else
	{
		DrawString2(19, 50, 110, &RGBAColor, true, true, "Close : F2");
	}
}

void notify_game_information()
{

	auto isReloading = ctx->read_physical_memory<bool>(Off_currweapon + FortWeapon::bIsReloadingWeapon);
	auto AmmoCount = ctx->read_physical_memory<int32_t>(Off_currweapon + FortWeapon::AmmoCount);
	auto Crouched = ctx->read_physical_memory<char>(LocalPawn_base + Character::bIsCrouched);
	auto Jumping = ctx->read_physical_memory<char>(LocalPawn_base + FortPawn::bIsJumping);
	if (external_def::bNotify_info)
	{
		/*if (AmmoCount == 0)
		{
			ImGui::InsertNotification({ ImGuiToastType_Warning, 800, "No Ammo !" });
		}*/

		if (isReloading == true)
		{
		//	ImGui::InsertNotification({ImGuiToastType_Info, 800, "Reloading Weapon..."});
			isReloading = NULL;
		}
	

		if (Crouched == 1)
		{
		//	ImGui::InsertNotification({ ImGuiToastType_Info, 800, "Is Crouched" });
			Crouched = NULL;
		}
		if (Jumping == 1)
		{
		//	ImGui::InsertNotification({ ImGuiToastType_Info, 800, "Jumping/Sliding..." });
		}
	}
//	ImGui::RenderNotifications();
}


void get_heure()
{
	time_t currentTime = time(nullptr);

	tm* localTime = localtime(&currentTime);

	char timeText[64];
	sprintf(timeText, "Hours : %02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);


	DrawStrokeText(10, 850, timeText);
}

void get_use_time()
{


	clock_t startTime = clock();
    double elapsedTime = (clock() - startTime) / (double)CLOCKS_PER_SEC;


	char elapsedTimeText[64];
	sprintf(elapsedTimeText, "Delay : %.2f", elapsedTime);



	DrawStrokeText(10, 870, elapsedTimeText);
}

void get_cpu_time()
{
	// Obtention du handle du processus en cours
HANDLE hProcess = GetCurrentProcess();


FILETIME createTime, exitTime, kernelTime, userTime;


GetProcessTimes(hProcess, &createTime, &exitTime, &kernelTime, &userTime);


ULONGLONG kernelTimeNano = kernelTime.dwLowDateTime | ((ULONGLONG)kernelTime.dwHighDateTime << 32);
ULONGLONG userTimeNano = userTime.dwLowDateTime | ((ULONGLONG)userTime.dwHighDateTime << 32);
ULONGLONG totalTimeNano = kernelTimeNano + userTimeNano;

char testor[256];


sprintf(testor, "CPU Usage : %.2f%%\n", (double)totalTimeNano / 10000000.0);

DrawStrokeText(10, 890, testor);
}


void get_usert_name()
{
	const char* username = getenv("USERNAME");

	char usernameText[64];
	sprintf(usernameText, "User : %s", username);

	DrawStrokeText(10, 910, usernameText);
}

void get_version_winver()
{

	char versionText[64];
	sprintf(versionText, "Version du système d'exploitation : %u", (unsigned long)GetProductInfo);
	DrawStrokeText(10, 930, versionText);

}

void enable_use_info()
{
	get_heure();
	get_use_time();
	get_cpu_time();
	get_usert_name();
	get_version_winver();
	//char gay[64];
	//sprintf_s(gay, ("FOV: %.f\n"), pov_init);
	//DrawStrokeText(10, 960, gay);

	/*char fovqword[64];
	sprintf_s(fovqword, ("Pointer: %i\n"), value_fov_pointer);
	DrawStrokeText(10, 980, fovqword);

	char angleqword[64];
	sprintf_s(angleqword, ("Angle: %i\n"), value_fov_pointer_angle);
	DrawStrokeText(10, 1000, angleqword);*/

	uint64_t Vehicle = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
	DWORD_PTR VehicleRootComp = ctx->read_physical_memory<DWORD_PTR>(Vehicle + Actor::RootComponent);
	DWORD_PTR PawnRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Actor::RootComponent);
	Vector3 read_pos = ctx->read_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation);
	auto read_pos_vehcle = ctx->read_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation);
	
	Vector3 pos_draw = (read_pos.x, read_pos.y, read_pos.z);
	char gay[255];
	sprintf_s(gay, ("player pos: %0.0f, %0.0f, %0.0f\n"), read_pos.x, read_pos.y, read_pos.z);
	DrawStrokeText(10, 960, gay);

	char gay2[255];
	sprintf_s(gay2, ("car pos: %0.0f, %0.0f, %0.0f\n"), read_pos_vehcle.x, read_pos_vehcle.y, read_pos_vehcle.z);
	DrawStrokeText(10, 980, gay2);
	ImGui::GetBackgroundDrawList()->AddText(ImVec2(1, 20), ImColor(255, 255, 0), gay);
}