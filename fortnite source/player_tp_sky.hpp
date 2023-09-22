#pragma once


//namespace USceneComponent
//{
//    constexpr auto PhysicsVolume = 0xa8; // TWeakObjectPtr<APhysicsVolume>
//    constexpr auto AttachParent = 0xb0; // USceneComponent*
//    constexpr auto AttachSocketName = 0xb8; // FName
//    constexpr auto AttachChildren = 0xc0; // TArray<USceneComponent*>
//    constexpr auto ClientAttachedChildren = 0xd0; // TArray<USceneComponent*>
//    constexpr auto RelativeLocation = 0x128; // FVector
//    constexpr auto RelativeRotation = 0x140; // FRotator
//    constexpr auto RelativeScale3D = 0x158; // FVector
//    constexpr auto ComponentVelocity = 0x170; // FVector
//    constexpr auto bComponentToWorldUpdated = 0x188; // char : 1
//    constexpr auto bAbsoluteLocation = 0x188; // char : 1
//    constexpr auto bAbsoluteRotation = 0x188; // char : 1
//    constexpr auto bAbsoluteScale = 0x188; // char : 1
//    constexpr auto bVisible = 0x188; // char : 1
//    constexpr auto bShouldBeAttached = 0x188; // char : 1
//    constexpr auto bShouldSnapLocationWhenAttached = 0x188; // char : 1
//    constexpr auto bShouldSnapRotationWhenAttached = 0x189; // char : 1
//    constexpr auto bShouldSnapScaleWhenAttached = 0x189; // char : 1
//    constexpr auto bShouldUpdatePhysicsVolume = 0x189; // char : 1
//    constexpr auto bHiddenInGame = 0x189; // char : 1
//    constexpr auto bBoundsChangeTriggersStreamingDataRebuild = 0x189; // char : 1
//    constexpr auto bUseAttachParentBound = 0x189; // char : 1
//    constexpr auto bComputeFastLocalBounds = 0x189; // char : 1
//    constexpr auto bComputeBoundsOnceForGame = 0x189; // char : 1
//    constexpr auto bComputedBoundsOnceForGame = 0x18a; // char : 1
//    constexpr auto bIsNotRenderAttachmentRoot = 0x18a; // char : 1
//    constexpr auto Mobility = 0x18b; // EComponentMobility
//    constexpr auto DetailMode = 0x18c; // EDetailMode
//    constexpr auto PhysicsVolumeChangedDelegate = 0x18d; // FMulticastSparseDelegate
//}

void tp_player_sky()
{
        if (LocalPawn_base)
        {
            if (tp_players_sky)
            {
                DWORD_PTR Player = ctx->read_physical_memory<DWORD_PTR>(uworld + 0x30);
                if (Player)
                {
                    int ActorCount = ctx->read_physical_memory<int>(Player + 0xA0);
                    uint64_t AActors = ctx->read_physical_memory<uint64_t>(Player + 0x98);
                    for (int i = 0; i < ActorCount; i++)
                    {
                        uintptr_t CurrentItemPawn = ctx->read_physical_memory<uintptr_t>(AActors + (i * sizeof(uintptr_t)));




                        auto mesh = ctx->read_physical_memory<uintptr_t>(closestPawnExploit + Character::Mesh);
                        uint64_t bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x600);
                        if (!bonearray) bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x648);
                        FTransform ComponentToWorld = ctx->read_physical_memory<FTransform>(mesh + 0x240);
                        //  boneinfo closestboneinfo; 


                        uint64_t Vehicle = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
                        DWORD_PTR VehicleRootComp = ctx->read_physical_memory<DWORD_PTR>(Vehicle + Actor::RootComponent);
                        DWORD_PTR PawnRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Actor::RootComponent);
                        DWORD_PTR MeshRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Character::Mesh + Actor::RootComponent);

                        auto read_pos = ctx->read_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation);
                        auto read_pos_mesh = ctx->read_physical_memory<Vector3>(MeshRootComp + SceneComponent::RelativeLocation);
                        auto read_pos_vehcle = ctx->read_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation);

                        Vector3 rootHead;
                        Vector3 foot;

                        rootHead = GetBoneWithRotation(mesh, 106);
                        foot = GetBoneWithRotation(mesh, 0);



                        //  uintptr_t ProjectileRootComponent = ctx->read_physical_memory<uintptr_t>(CurrentItemPawn + AActor::RootComponent);
                        if (MouseController::GetAsyncKeyState(hotkeys_exploit::keybind))
                        {

                            ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                            ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                            if (LocalPawn_base)
                            {

                                Vector3 pos_veh = VehicleRootComp;
                                Vector3 pos_pwn = PawnRootComp;

                                //  ctx->write_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation, Vector3{ rootHead.x, rootHead.y , rootHead.z + 15 });

                             //    ctx->write_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation, Vector3{ rootHead.x, rootHead.y , rootHead.z + 15 });
                                ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                                ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                              //  ctx->write_physical_memory<char>(MeshRootComp + SceneComponent::bComponentToWorldUpdated, 0);

                                //position
                                ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos_vehcle.x - 2);
                                ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos_vehcle.y - 2);
                                ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 99999999 - 4);

                      /*          ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos.x - 2);
                                ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos.y - 2);
                                ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Z, 9999 - 4);*/

                                ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos.x - 2);
                                ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos.y - 2);
                                ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 99999999 - 4);
                                //camera
                                ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, read_pos_vehcle.x - 2);
                                ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, read_pos_vehcle.y - 2);
                                ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 99999999 - 4);

                            //    ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos.x - 2);
                           //     ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos.y - 2);
                            //    ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Z, 999 - 4);

                                ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, read_pos.x - 2);
                                ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, read_pos.y - 2);
                                ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 99999999 - 4);
                                ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 1);
                                ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 1);
                             //   ctx->write_physical_memory<char>(MeshRootComp + SceneComponent::bComponentToWorldUpdated, 1);

                                // rootHead.y, rootHead.z


                            }
                        }

                    }
                }
            }
        }
    }




    void Jump_car()
    {
        if (LocalPawn_base)
        {
            if (tp_jump_car)
            {
                DWORD_PTR Player = ctx->read_physical_memory<DWORD_PTR>(uworld + 0x30);
                if (Player)
                {
                    int ActorCount = ctx->read_physical_memory<int>(Player + 0xA0);
                    uint64_t AActors = ctx->read_physical_memory<uint64_t>(Player + 0x98);
                    for (int i = 0; i < ActorCount; i++)
                    {
                        uintptr_t CurrentItemPawn = ctx->read_physical_memory<uintptr_t>(AActors + (i * sizeof(uintptr_t)));




                        auto mesh = ctx->read_physical_memory<uintptr_t>(closestPawnExploit + Character::Mesh);
                        uint64_t bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x600);
                        if (!bonearray) bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x610);
                        FTransform ComponentToWorld = ctx->read_physical_memory<FTransform>(mesh + 0x240);
                        //  boneinfo closestboneinfo; 


                        uint64_t Vehicle = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
                        DWORD_PTR VehicleRootComp = ctx->read_physical_memory<DWORD_PTR>(Vehicle + Actor::RootComponent);
                        DWORD_PTR PawnRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Actor::RootComponent);
                        DWORD_PTR MeshRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Character::Mesh + Actor::RootComponent);

                        auto read_pos = ctx->read_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation);
                        auto read_pos_mesh = ctx->read_physical_memory<Vector3>(MeshRootComp + SceneComponent::RelativeLocation);
                        auto read_pos_vehcle = ctx->read_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation);

         
                        Vector3 rootHead;
                        Vector3 foot;

                        rootHead = GetBoneWithRotation(mesh, 106);
                        foot = GetBoneWithRotation(mesh, 0);



                        //  uintptr_t ProjectileRootComponent = ctx->read_physical_memory<uintptr_t>(CurrentItemPawn + AActor::RootComponent);
                        if (MouseController::GetAsyncKeyState(hotkeys_exploit::keybind))
                        {

                            ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                            ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                            if (Vehicle)
                            {

                                Vector3 pos_veh = VehicleRootComp;
                                Vector3 pos_pwn = PawnRootComp;

                                //  ctx->write_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation, Vector3{ rootHead.x, rootHead.y , rootHead.z + 15 });

                             //    ctx->write_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation, Vector3{ rootHead.x, rootHead.y , rootHead.z + 15 });
                                ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                                ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                                //  ctx->write_physical_memory<char>(MeshRootComp + SceneComponent::bComponentToWorldUpdated, 0);

                                  //position
 
                                ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 3500 - 4);

                                /*          ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos.x - 2);
                                          ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos.y - 2);
                                          ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Z, 9999 - 4);*/

                    
                                ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 3500 - 4);
                                //camera
    
                                ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 3500 - 4);

                                //    ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos.x - 2);
                               //     ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos.y - 2);
                                //    ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Z, 999 - 4);

                                ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 3500 - 4);
                                ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 1);
                                ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 1);
                                //   ctx->write_physical_memory<char>(MeshRootComp + SceneComponent::bComponentToWorldUpdated, 1);

                                   // rootHead.y, rootHead.z


                            }
                        }

                    }
                }
            }
        }
    }
