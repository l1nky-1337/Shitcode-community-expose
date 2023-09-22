//#pragma once
//#include "stdafx.hpp"
//bool spinbot_hak = false;
//bool spinbot_hak_player = false;
//void SpinBot_Client_hook()
//{
//	uintptr_t Mesh = ctx->read_physical_memory<uintptr_t>(LocalPawn_base + Character::Mesh); //possible ctx->read_physical_memory<uintptr_t>(LocalPawn_base + Character::CharacterMovement);
//
//	if (enable_exploit_client)
//	{
//		if (LocalPawn_base)
//		{
//			if (spinbot_hak)
//			{
//				if (GetAsyncKeyState(VK_LBUTTON) < 0)
//				{
//					
//					static auto Cached = ctx->read_physical_memory<Vector3>(Mesh + SceneComponent::RelativeRotation);
//					ctx->write_physical_memory<Vector3>(Mesh + SceneComponent::RelativeRotation, Vector3(1, spin_val, 1));
//					spin_val = rand() % 361;
//				}
//				else
//				{
//					ctx->write_physical_memory<Vector3>(Mesh + SceneComponent::RelativeRotation, Vector3(1, spin_val, 1));
//				}
//			}
//		}
//	}
//}
//
//void SpinBot_Client_entity_actor_hook()
//{
//	_Entity currEntity{ };
//
//
//	if (enable_exploit_client)
//	{
//		if (LocalPawn_base)
//		{
//			if (spinbot_hak_player)
//			{
//					static auto Cached = ctx->read_physical_memory<Vector3>(Off_player_array + SceneComponent::RelativeRotation);
//					ctx->write_physical_memory<Vector3>(Off_player_array + SceneComponent::RelativeRotation, Vector3(1, spin_val_actor, 1));
//					spin_val_actor = rand() % 361;
//				}
//				
//			}
//		}
//	}
