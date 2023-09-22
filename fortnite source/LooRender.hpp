#pragma once
void GetWeaponCache()
{
	
		std::vector<_ItemBase> itemBaseList_tmp;

		uworld = ctx->read_physical_memory<uint64_t>(DriverVar::module + 0xEE9ED98);
		auto game_instance = ctx->read_physical_memory<uint64_t>(uworld + World::OwningGameInstance);
		Off_player_array = ctx->read_physical_memory<uint64_t>(ctx->read_physical_memory<uint64_t>(game_instance + 0x38));
		auto player_controller = ctx->read_physical_memory<uint64_t>(Off_player_array + 0x30);

		LocalPawn_base = ctx->read_physical_memory<uint64_t>(player_controller + PlayerController::AcknowledgedPawn);
		Off_rootcomponent = ctx->read_physical_memory<uint64_t>(LocalPawn_base + Actor::RootComponent);
		Off_relativelocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);

		auto levelscount = ctx->read_physical_memory<int32>(uworld + World::Levels + 0x8);

		for (DWORD n = 0; n < levelscount; n++)
		{
			auto levels = ctx->read_physical_memory<uint64_t>(uworld + World::Levels);
			if (!levels) continue;

			auto level = ctx->read_physical_memory<uint64_t>(levels + (n * 0x8));
			if (!level) continue;

			auto actorscount = ctx->read_physical_memory<int32>(level + 0xA0);
			auto actorsarray = ctx->read_physical_memory<uint64_t>(level + 0x98);
			if (!actorsarray) continue;

			_ItemBase baseItem{ };
			baseItem.actorscount = actorscount;
			baseItem.actorsarray = actorsarray;
			itemBaseList_tmp.push_back(baseItem);
		}
		itemBaseList.clear();
		itemBaseList = itemBaseList_tmp;
		Sleep(4500);
	}

void GetWeapon()
{

		std::vector<_Item> itemList_tmp;

		uworld = ctx->read_physical_memory<uint64_t>(DriverVar::module + 0xEE9ED98);
		auto game_instance = ctx->read_physical_memory<uint64_t>(uworld + World::OwningGameInstance);
		Off_player_array = ctx->read_physical_memory<uint64_t>(ctx->read_physical_memory<uint64_t>(game_instance + 0x38));
		auto player_controller = ctx->read_physical_memory<uint64_t>(Off_player_array + 0x30);

		LocalPawn_base = ctx->read_physical_memory<uint64_t>(player_controller + PlayerController::AcknowledgedPawn);
		Off_rootcomponent = ctx->read_physical_memory<uint64_t>(LocalPawn_base + Actor::RootComponent);
		Off_relativelocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);

		for (DWORD i = 0; i < itemBaseList.size(); i++)
		{
			for (DWORD n = 0; n < itemBaseList[i].actorscount; n++)
			{
				auto actor = ctx->read_physical_memory<uint64_t>(itemBaseList[i].actorsarray + (n * 0x8));

				auto actorClassPrivate = ctx->read_physical_memory<uint64_t>(actor + 0x10);
				if (!AFortPickupAthena) {
					auto pUItemID = ctx->read_physical_memory<int32>(actor + 0x18);
					if (!pUItemID) continue;

					auto pObjName = GetNameByIndex(pUItemID);

					if (strstr(pObjName.c_str(), _XOR_("Fort_Pickup_Creative_C")) || strstr(pObjName.c_str(), _XOR_("FortPickupAthena")) || strstr(pObjName.c_str(), _XOR_("AFortPickupAthena")) || strstr(pObjName.c_str(), _XOR_("Tiered_Chest")) && visuals::items)
					{
						AFortPickupAthena = ctx->read_physical_memory<uint64_t>(actor + 0x10); // (ClassPrivate)
					}
					else
						continue;
				}

				if (actorClassPrivate == AFortPickupAthena)
				{
					auto item = ctx->read_physical_memory<uint64_t>(actor + (FortPickup::PrimaryPickupItemEntry + 0x18)); // (PrimaryPickupItemEntry + ItemDefinition)
					if (item)
					{

						auto DisplayName = ctx->read_physical_memory<uint64_t>(item + 0x90); // DisplayName (FText)
						auto ItemLength = ctx->read_physical_memory<int32>(DisplayName + 0x38); // FText -> Length
						wchar_t* ItemName = new wchar_t[static_cast<size_t>(ItemLength) + 1];

						auto DisplayNameData = ctx->read_physical_memory<uintptr_t>(DisplayName + 0x30);
						//ctx->read_physical_memory(DisplayNameData, reinterpret_cast<uint8_t*>(ItemName), static_cast<size_t>(ItemLength) * sizeof(wchar_t)); // FText -> Name

						std::wstring wItemName(ItemName, static_cast<size_t>(ItemLength));
						std::string sItemName(wItemName.begin(), wItemName.end());
						auto bWTier = ctx->read_physical_memory<BYTE>(item + FortItemDefinition::Tier);

						_Item currItem{ };
						currItem.actor = actor;
						currItem.ItemName = sItemName;
						currItem.bWTier = bWTier;
						itemList_tmp.push_back(currItem);
						auto pUItemID = ctx->read_physical_memory<int32>(actor + 0x18);
						if (!pUItemID) continue;
						auto pObjName = GetNameByIndex(pUItemID);
						if (strstr(pObjName.c_str(), (_XOR_("Tiered_Chest"))) || strstr(pObjName.c_str(), (_XOR_("AthenaPlayerMarker_WithCustomization"))) || strstr(pObjName.c_str(), (_XOR_("NPC_Pawn_Irwin_Simple_Avian_Crow_C"))) || strstr(pObjName.c_str(), (_XOR_("NPC_Pawn_Irwin_Prey_Nug_C"))) || strstr(pObjName.c_str(), (_XOR_("NPC_Pawn_Irwin_Predator_Robert_C"))) || strstr(pObjName.c_str(), (_XOR_("NPC_Pawn_Irwin_Prey_Burt_C"))) || strstr(pObjName.c_str(), (_XOR_("NPC_Pawn_Irwin_Simple_Smackie_C"))) || strstr(pObjName.c_str(), (_XOR_("NPC_Pawn_Irwin_Predator_Grandma_C"))) ||
							(visuals::VehicleEsp && strstr(pObjName.c_str(), (_XOR_("Vehicl"))) || strstr(pObjName.c_str(), (_XOR_("Valet_Taxi"))) ||
								strstr(pObjName.c_str(), (_XOR_("Valet_BigRig"))) || strstr(pObjName.c_str(), (_XOR_("Valet_BasicTr"))) ||
								strstr(pObjName.c_str(), (_XOR_("Valet_SportsC"))) || strstr(pObjName.c_str(), (_XOR_("Valet_BasicC"))) ||
								strstr(pObjName.c_str(), (_XOR_("Tiered_Ammo"))) || strstr(pObjName.c_str(), (_XOR_("MeatballVehicle_L_C")))))


						
							_Item currItem{ };
							currItem.actor = actor;
							currItem.ItemName = sItemName;
							currItem.bWTier = bWTier;
							itemList_tmp.push_back(currItem);
						
					}
				}
			}
		}
		itemList.clear();
		itemList = itemList_tmp;
		Sleep(1500);
	
}
