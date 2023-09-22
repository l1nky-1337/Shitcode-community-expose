#pragma once
#include "stdafx.hpp"

void tp_gun()
{
        if (LocalPawn_base)
        {
            if (tpbullet)
            {
                DWORD_PTR Player = ctx->read_physical_memory<DWORD_PTR>(uworld + 0x30);
                auto mesh = ctx->read_physical_memory<uintptr_t>(closestPawnExploit + Character::Mesh);
                uint64_t bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x600);
                if (!bonearray) bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x610);
                FTransform ComponentToWorld = ctx->read_physical_memory<FTransform>(mesh + 0x240);
                //  boneinfo closestboneinfo; 

                Vector3 rootHead;
                Vector3 neck;

                rootHead = GetBoneWithRotation(mesh, 106);
                neck = GetBoneWithRotation(mesh, 68);
                if (Player)
                {
                    int ActorCount = ctx->read_physical_memory<int>(Player + 0xA0);
                    uint64_t AActors = ctx->read_physical_memory<uint64_t>(Player + 0x98);
                    for (int i = 0; i < ActorCount; i++)
                    {
                        uintptr_t CurrentItemPawn = ctx->read_physical_memory<uintptr_t>(AActors + (i * sizeof(uintptr_t)));

                        int CurrentItemId = ctx->read_physical_memory<int>(CurrentItemPawn + 0x18);
                        auto AllAct = GetNameByIndex(CurrentItemId);

                        if (AllAct == "B_Prj_Bullet_Sniper_C" && AllAct == "B_Prj_Bullet_Athena_AR_C")
                        {
                         
                            uintptr_t ProjectileRootComponent = ctx->read_physical_memory<uintptr_t>(CurrentItemPawn + Actor::RootComponent);
                            ctx->write_physical_memory<char>(ProjectileRootComponent + SceneComponent::bComponentToWorldUpdated, 0);
                            ctx->write_physical_memory<Vector3>(ProjectileRootComponent + SceneComponent::RelativeLocation, Vector3(rootHead.x, rootHead.y, rootHead.z));
                   

                        }
                       
                    }
                }
            }
        }
    }