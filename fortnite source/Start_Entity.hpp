#ifndef START_ENTITY_HPP
#define START_ENTITY_HPP
#pragma once
#include <stdafx.hpp>
char* drawBuff = (char*)malloc(4096);
char* wchar_to_char(const wchar_t* pwchar)
{
	int currentCharIndex = 0;
	char currentChar = pwchar[currentCharIndex];

	while (currentChar != '\0')
	{
		currentCharIndex++;
		currentChar = pwchar[currentCharIndex];
	}

	const int charCount = currentCharIndex + 1;

	char* filePathC = (char*)malloc(sizeof(char) * charCount);

	for (int i = 0; i < charCount; i++)
	{
		char character = pwchar[i];

		*filePathC = character;

		filePathC += sizeof(char);

	}
	filePathC += '\0';

	filePathC -= (sizeof(char) * charCount);

	return filePathC;
}


void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness) {
	float lineW = (W / 3);
	float lineH = (H / 3);

	//corners
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}






void pre_start_ploop()
{
	RGBA Fov = { colors::fov[0] * 255, colors::fov[1] * 255, colors::fov[2] * 255, 255 };
	RGBA Fovv = { colors::fovv[0] * 0, colors::fovv[1] * 0, colors::fovv[2] * 0, 0 };
	RGBA invisible = { colors::invisible[0] * 255, colors::invisible[1] * 255, colors::invisible[2] * 255, 255 };
	RGBA visible = { colors::visible[0] * 255, colors::visible[1] * 255, colors::visible[2] * 255, 255 };
	RGBA RGBAColor;
	float distance = 0.0;
	bool Visible;

	for (int i = 0; i < EntityList.size(); i++)
	{
		
		auto entity = EntityList[i];

		auto actor = entity.actor;
		if (!entity.actor) {
			continue;
		}
		auto mesh = entity.mesh;
		auto type = entity.type;
		auto currweapon = entity.currweapon;
		auto playerstate = entity.playerstate;


		Visible = isVisible(mesh); 
		auto nukr = GetBoneWithRotation(mesh, 7);
		auto foot = GetBoneWithRotation(mesh, 0);
		auto head = GetBoneWithRotation(mesh, 68);

		auto left_hand_top = GetBoneWithRotation(mesh, 33);
		auto left_hand_bottom = GetBoneWithRotation(mesh, 15);

		auto right_hand_top = GetBoneWithRotation(mesh, 62);
		auto right_hand_bottom = GetBoneWithRotation(mesh, 56);

		auto left_foot_top = GetBoneWithRotation(mesh, 73);
		auto left_foot_bottom = GetBoneWithRotation(mesh, 35); //or 76

		auto right_foot_top = GetBoneWithRotation(mesh, 80);
		auto right_foot_bottom = GetBoneWithRotation(mesh, 83);

		auto player_screen = ProjectWorldToScreen(head);
		auto player_screen_2 = ProjectWorldToScreen(foot);
		auto head_screen = ProjectWorldToScreen(Vector3(head.x, head.y, head.z));
		Vector3 Headbox = ProjectWorldToScreen(Vector3(head.x, head.y, head.z + 15));
		auto normal_head = ProjectWorldToScreen(head);
		auto Itemdef = ctx->read_physical_memory<_QWORD>(currweapon + FortWeapon::WeaponData);
		auto isReloading = ctx->read_physical_memory<bool>(currweapon + FortWeapon::bIsReloadingWeapon);
		auto AmmoCount = ctx->read_physical_memory<int32_t>(currweapon + FortWeapon::AmmoCount);
		auto CrouchingActoVar = ctx->read_physical_memory<bool>(entity.actor + Character::bIsCrouched);
		auto bIsParashuteOpen = ctx->read_physical_memory<bool>(entity.actor + FortPlayerPawn::bIsParachuteOpen);
		auto AimingWeap = ctx->read_physical_memory<bool>(currweapon + FortWeapon::bIsTargeting);
		auto WeaponID = ctx->read_physical_memory<int32>(Itemdef + 0x18);
		auto TeamNumber = ctx->read_physical_memory<char>(playerstate + FortPlayerStateAthena::TeamIndex);

		auto rootcomponent = ctx->read_physical_memory<_QWORD>(entity.actor + Actor::RootComponent);
		auto root_position = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
		auto IsABot = ctx->read_physical_memory<char>(playerstate + 0x292 & 0x8); //AIinfo (isabot 'char')
			
	
		if (head.z <= root_position.z) {
			continue;
		}
		uint64_t PawnMesh = ctx->read_physical_memory<uint64_t>(LocalPawn_base + Character::Mesh);
		Vector3 pLocalPosition = GetBoneWithRotation(PawnMesh, 108);
		if (_isnanf(pLocalPosition.x) || _isnanf(pLocalPosition.y) || _isnanf(pLocalPosition.z))
		{
			pLocalPosition = { 0.f, 0.f, 0.f };
		}
		if (pLocalPosition.x!= 0.f)
		{
			distance = pLocalPosition.Distance(foot) / 360;
		}

		auto local_Itemdef = ctx->read_physical_memory<_QWORD>(Off_currweapon + FortWeapon::WeaponData);
		auto pawnWeaponID = ctx->read_physical_memory<int32>(local_Itemdef + 0x18);
		std::string pObjName = GetNameByIndex(pawnWeaponID);
		std::string pObjNamee = GetNameByIndex(WeaponID);

		auto dx = normal_head.x - (DriverVar::width / 2);
		auto dy = normal_head.y - (DriverVar::height / 2);
		auto dist = sqrtf(dx * dx + dy * dy);

		bool bIsCrouched = ctx->read_physical_memory<bool>(LocalPawn_base + Character::bIsCrouched);
		bool bIsTargeting = ctx->read_physical_memory<bool>(Off_currweapon + FortWeapon::bIsTargeting);

		float BoxHeight = player_screen.y - head_screen.y;
		float BoxWidth = BoxHeight * 1.80;
		Vector3 bottom = ProjectWorldToScreen(foot);
		float CornerHeight = abs(Headbox.y - bottom.y);
		float CornerWidth = CornerHeight * boxsize;
		float yOffset = 15.0f;
		//ctx->write_physical_memory<char>(mesh + 0x88, 0xff);
		

		
			RGBA box{ Visible ? visible : invisible };
		
			
				if (aimbot::fovcircle) {
					DrawCirclev2(ImGui::GetIO().DisplaySize.x / 2.f, ImGui::GetIO().DisplaySize.y / 2.f, aimbot::aimfov, IM_COL32(cross_r, cross_g, cross_b, 128), 360);
				}

			

			//if (bIsCrouched)
			//	aimbot::hipfire = aimbot::hipfire;
			//else
			//	aimbot::aimspeed = aimbot::aimspeed;
	
			//if (!external_def::Settings::fovCircleByAngle)
			//{
			//	if (bIsTargeting)
			//		aimbot::adsfov = aimbot::adsfov;
			//	else
			//		aimbot::aimfov = aimbot::aimfov;
			//}
		
				if (tpbullet or tp_players)
				{
					closestDistance = 80;
					closestPawnExploit = entity.actor;
				}
			
			if (aimbot::aimbot)
			{
			  
					if (dist < aimbot::aimfov && dist < closestDistance && targetlocked == false && Visible) {

						if (distance <= aimbot::aimdistance)
						{
							closestDistance = dist;
							closestPawn = entity.actor;
						}

					}
				
				
			}

		
				
	
				if (visuals::skeleton)
				{
					float distance_modifier = pLocalPosition.Distance(foot) * 0.001F;
					DrawCircle(normal_head.x, normal_head.y, 10 / distance_modifier, IM_COL32(cross_r, cross_g, cross_b, 255), 100);

					DrawBone(mesh, Col.white, 3);
				}
			


				if (distance < visuals::MaxDistance)
				{

					radarFlex();


					if (external_def::g_3d_box)
					{

						if (head.x != 0 || head.y != 0 || head.z != 0)
						{
							ImU32 Colorsimple, Colordouble;

							if (box_color)
							{
								if (Visible)
									Colorsimple = IM_COL32(box_r, box_g, box_b, 255);

								else if (!Visible)


									Colorsimple = IM_COL32(255, 255, 255, 255);

								if (Visible)
									Colordouble = IM_COL32(box_g, box_b, box_r, 255);
								else
									Colordouble = IM_COL32(255, 255, 255, 255);

							}
							else
							{
								if (Visible)
									Colorsimple = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);

								else if (!Visible)


									Colorsimple = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);

								if (Visible)
									Colordouble = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);
								else
									Colordouble = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);
							}

							//box simple
							Vector3 bottom1 = ProjectWorldToScreen(Vector3(foot.x + 50, foot.y - 50, foot.z));
							Vector3 bottom2 = ProjectWorldToScreen(Vector3(foot.x - 50, foot.y - 50, foot.z));
							Vector3 bottom3 = ProjectWorldToScreen(Vector3(foot.x - 50, foot.y + 50, foot.z));
							Vector3 bottom4 = ProjectWorldToScreen(Vector3(foot.x + 50, foot.y + 50, foot.z));

							Vector3 top1 = ProjectWorldToScreen(Vector3(head.x + 50, head.y - 50, head.z + 15));
							Vector3 top2 = ProjectWorldToScreen(Vector3(head.x - 50, head.y - 50, head.z + 15));
							Vector3 top3 = ProjectWorldToScreen(Vector3(head.x - 50, head.y + 50, head.z + 15));
							Vector3 top4 = ProjectWorldToScreen(Vector3(head.x + 50, head.y + 50, head.z + 15));

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), Colordouble, thickness::box_thick);



							/*	ImVec2 corners2d[8];
								corners2d[0] = ImVec2(Headbox.x - CornerWidth, Headbox.y - CornerHeight);
								corners2d[1] = ImVec2(Headbox.x + CornerWidth, Headbox.y - CornerHeight);
								corners2d[2] = ImVec2(Headbox.x - CornerWidth, Headbox.y + CornerHeight);
								corners2d[3] = ImVec2(Headbox.x + CornerWidth, Headbox.y + CornerHeight);
								corners2d[4] = ImVec2(corners2d[0].x, corners2d[0].y + 2 * CornerHeight);
								corners2d[5] = ImVec2(corners2d[1].x, corners2d[1].y + 2 * CornerHeight);
								corners2d[6] = ImVec2(corners2d[2].x, corners2d[2].y - 2 * CornerHeight);
								corners2d[7] = ImVec2(corners2d[3].x, corners2d[3].y - 2 * CornerHeight);
								draw_corners(corners2d, 1.0f, Colorsimple);
		*/

						}

					}

					if (external_def::g_buried)
					{


						ImU32 Colordouble, blacknigger;

						if (box_color)
						{


							if (Visible)
								Colordouble = IM_COL32(box_r, box_g, box_b, 255);
							else
								Colordouble = IM_COL32(255, 255, 255, 255);

						}
						else
						{




							if (Visible)
								Colordouble = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);
							else
								Colordouble = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);
						}
						blacknigger = IM_COL32(0, 0, 0, 255);

						DrawCornerBox(Headbox.x - CornerWidth / 2 + 1, Headbox.y, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawCornerBox(Headbox.x - CornerWidth / 2 - 1, Headbox.y, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawCornerBox(Headbox.x - CornerWidth / 2, Headbox.y + 1, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawCornerBox(Headbox.x - CornerWidth / 2, Headbox.y - 1, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawCornerBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, thickness::box_thick, Colordouble);



					}

					if (external_def::filled_box)
					{


						ImU32 Colordouble, blacknigger;

						if (box_color)
						{


							if (Visible)
								Colordouble = IM_COL32(box_r, box_g, box_b, 255);
							else
								Colordouble = IM_COL32(255, 255, 255, 255);

						}
						else
						{




							if (Visible)
								Colordouble = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);
							else
								Colordouble = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);
						}
						blacknigger = IM_COL32(0, 0, 0, 255);


						DrawNormalBox_filled(Headbox.x - CornerWidth / 2 + 1, Headbox.y, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawNormalBox_filled(Headbox.x - CornerWidth / 2 - 1, Headbox.y, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawNormalBox_filled(Headbox.x - CornerWidth / 2, Headbox.y + 1, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawNormalBox_filled(Headbox.x - CornerWidth / 2, Headbox.y - 1, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawNormalBox_filled(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, thickness::box_thick, Colordouble);


					}

					if (external_def::Esp_box)
					{


						ImU32 Colordouble, blacknigger;

						if (box_color)
						{


							if (Visible)
								Colordouble = IM_COL32(box_r, box_g, box_b, 255);
							else
								Colordouble = IM_COL32(255, 255, 255, 255);

						}
						else
						{




							if (Visible)
								Colordouble = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);
							else
								Colordouble = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);
						}
						blacknigger = IM_COL32(0, 0, 0, 255);
						DrawNormalBox(Headbox.x - CornerWidth / 2 + 1, Headbox.y, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawNormalBox(Headbox.x - CornerWidth / 2 - 1, Headbox.y, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawNormalBox(Headbox.x - CornerWidth / 2, Headbox.y + 1, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawNormalBox(Headbox.x - CornerWidth / 2, Headbox.y - 1, CornerWidth, CornerHeight, 1.1, blacknigger);
						DrawNormalBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, thickness::box_thick, Colordouble);

					}

					if (external_def::g_3d_box_triangle)
					{

						if (head.x != 0 || head.y != 0 || head.z != 0)
						{
							ImU32 Colorsimple, Colordouble;

							if (box_color)
							{
								if (Visible)
									Colorsimple = IM_COL32(box_r, box_g, box_b, 255);

								else if (!Visible)


									if (Visible)
										Colorsimple = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);

									else if (!Visible)


										Colorsimple = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);

								if (Visible)
									Colordouble = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);
								else
									Colordouble = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);

							}
							else
							{
								if (Visible)
									Colorsimple = IM_COL32(0, 255, 0, 255);

								else if (!Visible)


									Colorsimple = IM_COL32(255, 0, 0, 255);

								if (Visible)
									Colordouble = IM_COL32(0, 255, 0, 255);
								else
									Colordouble = IM_COL32(255, 0, 0, 255);
							}




							//	DrawCorneredBox(player_screen.x - (BoxWidth / 2), head_screen.y, BoxWidth, BoxHeight, IM_COL32(255, 215, 0, 255), 1.5);



								//box simple
							Vector3 bottom1 = ProjectWorldToScreen(Vector3(foot.x + 60, foot.y - 60, foot.z));
							Vector3 bottom2 = ProjectWorldToScreen(Vector3(foot.x - 60, foot.y - 60, foot.z));
							Vector3 bottom3 = ProjectWorldToScreen(Vector3(foot.x - 60, foot.y + 60, foot.z));
							Vector3 bottom4 = ProjectWorldToScreen(Vector3(foot.x + 60, foot.y + 60, foot.z));

							Vector3 top1 = ProjectWorldToScreen(Vector3(head.x + 0, head.y - 0, head.z + 35));
							Vector3 top2 = ProjectWorldToScreen(Vector3(head.x - 0, head.y - 0, head.z + 35));
							Vector3 top3 = ProjectWorldToScreen(Vector3(head.x - 0, head.y + 0, head.z + 35));
							Vector3 top4 = ProjectWorldToScreen(Vector3(head.x + 0, head.y + 0, head.z + 35));

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), Colordouble, thickness::box_thick);





						}

					}

					if (aimbot::triggerbot)
					{
						if (isVisible(mesh))
						{
							move_to(Headbox.x, Headbox.y);
						}
					}
					if (external_def::g_3d_head)
					{

						if (head.x != 0 || head.y != 0 || head.z != 0)
						{
							ImU32 Colorsimple, Colordouble;


							if (box_color)
							{
								if (Visible)
									Colorsimple = IM_COL32(box_r, box_g, box_b, 255);

								else if (!Visible)


									Colorsimple = IM_COL32(255, 255, 255, 255);

								if (Visible)
									Colordouble = IM_COL32(box_g, box_b, box_r, 255);
								else
									Colordouble = IM_COL32(255, 255, 255, 255);

							}
							else
							{
								if (Visible)
									Colorsimple = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);

								else if (!Visible)


									Colorsimple = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);

								if (Visible)
									Colordouble = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);
								else
									Colordouble = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);
							}

							//box head
							Vector3 head_bottom1 = ProjectWorldToScreen(Vector3(nukr.x + 10, nukr.y - 10, nukr.z));
							Vector3 head_bottom2 = ProjectWorldToScreen(Vector3(nukr.x - 10, nukr.y - 10, nukr.z));
							Vector3 head_bottom3 = ProjectWorldToScreen(Vector3(nukr.x - 10, nukr.y + 10, nukr.z));
							Vector3 head_bottom4 = ProjectWorldToScreen(Vector3(nukr.x + 10, nukr.y + 10, nukr.z));

							Vector3 head_top1 = ProjectWorldToScreen(Vector3(head.x + 10, head.y - 10, head.z + 10));
							Vector3 head_top2 = ProjectWorldToScreen(Vector3(head.x - 10, head.y - 10, head.z + 10));
							Vector3 head_top3 = ProjectWorldToScreen(Vector3(head.x - 10, head.y + 10, head.z + 10));
							Vector3 head_top4 = ProjectWorldToScreen(Vector3(head.x + 10, head.y + 10, head.z + 10));


							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_bottom1.x, head_bottom1.y), ImVec2(head_top1.x, head_top1.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_bottom2.x, head_bottom2.y), ImVec2(head_top2.x, head_top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_bottom3.x, head_bottom3.y), ImVec2(head_top3.x, head_top3.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_bottom4.x, head_bottom4.y), ImVec2(head_top4.x, head_top4.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_bottom1.x, head_bottom1.y), ImVec2(head_bottom2.x, head_bottom2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_bottom2.x, head_bottom2.y), ImVec2(head_bottom3.x, head_bottom3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_bottom3.x, head_bottom3.y), ImVec2(head_bottom4.x, head_bottom4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_bottom4.x, head_bottom4.y), ImVec2(head_bottom1.x, head_bottom1.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_top1.x, head_top1.y), ImVec2(head_top2.x, head_top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_top2.x, head_top2.y), ImVec2(head_top3.x, head_top3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_top3.x, head_top3.y), ImVec2(head_top4.x, head_top4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head_top4.x, head_top4.y), ImVec2(head_top1.x, head_top1.y), Colordouble, thickness::box_thick);


						}
					}
					if (external_def::g_3d_hand)
					{

						if (head.x != 0 || head.y != 0 || head.z != 0)
						{
							ImU32 Colorsimple, Colordouble;
							if (box_color)
							{
								if (Visible)
									Colorsimple = IM_COL32(box_r, box_g, box_b, 255);

								else if (!Visible)


									Colorsimple = IM_COL32(255, 255, 255, 255);

								if (Visible)
									Colordouble = IM_COL32(box_g, box_b, box_r, 255);
								else
									Colordouble = IM_COL32(255, 255, 255, 255);

							}
							else
							{
								if (Visible)
									Colorsimple = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);

								else if (!Visible)


									Colorsimple = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);

								if (Visible)
									Colordouble = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);
								else
									Colordouble = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);
							}

							/*ImGui::GetBackgroundDrawList()->AddLine(ImVec2(head.x, head.y), ImVec2(nukr.x, nukr.y), ImColor(255,255,255,255), 1.5f);*/

							////box hand left

							Vector3 hand1_bottom1 = ProjectWorldToScreen(Vector3(left_hand_bottom.x, left_hand_bottom.y, left_hand_bottom.z));
							Vector3 hand1_bottom2 = ProjectWorldToScreen(Vector3(left_hand_bottom.x, left_hand_bottom.y, left_hand_bottom.z));
							Vector3 hand1_bottom3 = ProjectWorldToScreen(Vector3(left_hand_bottom.x, left_hand_bottom.y, left_hand_bottom.z));
							Vector3 hand1_bottom4 = ProjectWorldToScreen(Vector3(left_hand_bottom.x, left_hand_bottom.y, left_hand_bottom.z));

							Vector3 hand1_top1 = ProjectWorldToScreen(Vector3(left_hand_top.x, left_hand_top.y, left_hand_top.z));
							Vector3 hand1_top2 = ProjectWorldToScreen(Vector3(left_hand_top.x, left_hand_top.y, left_hand_top.z));
							Vector3 hand1_top3 = ProjectWorldToScreen(Vector3(left_hand_top.x, left_hand_top.y, left_hand_top.z));
							Vector3 hand1_top4 = ProjectWorldToScreen(Vector3(left_hand_top.x, left_hand_top.y, left_hand_top.z));


							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_bottom1.x, hand1_bottom1.y), ImVec2(hand1_top1.x, hand1_top1.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_bottom2.x, hand1_bottom2.y), ImVec2(hand1_top2.x, hand1_top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_bottom3.x, hand1_bottom3.y), ImVec2(hand1_top3.x, hand1_top3.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_bottom4.x, hand1_bottom4.y), ImVec2(hand1_top4.x, hand1_top4.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_bottom1.x, hand1_bottom1.y), ImVec2(hand1_bottom2.x, hand1_bottom2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_bottom2.x, hand1_bottom2.y), ImVec2(hand1_bottom3.x, hand1_bottom3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_bottom3.x, hand1_bottom3.y), ImVec2(hand1_bottom4.x, hand1_bottom4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_bottom4.x, hand1_bottom4.y), ImVec2(hand1_bottom1.x, hand1_bottom1.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_top1.x, hand1_top1.y), ImVec2(hand1_top2.x, hand1_top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_top2.x, hand1_top2.y), ImVec2(hand1_top3.x, hand1_top3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_top3.x, hand1_top3.y), ImVec2(hand1_top4.x, hand1_top4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand1_top4.x, hand1_top4.y), ImVec2(hand1_top1.x, hand1_top1.y), Colordouble, thickness::box_thick);



							////box hand right
							Vector3 hand2_bottom1 = ProjectWorldToScreen(Vector3(right_hand_bottom.x, right_hand_bottom.y, right_hand_bottom.z));
							Vector3 hand2_bottom2 = ProjectWorldToScreen(Vector3(right_hand_bottom.x, right_hand_bottom.y, left_hand_bottom.z));
							Vector3 hand2_bottom3 = ProjectWorldToScreen(Vector3(right_hand_bottom.x, right_hand_bottom.y, right_hand_bottom.z));
							Vector3 hand2_bottom4 = ProjectWorldToScreen(Vector3(right_hand_bottom.x, right_hand_bottom.y, right_hand_bottom.z));

							Vector3 hand2_top1 = ProjectWorldToScreen(Vector3(right_hand_top.x, right_hand_top.y, right_hand_top.z));
							Vector3 hand2_top2 = ProjectWorldToScreen(Vector3(right_hand_top.x, right_hand_top.y, right_hand_top.z));
							Vector3 hand2_top3 = ProjectWorldToScreen(Vector3(right_hand_top.x, right_hand_top.y, right_hand_top.z));
							Vector3 hand2_top4 = ProjectWorldToScreen(Vector3(right_hand_top.x, right_hand_top.y, right_hand_top.z));




							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_bottom1.x, hand2_bottom1.y), ImVec2(hand2_top1.x, hand2_top1.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_bottom2.x, hand2_bottom2.y), ImVec2(hand2_top2.x, hand2_top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_bottom3.x, hand2_bottom3.y), ImVec2(hand2_top3.x, hand2_top3.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_bottom4.x, hand2_bottom4.y), ImVec2(hand2_top4.x, hand2_top4.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_bottom1.x, hand2_bottom1.y), ImVec2(hand2_bottom2.x, hand2_bottom2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_bottom2.x, hand2_bottom2.y), ImVec2(hand2_bottom3.x, hand2_bottom3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_bottom3.x, hand2_bottom3.y), ImVec2(hand2_bottom4.x, hand2_bottom4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_bottom4.x, hand2_bottom4.y), ImVec2(hand2_bottom1.x, hand2_bottom1.y), Colordouble, thickness::box_thick);

							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_top1.x, hand2_top1.y), ImVec2(hand2_top2.x, hand2_top2.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_top2.x, hand2_top2.y), ImVec2(hand2_top3.x, hand2_top3.y), Colorsimple, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_top3.x, hand2_top3.y), ImVec2(hand2_top4.x, hand2_top4.y), Colordouble, thickness::box_thick);
							ImGui::GetBackgroundDrawList()->AddLine(ImVec2(hand2_top4.x, hand2_top4.y), ImVec2(hand2_top1.x, hand2_top1.y), Colordouble, thickness::box_thick);


						}

					}
					if (visuals::lines)
					{

						ImU32 Colorsimple;
						if (box_color)
						{
							if (Visible)
								Colorsimple = IM_COL32(box_r, box_g, box_b, 255);

							else if (!Visible)


								Colorsimple = IM_COL32(255, 255, 255, 255);



						}
						else
						{
							if (Visible)
								Colorsimple = IM_COL32(VisibleColCheck::r, VisibleColCheck::g, VisibleColCheck::b, 255);

							else if (!Visible)


								Colorsimple = IM_COL32(InVisibleColCheck::r, InVisibleColCheck::g, InVisibleColCheck::b, 255);



						}

						if (visuals::lineMode == 0)
							DrawLineV2(DriverVar::width / 2, DriverVar::height, player_screen.x, player_screen.y, Colorsimple, 1.5f);
						if (visuals::lineMode == 1)
							DrawLineV2(DriverVar::width / 2, 0.f, player_screen.x, player_screen.y, Colorsimple, 1.5f);
						if (visuals::lineMode == 2)
							DrawLineV2(DriverVar::width / 2, DriverVar::height / 2, player_screen.x, player_screen.y, Colorsimple, 1.5f);

					}
					//if (visuals::weapon)
					//{
					//	

					//	_QWORD APlayerState = ctx->read_physical_memory<_QWORD>(UFortKismetLibrary::FortShippingLogSuppressedObjects);//APlayerState->PlayerNamePrivate*FString
					//	auto nameptr = ctx->read_physical_memory<uintptr_t>(g_pid, APlayerState + 0x370);

					//	_QWORD StringData = ctx->read_physical_memory<_QWORD>(g_pid, nameptr);
					//	uint32_t StringLength = ctx->read_physical_memory<uint32_t>(g_pid, nameptr + 0x8);
					//	wchar_t* OutString = new wchar_t[StringLength + 1];
					//	Drive.ctx->read_physical_memoryPtr(g_pid, StringData, OutString, StringLength * sizeof(wchar_t));

					//	std::string Text = wchar_to_char(OutString);

					//	DrawString(13, vHeadBoneOut.x, vHeadBoneOut.y - 50, &Col.white, true, true, Text.c_str());
					//}

				}
		}

			
		
	}
	


#endif