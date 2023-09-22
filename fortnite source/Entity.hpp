#ifndef ENTITY_HPP
#define ENTITY_HPP

int spin_val = 1.5; //client spinbot Exploit var
int spin_val_actor = 1.5; //client spinbot Exploit var
Vector3 Cached;
bool megachest = false;
bool megachestexit = false;
bool Templechest = false;
bool Templechest2 = false;
bool Templechestexit = false;
bool Icechest = false;
bool Icechestexit = false;
bool Castlechest = false;
bool Castlechestexit = false;
bool Citadellechest = false;
bool Citadellechestexit = false;
char cache_tp;
char cache_tp_pawn;
#include "bul_tp.hpp"
#include "CarTeleport.hpp"
#include "CarToPing.hpp"
#include "VanReboot.hpp"
#include "PlayerFly.hpp"
#include "Player_tp.hpp"
#include "Vehicle_speed.hpp"
#include "player_tp_sky.hpp"
#include "CARFLY.hpp"
#include "code_notif_render.hpp"
void __cdecl loop_exploit(void*)
{
    while (true)
    {
    /*    if (LocalPawn_base && enable_exploit_client)
        {
            spin_val = 1.5;
            spin_val_actor = 1.5;
            Cached = Vector3{ 1,1.5,1 };
        }*/

        if (tpbullet)
        {
            tp_gun();

            
        }



        if (tp_players)
        {
            tp_player();
        }
        if (tp_jump_car)
        {
            Jump_car();
        }

        if (tp_players_sky)
        {
            tp_player_sky();
        }

        if (boat_speed_toggle)
        {
            Boatspeed_07_05_2022();
        }
      //
      //  if (enable_exploit_server && vehicle_speed_exploit)
      //  {
      //      StartSpeedVEH();
      //  }
      //*  if (enable_exploit_server && test_tp_b)
      //  {
      //      cache_tp;
      //      cache_tp_pawn;
      //  }*/

        if (megachest or megachestexit or Templechest or Templechest2 or Templechestexit or Icechest or Icechestexit or Castlechest or Castlechestexit or Citadellechest or Citadellechestexit)
        {
            test_tp();
        }

      //  if (enable_exploit_server && EnableCarToPing)
      //  {
      //      CarToPing_hook();
      //  }

     

       /* if (enable_exploit_client && playerFly)
        {
            PlayerFly();
        }*/
    /*    if (enable_server_info)
        {
            hook_notify();
        }*/
    }
    Sleep(1);
}


void __cdecl loop_exploit_van(void*)
{
    while (true)
    {
    
      

    
    }
    Sleep(1);
}



void __cdecl bone_exploit(void*)
{
    while (true)
    {
        RBONE();
    }
    Sleep(1300);
}




void GetOffset()
{
    uworld = ctx->read_physical_memory<_QWORD>(DriverVar::module + 0xEE9ED98);
    auto game_instance = ctx->read_physical_memory<_QWORD>(uworld + World::OwningGameInstance);
    Off_player_array = ctx->read_physical_memory<_QWORD>(game_instance + 0x38);
    auto player_controller = ctx->read_physical_memory<_QWORD>(Off_player_array + 0x30);
    LocalPawn_base = ctx->read_physical_memory<_QWORD>(player_controller + PlayerController::AcknowledgedPawn);
    Off_rootcomponent = ctx->read_physical_memory<_QWORD>(LocalPawn_base + Actor::RootComponent);
    Off_relativelocation = ctx->read_physical_memory<Vector3>(Off_rootcomponent + SceneComponent::RelativeLocation);
    Off_currweapon = ctx->read_physical_memory<_QWORD>(LocalPawn_base + FortPawn::CurrentWeapon);


    CamManager = ctx->read_physical_memory<uint64_t>(player_controller + PlayerController::PlayerCameraManager);
}

void GetEntity()
{
    GetOffset();
    auto persistent_level = ctx->read_physical_memory<DWORD64>(uworld + 0x30);
    auto actor_array = ctx->read_physical_memory<DWORD_PTR>(persistent_level + 0x98);
    auto actor_count = ctx->read_physical_memory<DWORD32>(persistent_level + 0xA0);
    auto player_state = ctx->read_physical_memory<DWORD64>(LocalPawn_base + Pawn::PlayerState);
    Off_team_id = ctx->read_physical_memory<char>(player_state + FortPlayerStateAthena::TeamIndex);

    std::vector<_Entity> EntityList_tmp;
    EntityList_tmp.reserve(actor_count); // Reserve memory for better performance

    for (DWORD_PTR i = 0; i < actor_count; ++i)
    {
        uintptr_t actor = ctx->read_physical_memory<uintptr_t>(actor_array + i * sizeof(uintptr_t));
        if (!actor) { continue; }

        _Entity currEntity{ };
        currEntity.actor = actor;
        currEntity.mesh = ctx->read_physical_memory<_QWORD>(actor + Character::Mesh);
        currEntity.currweapon = ctx->read_physical_memory<_QWORD>(actor + FortPawn::CurrentWeapon);
        currEntity.playerstate = ctx->read_physical_memory<_QWORD>(actor + Pawn::PlayerState);
        EntityList_tmp.push_back(currEntity);
    }

    EntityList = std::move(EntityList_tmp); // Move the temporary vector to the actual container
}

 
#endif