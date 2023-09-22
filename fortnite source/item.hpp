//#include "stdafx.hpp"
//
//
//void loop_loot()
//{
//    if (LocalPawn_base)
//    {
//        std::vector<LootEntity> tmpList;
//        uintptr_t ItemLevels = ctx->read_physical_memory<uintptr_t>(uworld + 0x170);
//
//        for (int i = 0; i < ctx->read_physical_memory<DWORD>(uworld + (0x170 + sizeof(PVOID))); ++i) {
//
//            uintptr_t ItemLevel = ctx->read_physical_memory<uintptr_t>(ItemLevels + (i * sizeof(uintptr_t)));
//
//            for (int i = 0; i < ctx->read_physical_memory<DWORD>(ItemLevel + (0x98 + sizeof(PVOID))); ++i) {
//                uintptr_t ItemsPawns = ctx->read_physical_memory<uintptr_t>(ItemLevel + 0x98);
//                uintptr_t CurrentItemPawn = ctx->read_physical_memory<uintptr_t>(ItemsPawns + (i * sizeof(uintptr_t)));
//                uintptr_t ItemRootComponent = ctx->read_physical_memory<uintptr_t>(CurrentItemPawn + Actor::RootComponent);
//                Vector3 ItemPosition = ctx->read_physical_memory<Vector3>(ItemRootComponent + SceneComponent::RelativeLocation);
//
//
//                int ItemIndex = ctx->read_physical_memory<int>(CurrentItemPawn + 0x18);//
//                auto CurrentItemPawnName = GetNameByIndex(ItemIndex);
//
//                if (strstr(CurrentItemPawnName.c_str(), (("Tiered_Chest"))) || strstr(CurrentItemPawnName.c_str(), (("AthenaPlayerMarker_WithCustomization"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Simple_Avian_Crow_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Prey_Nug_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Predator_Robert_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Prey_Burt_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Simple_Smackie_C"))) || strstr(CurrentItemPawnName.c_str(), (("NPC_Pawn_Irwin_Predator_Grandma_C"))) ||
//                    (visuals::VehicleEsp && strstr(CurrentItemPawnName.c_str(), ("Vehicl")) || strstr(CurrentItemPawnName.c_str(), ("Valet_Taxi")) ||
//                        strstr(CurrentItemPawnName.c_str(), ("Valet_BigRig")) || strstr(CurrentItemPawnName.c_str(), ("Valet_BasicTr")) ||
//                        strstr(CurrentItemPawnName.c_str(), ("Valet_SportsC")) || strstr(CurrentItemPawnName.c_str(), ("Valet_BasicC")) ||
//                        strstr(CurrentItemPawnName.c_str(), ("Tiered_Ammo")) || strstr(CurrentItemPawnName.c_str(), ("MeatballVehicle_L_C"))))
//                {
//                    LootEntity LevelObjects{ };
//                    LevelObjects.ACurrentItem = CurrentItemPawn;
//                    LevelObjects.GNames = CurrentItemPawnName;
//                    tmpList.push_back(LevelObjects);
//                }
//
//            }
//        }
//        LootentityList.clear();
//        LootentityList = tmpList;
//        Sleep(3000);
//    }
//}
//
//
//
//
//    //if (strstr(pObjName.c_str(), "NPC_Pawn_Irwin_Predator_Robert_C")
//  //    || strstr(pObjName.c_str(), "NPC_Pawn_Irwin_Simple_Smackie_C")
//  //    || strstr(pObjName.c_str(), "NPC_Pawn_Irwin_Prey_Burt_C")
//  //    || strstr(pObjName.c_str(), "NPC_Pawn_Irwin_Simple_Avian_Crow_C")
//  //    || strstr(pObjName.c_str(), "NPC_Pawn_Irwin_Prey_Nug_C")
//  //    || strstr(pObjName.c_str(), "NPC_Pawn_Irwin_Predator_Grandma_C")
//  //    || strstr(pObjName.c_str(), "AthenaPlayerMarker_WithCustomization"))