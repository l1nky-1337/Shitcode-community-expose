//void CARFLYHOOK()
//{
//    if (enable_exploit_server)
//    {
//        if (LocalPawn_base)
//        {
//            if (BCARFLY)
//            {
//                DWORD_PTR Player = ctx->read_physical_memory<DWORD_PTR>(uworld + 0x30);
//                if (Player)
//                {
//                    int ActorCount = ctx->read_physical_memory<int>(Player + 0xA0);
//                    uint64_t AActors = ctx->read_physical_memory<uint64_t>(Player + 0x98);
//                    for (int i = 0; i < ActorCount; i++)
//                    {
//                        uintptr_t CurrentItemPawn = ctx->read_physical_memory<uintptr_t>(AActors + (i * sizeof(uintptr_t)));
//
//
//
//
//                        auto mesh = ctx->read_physical_memory<uintptr_t>(closestPawnExploit + Character::Mesh);
//                        uint64_t bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x5F8);
//                        if (!bonearray) bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x608);
//                        FTransform ComponentToWorld = ctx->read_physical_memory<FTransform>(mesh + 0x240);
//                        //  boneinfo closestboneinfo; 
//
//
//                        uint64_t Vehicle = ctx->read_physical_memory<uint64_t>(LocalPawn_base + FortPlayerPawn::CurrentVehicle);
//                        DWORD_PTR VehicleRootComp = ctx->read_physical_memory<DWORD_PTR>(Vehicle + Actor::RootComponent);
//                        DWORD_PTR PawnRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Actor::RootComponent);
//                        DWORD_PTR MeshRootComp = ctx->read_physical_memory<DWORD_PTR>(LocalPawn_base + Character::Mesh + Actor::RootComponent);
//
//                        auto read_pos = ctx->read_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation);
//                        auto read_pos_mesh = ctx->read_physical_memory<Vector3>(MeshRootComp + SceneComponent::RelativeLocation);
//                        auto read_pos_vehcle = ctx->read_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation);
//
//                        Vector3 rootHead;
//                        Vector3 foot;
//
//                        rootHead = GetBoneWithRotation(mesh, 106);
//                        foot = GetBoneWithRotation(mesh, 0);
//
//
//
//                        //  uintptr_t ProjectileRootComponent = ctx->read_physical_memory<uintptr_t>(CurrentItemPawn + AActor::RootComponent);
//                        if (GetAsyncKeyState(VK_MBUTTON))
//                        {
//
//                            ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 0);
//                            ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 0);
//                            if (LocalPawn_base)
//                            {
//
//                                Vector3 pos_veh = VehicleRootComp;
//                                Vector3 pos_pwn = PawnRootComp;
//
//                                //  ctx->write_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation, Vector3{ rootHead.x, rootHead.y , rootHead.z + 15 });
//
//                             //    ctx->write_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation, Vector3{ rootHead.x, rootHead.y , rootHead.z + 15 });
//                                ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 0);
//                                ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 0);
//                           //     ctx->write_physical_memory<char>(MeshRootComp + SceneComponent::bComponentToWorldUpdated, 0);
//
//                     
//                                if (GetAsyncKeyState(VK_SPACE)) //ESCAPE
//                                {
//                      
//
//                                    //position
//                                    ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos_vehcle.x);
//                                    ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos_vehcle.y);
//                                    ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, 1200 - 4);
//
//                                    //ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos.x);
//                                    //ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos.y);
//                                    //ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Z, 999 - 4);
//
//                                    ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos.x);
//                                    ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos.y);
//                                    ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, 1200 - 4);
//                                    //camera
//                                    ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::X, read_pos_vehcle.x);
//                                    ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Y, read_pos_vehcle.y);
//                                    ctx->write_physical_memory<double>(VehicleRootComp + 0x260 + FVector::Z, 1200 - 4);
//
//       /*                             ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::X, read_pos.x);
//                                    ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Y, read_pos.y);
//                                    ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Z, 140 - 4);*/
//
//                                    ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::X, read_pos.x);
//                                    ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Y, read_pos.y);
//                                    ctx->write_physical_memory<double>(PawnRootComp + 0x260 + FVector::Z, 1200 - 4);
//
//                                }
//                                ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 1);
//                                ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 1);
//                              //  ctx->write_physical_memory<char>(MeshRootComp + SceneComponent::bComponentToWorldUpdated, 1);
//
//                                // rootHead.y, rootHead.z
//
//
//                            }
//                        }
//
//                    }
//                }
//            }
//        }
//    }
//}