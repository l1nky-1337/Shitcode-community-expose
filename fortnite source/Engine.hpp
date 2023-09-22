#ifndef ENGINE_HPP
#define ENGINE_HPP
bool Visible;
void draw_eso()
{
#pragma once
	RGBA Fov = { colors::fov[0] * 255, colors::fov[1] * 255, colors::fov[2] * 255, 255 };
	RGBA Fovv = { colors::fovv[0] * 0, colors::fovv[1] * 0, colors::fovv[2] * 0, 0 };
	RGBA invisible = { colors::invisible[0] * 255, colors::invisible[1] * 255, colors::invisible[2] * 255, 255 };
	RGBA visible = { colors::visible[0] * 255, colors::visible[1] * 255, colors::visible[2] * 255, 255 };
	RGBA RGBAColor;
	float distance = 0.0;

	_QWORD PawnMesh = ctx->read_physical_memory<_QWORD>(LocalPawn_base + Character::Mesh);
	Vector3 pLocalPosition = GetBoneWithRotation(PawnMesh, 108);



	for (int i = 0; i < itemList.size(); ++i)
	{
		auto entity = itemList[i];
		auto ItemRoot = ctx->read_physical_memory<_QWORD>(entity.actor + Actor::RootComponent);
		auto ItemLocation = ctx->read_physical_memory<Vector3>(ItemRoot + SceneComponent::RelativeLocation);

		if (pLocalPosition.x != 0.f)
		{
			distance = pLocalPosition.Distance(ItemLocation) / 360;
		}

		if (distance < visuals::ItemDistance)
		{
			auto bWTier = entity.bWTier;
			auto ItemName = entity.ItemName.c_str();

			auto ItemScreenPos = ProjectWorldToScreen(ItemLocation);




			if (visuals::items)
			{
				if (bWTier == 2 && (items::UnCommon))
				{
					// Récupération de la position relative de l'élément
					Vector3 relativeLocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);

					// Calcul de la distance entre le joueur et l'élément
					float distance = pLocalPosition.Distance(relativeLocation) / 100;

					// Définition de la taille de l'élément en fonction de la distance
					float itemSize = std::fmaxf(10.0f, 500.0f / distance);

					// Calcul de la position de l'élément à afficher à l'écran en fonction de la distance
					ImVec2 itemScreenPos = ImVec2(ItemScreenPos.x, ItemScreenPos.y - 135 - itemSize);

					// Affichage de l'élément à l'écran
					RGBAColor = Col.darkgreen_;
					sprintf(drawBuff, "Name : %s\nDist : %0.fm\0", ItemName, distance);
					DrawString2(itemSize, ItemScreenPos.x, itemScreenPos.y, &RGBAColor, true, true, drawBuff);
					ImVec2 textSize = ImGui::CalcTextSize(drawBuff);
					//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(itemScreenPos.x - textSize.x / 2.5, itemScreenPos.y - textSize.y), ImVec2(itemScreenPos.x + textSize.x / 4.0, itemScreenPos.y), IM_COL32(0, 0, 0, 75));
				}
				else if ((bWTier == 3) && (items::rare))
				{
					// Récupération de la position relative de l'élément
					Vector3 relativeLocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);

					// Calcul de la distance entre le joueur et l'élément
					float distance = pLocalPosition.Distance(relativeLocation) / 100;

					// Définition de la taille de l'élément en fonction de la distance
					float itemSize = std::fmaxf(10.0f, 500.0f / distance);

					// Calcul de la position de l'élément à afficher à l'écran en fonction de la distance
					ImVec2 itemScreenPos = ImVec2(ItemScreenPos.x, ItemScreenPos.y - 135 - itemSize);

					// Affichage de l'élément à l'écran
					RGBAColor = Col.blue;
					sprintf(drawBuff, "Name : %s\nDist : %0.fm\0", ItemName, distance);
					DrawString2(itemSize, ItemScreenPos.x, itemScreenPos.y, &RGBAColor, true, true, drawBuff);
					ImVec2 textSize = ImGui::CalcTextSize(drawBuff);
					//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(itemScreenPos.x - textSize.x / 2.5, itemScreenPos.y - textSize.y), ImVec2(itemScreenPos.x + textSize.x / 4.0, itemScreenPos.y), IM_COL32(0, 0, 0, 75));
				}
				else if ((bWTier == 4) && (items::purple))
				{
					// Récupération de la position relative de l'élément
					Vector3 relativeLocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);

					// Calcul de la distance entre le joueur et l'élément
					float distance = pLocalPosition.Distance(relativeLocation) / 100;

					// Définition de la taille de l'élément en fonction de la distance
					float itemSize = std::fmaxf(10.0f, 500.0f / distance);

					// Calcul de la position de l'élément à afficher à l'écran en fonction de la distance
					ImVec2 itemScreenPos = ImVec2(ItemScreenPos.x, ItemScreenPos.y - 135 - itemSize);

					// Affichage de l'élément à l'écran
					RGBAColor = Col.pinks_;
					sprintf(drawBuff, "Name : %s\nDist : %0.fm\0", ItemName, distance);
					DrawString2(itemSize, ItemScreenPos.x, itemScreenPos.y, &RGBAColor, true, true, drawBuff);
					ImVec2 textSize = ImGui::CalcTextSize(drawBuff);
					//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(itemScreenPos.x - textSize.x / 2.5, itemScreenPos.y - textSize.y), ImVec2(itemScreenPos.x + textSize.x / 4.0, itemScreenPos.y), IM_COL32(0, 0, 0, 75));
				}
				else if ((bWTier == 5) && (items::gold))
				{
					// Récupération de la position relative de l'élément
					Vector3 relativeLocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);

					// Calcul de la distance entre le joueur et l'élément
					float distance = pLocalPosition.Distance(relativeLocation) / 100;

					// Définition de la taille de l'élément en fonction de la distance
					float itemSize = std::fmaxf(10.0f, 500.0f / distance);

					// Calcul de la position de l'élément à afficher à l'écran en fonction de la distance
					ImVec2 itemScreenPos = ImVec2(ItemScreenPos.x, ItemScreenPos.y - 135 - itemSize);

					// Affichage de l'élément à l'écran
					RGBAColor = Col.orange;
					sprintf(drawBuff, "Name : %s\nDist : %0.fm\0", ItemName, distance);
					DrawString2(itemSize, ItemScreenPos.x, itemScreenPos.y, &RGBAColor, true, true, drawBuff);
					ImVec2 textSize = ImGui::CalcTextSize(drawBuff);
					//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(itemScreenPos.x - textSize.x / 2.5, itemScreenPos.y - textSize.y), ImVec2(itemScreenPos.x + textSize.x / 4.0, itemScreenPos.y), IM_COL32(0, 0, 0, 75));
				}
				else if ((bWTier == 6) && (items::mythic))
				{
					// Récupération de la position relative de l'élément
					Vector3 relativeLocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);

					// Calcul de la distance entre le joueur et l'élément
					float distance = pLocalPosition.Distance(relativeLocation) / 100;

					// Définition de la taille de l'élément en fonction de la distance
					float itemSize = std::fmaxf(10.0f, 500.0f / distance);

					// Calcul de la position de l'élément à afficher à l'écran en fonction de la distance
					ImVec2 itemScreenPos = ImVec2(ItemScreenPos.x, ItemScreenPos.y - 135 - itemSize);

					// Affichage de l'élément à l'écran
					RGBAColor = Col.yellow;
					sprintf(drawBuff, "Name : %s\nDist : %0.fm\0", ItemName, distance);
					DrawString2(itemSize, ItemScreenPos.x, itemScreenPos.y, &RGBAColor, true, true, drawBuff);
					ImVec2 textSize = ImGui::CalcTextSize(drawBuff);
					//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(itemScreenPos.x - textSize.x / 2.5, itemScreenPos.y - textSize.y), ImVec2(itemScreenPos.x + textSize.x / 4.0, itemScreenPos.y), IM_COL32(0, 0, 0, 75));
				}
				else if ((bWTier == 0) || (bWTier == 1) && (items::Common))
				{
					// Récupération de la position relative de l'élément
					Vector3 relativeLocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);

					// Calcul de la distance entre le joueur et l'élément
					float distance = pLocalPosition.Distance(relativeLocation) / 100;

					// Définition de la taille de l'élément en fonction de la distance
					float itemSize = std::fmaxf(10.0f, 500.0f / distance);

					// Calcul de la position de l'élément à afficher à l'écran en fonction de la distance
					ImVec2 itemScreenPos = ImVec2(ItemScreenPos.x, ItemScreenPos.y - 135 - itemSize);

					// Affichage de l'élément à l'écran
					RGBAColor = Col.silverwhite_;
					sprintf(drawBuff, "Name : %s\nDist : %0.fm\0", ItemName, distance);
					DrawString2(itemSize, ItemScreenPos.x, itemScreenPos.y, &RGBAColor, true, true, drawBuff);
					ImVec2 textSize = ImGui::CalcTextSize(drawBuff);
					//ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(itemScreenPos.x - textSize.x / 2.5, itemScreenPos.y - textSize.y), ImVec2(itemScreenPos.x + textSize.x / 4.0, itemScreenPos.y), IM_COL32(0, 0, 0, 75));
				}
			}

			//Vector3 ChestPosition;
			//ChestPosition = ProjectWorldToScreen(ItemLocation);
			//Vector3 VehiclePosition = ProjectWorldToScreen(ItemLocation);
			//if (strstr(entity.ItemName.c_str(), ("Tiered_Chest")) && visuals::chest)
			//{
			//	if (distance < visuals::ItemDistance) {

			//		std::string Text = NULL + ("Chest [") + std::to_string((int)visuals::ItemDistance) + ("m]");
			//		DrawString(14, ChestPosition.x, ChestPosition.y, true, true, Text.c_str());
			//	}
			//}

			//else if (visuals::animal)
			//{
			//	if ((strstr(entity.ItemName.c_str(), ("NPC_Pawn_Irwin_Predator_Robert_C")) || strstr(entity.ItemName.c_str(), ("NPC_Pawn_Irwin_Prey_Burt_C")) || strstr(entity.ItemName.c_str(), ("NPC_Pawn_Irwin_Simple_Smackie_C")) || strstr(entity.ItemName.c_str(), ("NPC_Pawn_Irwin_Simple_Smackie_C")) || strstr(entity.ItemName.c_str(), ("NPC_Pawn_Irwin_Prey_Nug_C")) || strstr(entity.ItemName.c_str(), ("NPC_Pawn_Irwin_Predator_Grandma_C")) || strstr(entity.ItemName.c_str(), ("NPC_Pawn_Irwin_Simple_Avian_Crow_C")))) {
			//		if (distance < visuals::ItemDistance) {

			//			std::string Text = NULL + ("Animal [") + std::to_string((int)visuals::ItemDistance) + ("m]");
			//			DrawString(14, VehiclePosition.x, VehiclePosition.y, true, true, Text.c_str());
			//		}
			//	}
			//}


			//if (strstr(entity.ItemName.c_str(), ("AthenaPlayerMarker_WithCustomization")))
			//{
			//	if (distance < visuals::ItemDistance) {

			//		std::string Text = NULL + ("Marker [") + std::to_string((int)visuals::ItemDistance) + ("m]");
			//		DrawString(14, ChestPosition.x, ChestPosition.y, true, true, Text.c_str());
			//	}
			//}



			////
			//else if (visuals::VehicleEsp)
			//{
			//	if (strstr(entity.ItemName.c_str(), ("MeatballVehicle_L_C")) || strstr(entity.ItemName.c_str(), ("Valet_SportsC")) || strstr(entity.ItemName.c_str(), ("Valet_BigRig")) || strstr(entity.ItemName.c_str(), ("Vehicl")) || strstr(entity.ItemName.c_str(), ("Valet_BasicC")) || strstr(entity.ItemName.c_str(), ("Valet_BasicTr")) || strstr(entity.ItemName.c_str(), ("Valet_Taxi"))) {
			//		if (distance < visuals::ItemDistance) {

			//			std::string Text = NULL + ("Vehicle [") + std::to_string((int)visuals::ItemDistance) + ("m]");
			//			DrawString(14, VehiclePosition.x, VehiclePosition.y, true, true, Text.c_str());

			//		}
			//	}
			//}

		}
	}
	
	

	//for (LootEntity LEntityList : LootentityList) {

	//	if (LocalPawn_base)
	//	{
	//		uintptr_t ItemRootComponent = ctx->read_physical_memory<uintptr_t>(LEntityList.ACurrentItem + Actor::RootComponent);
	//		Vector3 ItemPosition = ctx->read_physical_memory<Vector3>(ItemRootComponent + SceneComponent::RelativeLocation);
	//		float ItemDist = pLocalPosition.Distance(ItemPosition) / 100.f;
	//		if (ItemDist < visuals::ItemDistance)
	//		{

	//			std::string null = ("");
	//			auto IsSearched = ctx->read_physical_memory<BYTE>((uintptr_t)LEntityList.ACurrentItem + 0x101a);
	//			if (IsSearched >> 7 & 1) continue;

	//			Vector3 ChestPosition;
	//			ChestPosition = ProjectWorldToScreen(ItemPosition);
	//			Vector3 VehiclePosition = ProjectWorldToScreen(ItemPosition);
	//			if (strstr(LEntityList.GNames.c_str(), ("Tiered_Chest")) && visuals::chest)
	//			{
	//				if (ItemDist < visuals::ItemDistance) {

	//					std::string Text = null + ("Chest [") + std::to_string((int)ItemDist) + ("m]");
	//					DrawString(14, ChestPosition.x, ChestPosition.y, true, true, Text.c_str());
	//				}
	//			}

	//			else if (visuals::animal)
	//			{
	//				if (strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Predator_Robert_C")) || strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Prey_Burt_C")) || strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Simple_Smackie_C")) || strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Simple_Smackie_C")) || strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Prey_Nug_C")) || strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Predator_Grandma_C")) || strstr(LEntityList.GNames.c_str(), ("NPC_Pawn_Irwin_Simple_Avian_Crow_C"))) {
	//					if (ItemDist < visuals::ItemDistance) {

	//						std::string Text = null + ("Animal [") + std::to_string((int)ItemDist) + ("m]");
	//						DrawString(14, VehiclePosition.x, VehiclePosition.y, true, true, Text.c_str());
	//					}
	//				}
	//			}


	//			if (strstr(LEntityList.GNames.c_str(), ("AthenaPlayerMarker_WithCustomization")))
	//			{
	//				if (ItemDist < 500) {

	//					std::string Text = null + ("Marker [") + std::to_string((int)ItemDist) + ("m]");
	//					DrawString(14, ChestPosition.x, ChestPosition.y, true, true, Text.c_str());
	//				}
	//			}



	//			//
	//			else if (visuals::VehicleEsp)
	//			{
	//				if (strstr(LEntityList.GNames.c_str(), ("MeatballVehicle_L_C")) || strstr(LEntityList.GNames.c_str(), ("Valet_SportsC")) || strstr(LEntityList.GNames.c_str(), ("Valet_BigRig")) || strstr(LEntityList.GNames.c_str(), ("Vehicl")) || strstr(LEntityList.GNames.c_str(), ("Valet_BasicC")) || strstr(LEntityList.GNames.c_str(), ("Valet_BasicTr")) || strstr(LEntityList.GNames.c_str(), ("Valet_Taxi"))) {
	//					if (ItemDist < visuals::ItemDistance) {

	//						std::string Text = null + ("Vehicle [") + std::to_string((int)ItemDist) + ("m]");
	//						DrawString(14, VehiclePosition.x, VehiclePosition.y, true, true, Text.c_str());

	//					}
	//				}
	//			}
	//		}
	//	}
	//}






		if (LocalPawn_base)
		{
			if (closestPawn != 0)
			{
				if (aimbot::aimbot && closestPawn && MouseController::GetAsyncKeyState(hotkeys::aimkey) or Controller::IsPressingLeftTrigger())
				{
					targetlocked = true;
					Visible = true;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;


					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot::aimfov)) {
							if (Distance <= aimbot::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
								move_to(rootHeadOut.x, rootHeadOut.y);
							}

						}
					}
				}
				else
				{
					isaimbotting = false;
					targetlocked = false;
					Visible = false;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;

					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot::aimfov)) {
							if (Distance <= aimbot::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
							}
						}
					}
					closestDistance = FLT_MAX;
					closestPawn = NULL;
				}
				if (aimbot2::aimbot && closestPawn && MouseController::GetAsyncKeyState(hotkeys2::aimkey2) or Controller::IsPressingLeftTrigger())
				{
					targetlocked = true;
					Visible = true;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;


					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot2::aimfov)) {
							if (Distance <= aimbot2::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
								move_to(rootHeadOut.x, rootHeadOut.y);
							}

						}
					}
				}
				else
				{
					isaimbotting = false;
					targetlocked = false;
					Visible = false;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;

					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot2::aimfov)) {
							if (Distance <= aimbot2::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
							}
						}
					}
					closestDistance = FLT_MAX;
					closestPawn = NULL;
				}
				if (aimbot3::aimbot && closestPawn && MouseController::GetAsyncKeyState(hotkeys3::aimkey3) or Controller::IsPressingLeftTrigger())
				{
					targetlocked = true;
					Visible = true;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;


					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot3::aimfov)) {
							if (Distance <= aimbot3::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
								move_to(rootHeadOut.x, rootHeadOut.y);
							}
						}
					}
				}
				else
				{
					isaimbotting = false;
					targetlocked = false;
					Visible = false;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;

					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot3::aimfov)) {
							if (Distance <= aimbot3::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
							}
						}
					}
					closestDistance = FLT_MAX;
					closestPawn = NULL;
				}
				if (aimbot4::aimbot && closestPawn && MouseController::GetAsyncKeyState(hotkeys4::aimkey4) or Controller::IsPressingLeftTrigger())
				{
					targetlocked = true;
					Visible = true;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;


					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot4::aimfov)) {
							if (Distance <= aimbot4::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
								move_to(rootHeadOut.x, rootHeadOut.y);
							}
						}
					}
				}
				else
				{
					isaimbotting = false;
					targetlocked = false;
					Visible = false;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;

					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot4::aimfov)) {
							if (Distance <= aimbot4::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
							}
						}
					}
					closestDistance = FLT_MAX;
					closestPawn = NULL;
				}
				if (aimbot5::aimbot && closestPawn && MouseController::GetAsyncKeyState(hotkeys5::aimkey5) or Controller::IsPressingLeftTrigger())
				{
					targetlocked = true;
					Visible = true;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;

					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot5::aimfov)) {
							if (Distance <= aimbot5::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
								move_to(rootHeadOut.x, rootHeadOut.y);
							}
						}
					}
				}
				else
				{
					isaimbotting = false;
					targetlocked = false;
					Visible = false;

					_QWORD currentactormesh = ctx->read_physical_memory<_QWORD>(closestPawn + Character::Mesh);
					auto rootHead = GetBoneWithRotation(currentactormesh, select_hitbox());
					Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

					_QWORD rootcomponent = ctx->read_physical_memory<_QWORD>(closestPawn + Actor::RootComponent);
					Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
					float Distance = pLocalPosition.Distance(Relativelocation) / 100;

					if (rootHeadOut.x != 0 || rootHeadOut.y != 0) {
						if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, DriverVar::width / 2, DriverVar::height / 2) <= aimbot5::aimfov)) {
							if (Distance <= aimbot5::aimdistance) {
								DrawLine(DriverVar::width / 2, DriverVar::height / 2, rootHeadOut.x, rootHeadOut.y, IM_COL32(cross_r, cross_g, cross_b, 128), 1.f);
							}
						}
					}

					closestDistance = FLT_MAX;
					closestPawn = NULL;
				}
				
			}
		}
	}
#endif

