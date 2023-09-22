namespace UCharacterMovementComponent
{
	constexpr auto CharacterOwner = 0x160; // ACharacter*
	constexpr auto GravityScale = 0x168; // float
	constexpr auto MaxStepHeight = 0x16c; // float
	constexpr auto JumpZVelocity = 0x170; // float
	constexpr auto JumpOffJumpZFactor = 0x174; // float
	constexpr auto WalkableFloorAngle = 0x194; // float
	constexpr auto WalkableFloorZ = 0x198; // float
	constexpr auto MovementMode = 0x19c; // EMovementMode
	constexpr auto CustomMovementMode = 0x19d; // char
	constexpr auto NetworkSmoothingMode = 0x19e; // ENetworkSmoothingMode
	constexpr auto GroundFriction = 0x1a0; // float
	constexpr auto MaxWalkSpeed = 0x1e8; // float
	constexpr auto MaxWalkSpeedCrouched = 0x1ec; // float
	constexpr auto MaxSwimSpeed = 0x1f0; // float
	constexpr auto MaxFlySpeed = 0x1f4; // float
	constexpr auto MaxCustomMovementSpeed = 0x1f8; // float
	constexpr auto MaxAcceleration = 0x1fc; // float
	constexpr auto MinAnalogWalkSpeed = 0x200; // float
	constexpr auto BrakingFrictionFactor = 0x204; // float
	constexpr auto BrakingFriction = 0x208; // float
	constexpr auto BrakingSubStepTime = 0x20c; // float
	constexpr auto BrakingDecelerationWalking = 0x210; // float
	constexpr auto BrakingDecelerationFalling = 0x214; // float
	constexpr auto BrakingDecelerationSwimming = 0x218; // float
	constexpr auto BrakingDecelerationFlying = 0x21c; // float
	constexpr auto AirControl = 0x220; // float
	constexpr auto AirControlBoostMultiplier = 0x224; // float
	constexpr auto AirControlBoostVelocityThreshold = 0x228; // float
	constexpr auto FallingLateralFriction = 0x22c; // float
	constexpr auto CrouchedHalfHeight = 0x230; // float
	constexpr auto Buoyancy = 0x234; // float
	constexpr auto PerchRadiusThreshold = 0x238; // float
	constexpr auto PerchAdditionalHeight = 0x23c; // float
	constexpr auto RotationRate = 0x240; // FRotator
	constexpr auto bUseSeparateBrakingFriction = 0x258; // char : 1
	constexpr auto bApplyGravityWhileJumping = 0x258; // char : 1
	constexpr auto bUseControllerDesiredRotation = 0x258; // char : 1
	constexpr auto bOrientRotationToMovement = 0x258; // char : 1
	constexpr auto bSweepWhileNavWalking = 0x258; // char : 1
	constexpr auto bMovementInProgress = 0x258; // char : 1
	constexpr auto bEnableScopedMovementUpdates = 0x258; // char : 1
	constexpr auto bEnableServerDualMoveScopedMovementUpdates = 0x259; // char : 1
	constexpr auto bForceMaxAccel = 0x259; // char : 1
	constexpr auto bRunPhysicsWithNoController = 0x259; // char : 1
	constexpr auto bForceNextFloorCheck = 0x259; // char : 1
	constexpr auto bShrinkProxyCapsule = 0x259; // char : 1
	constexpr auto bCanWalkOffLedges = 0x259; // char : 1
	constexpr auto bCanWalkOffLedgesWhenCrouching = 0x259; // char : 1
	constexpr auto bNetworkSkipProxyPredictionOnNetUpdate = 0x25a; // char : 1
	constexpr auto bNetworkAlwaysReplicateTransformUpdateTimestamp = 0x25a; // char : 1
	constexpr auto bDeferUpdateMoveComponent = 0x2ba; // char : 1
	constexpr auto bEnablePhysicsInteraction = 0x25a; // char : 1
	constexpr auto bTouchForceScaledToMass = 0x25a; // char : 1
	constexpr auto bPushForceScaledToMass = 0x25a; // char : 1
	constexpr auto bPushForceUsingZOffset = 0x25a; // char : 1
	constexpr auto bScalePushForceToVelocity = 0x25b; // char : 1
	constexpr auto DeferredUpdatedMoveComponent = 0x260; // USceneComponent*
	constexpr auto MaxOutOfWaterStepHeight = 0x268; // float
	constexpr auto OutofWaterZ = 0x26c; // float
	constexpr auto Mass = 0x270; // float
	constexpr auto StandingDownwardForceScale = 0x274; // float
	constexpr auto InitialPushForceFactor = 0x278; // float
	constexpr auto PushForceFactor = 0x27c; // float
	constexpr auto PushForcePointZOffsetFactor = 0x280; // float
	constexpr auto TouchForceFactor = 0x284; // float
	constexpr auto MinTouchForce = 0x288; // float
	constexpr auto MaxTouchForce = 0x28c; // float
	constexpr auto RepulsionForce = 0x290; // float
	constexpr auto Acceleration = 0x298; // FVector
	constexpr auto LastUpdateRotation = 0x2b0; // FQuat
	constexpr auto LastUpdateLocation = 0x2d0; // FVector
	constexpr auto LastUpdateVelocity = 0x2e8; // FVector
	constexpr auto ServerLastTransformUpdateTimeStamp = 0x300; // float
	constexpr auto ServerLastClientGoodMoveAckTime = 0x304; // float
	constexpr auto ServerLastClientAdjustmentTime = 0x308; // float
	constexpr auto PendingImpulseToApply = 0x310; // FVector
	constexpr auto PendingForceToApply = 0x328; // FVector
	constexpr auto AnalogInputModifier = 0x340; // float
	constexpr auto MaxSimulationTimeStep = 0x350; // float
	constexpr auto MaxSimulationIterations = 0x354; // int32_t
	constexpr auto MaxJumpApexAttemptsPerSimulation = 0x358; // int32_t
	constexpr auto MaxDepenetrationWithGeometry = 0x35c; // float
	constexpr auto MaxDepenetrationWithGeometryAsProxy = 0x360; // float
	constexpr auto MaxDepenetrationWithPawn = 0x364; // float
	constexpr auto MaxDepenetrationWithPawnAsProxy = 0x368; // float
	constexpr auto NetworkSimulatedSmoothLocationTime = 0x36c; // float
	constexpr auto NetworkSimulatedSmoothRotationTime = 0x370; // float
	constexpr auto ListenServerNetworkSimulatedSmoothLocationTime = 0x374; // float
	constexpr auto ListenServerNetworkSimulatedSmoothRotationTime = 0x378; // float
	constexpr auto NetProxyShrinkRadius = 0x37c; // float
	constexpr auto NetProxyShrinkHalfHeight = 0x380; // float
	constexpr auto NetworkMaxSmoothUpdateDistance = 0x384; // float
	constexpr auto NetworkNoSmoothUpdateDistance = 0x388; // float
	constexpr auto NetworkMinTimeBetweenClientAckGoodMoves = 0x38c; // float
	constexpr auto NetworkMinTimeBetweenClientAdjustments = 0x390; // float
	constexpr auto NetworkMinTimeBetweenClientAdjustmentsLargeCorrection = 0x394; // float
	constexpr auto NetworkLargeClientCorrectionDistance = 0x398; // float
	constexpr auto LedgeCheckThreshold = 0x39c; // float
	constexpr auto JumpOutOfWaterPitch = 0x3a0; // float
	constexpr auto CurrentFloor = 0x3a8; // FFindFloorResult
	constexpr auto DefaultLandMovementMode = 0x498; // EMovementMode
	constexpr auto DefaultWaterMovementMode = 0x499; // EMovementMode
	constexpr auto GroundMovementMode = 0x49a; // EMovementMode
	constexpr auto bMaintainHorizontalGroundVelocity = 0x4a4; // char : 1
	constexpr auto bImpartBaseVelocityX = 0x4a4; // char : 1
	constexpr auto bImpartBaseVelocityY = 0x4a4; // char : 1
	constexpr auto bImpartBaseVelocityZ = 0x4a4; // char : 1
	constexpr auto bImpartBaseAngularVelocity = 0x4a4; // char : 1
	constexpr auto bJustTeleported = 0x4a4; // char : 1
	constexpr auto bNetworkUpdateReceived = 0x4a4; // char : 1
	constexpr auto bNetworkMovementModeChanged = 0x4a4; // char : 1
	constexpr auto bIgnoreClientMovementErrorChecksAndCorrection = 0x4a5; // char : 1
	constexpr auto bServerAcceptClientAuthoritativePosition = 0x4a5; // char : 1
	constexpr auto bNotifyApex = 0x4a5; // char : 1
	constexpr auto bCheatFlying = 0x4a5; // char : 1
	constexpr auto bWantsToCrouch = 0x4a5; // char : 1
	constexpr auto bCrouchMaintainsBaseLocation = 0x4a5; // char : 1
	constexpr auto bIgnoreBaseRotation = 0x4a5; // char : 1
	constexpr auto bFastAttachedMove = 0x4a5; // char : 1
	constexpr auto bAlwaysCheckFloor = 0x4a6; // char : 1
	constexpr auto bUseFlatBaseForFloorChecks = 0x4a6; // char : 1
	constexpr auto bPerformingJumpOff = 0x4a6; // char : 1
	constexpr auto bWantsToLeaveNavWalking = 0x4a6; // char : 1
	constexpr auto bUseRVOAvoidance = 0x4a6; // char : 1
	constexpr auto bRequestedMoveUseAcceleration = 0x4a6; // char : 1
	constexpr auto bWasSimulatingRootMotion = 0x4a6; // char : 1
	constexpr auto bAllowPhysicsRotationDuringAnimRootMotion = 0x4a7; // char : 1
	constexpr auto FormerBaseVelocityDecayHalfLife = 0x4a8; // float
	constexpr auto bHasRequestedVelocity = 0x4ac; // char : 1
	constexpr auto bRequestedMoveWithMaxSpeed = 0x4ac; // char : 1
	constexpr auto bWasAvoidanceUpdated = 0x4ac; // char : 1
	constexpr auto bProjectNavMeshWalking = 0x4ac; // char : 1
	constexpr auto bProjectNavMeshOnBothWorldChannels = 0x4ac; // char : 1
	constexpr auto AvoidanceConsiderationRadius = 0x4cc; // float
	constexpr auto RequestedVelocity = 0x4d0; // FVector
	constexpr auto LastUpdateRequestedVelocity = 0x4e8; // FVector
	constexpr auto AvoidanceUID = 0x500; // int32_t
	constexpr auto AvoidanceGroup = 0x504; // FNavAvoidanceMask
	constexpr auto GroupsToAvoid = 0x508; // FNavAvoidanceMask
	constexpr auto GroupsToIgnore = 0x50c; // FNavAvoidanceMask
	constexpr auto AvoidanceWeight = 0x510; // float
	constexpr auto PendingLaunchVelocity = 0x518; // FVector
	constexpr auto NavMeshProjectionInterval = 0x658; // float
	constexpr auto NavMeshProjectionTimer = 0x65c; // float
	constexpr auto NavMeshProjectionInterpSpeed = 0x660; // float
	constexpr auto NavMeshProjectionHeightScaleUp = 0x664; // float
	constexpr auto NavMeshProjectionHeightScaleDown = 0x668; // float
	constexpr auto NavWalkingFloorDistTolerance = 0x66c; // float
	constexpr auto PostPhysicsTickFunction = 0x6a0; // FCharacterMovementComponentPostPhysicsTickFunction
	constexpr auto MinTimeBetweenTimeStampResets = 0x6e8; // float
	constexpr auto CurrentRootMotion = 0xc38; // FRootMotionSourceGroup
	constexpr auto ServerCorrectionRootMotion = 0xc80; // FRootMotionSourceGroup
	constexpr auto RootMotionParams = 0xe30; // FRootMotionMovementParams
	constexpr auto AnimRootMotionVelocity = 0xea0; // FVector
}
void tp_player()
{
  
      
            if (tp_players)
            {
				if (MouseController::GetAsyncKeyState(hotkeys_exploit::keybind))
				{
                DWORD_PTR persistent_level = ctx->read_physical_memory<DWORD_PTR>(uworld + 0x30);
                if (persistent_level)
                {
                    int ActorCount = ctx->read_physical_memory<int>(persistent_level + 0xA0);
                    uint64_t AActors = ctx->read_physical_memory<uint64_t>(persistent_level + 0x98);
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

                        rootHead = GetBoneWithRotation(mesh, 43);
                        foot = GetBoneWithRotation(mesh, 0);



                        //  uintptr_t ProjectileRootComponent = ctx->read_physical_memory<uintptr_t>(CurrentItemPawn + AActor::RootComponent);
                    

                          //  ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                            ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                            if (!ActorCount == NULL && !AActors == NULL && !i == NULL)
                            {

                                Vector3 pos_veh = VehicleRootComp;
                                Vector3 pos_pwn = PawnRootComp;

                                //  ctx->write_physical_memory<Vector3>(PawnRootComp + SceneComponent::RelativeLocation, Vector3{ rootHead.x, rootHead.y , rootHead.z + 15 });

                             //    ctx->write_physical_memory<Vector3>(VehicleRootComp + SceneComponent::RelativeLocation, Vector3{ rootHead.x, rootHead.y , rootHead.z + 15 });
                                ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 0);
								ctx->write_physical_memory<char>(PawnRootComp + UCharacterMovementComponent::bDeferUpdateMoveComponent, 0);
                             //   ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 0);
                             //  ctx->write_physical_memory<char>(MeshRootComp + SceneComponent::bComponentToWorldUpdated, 0);

                                //position
                                ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::X, foot.x);
                                ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Y, foot.y);
                                ctx->write_physical_memory<double>(VehicleRootComp + SceneComponent::RelativeLocation + FVector::Z, foot.z);

                    /*            ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::X, foot.x - 2);
                                ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Y, foot.y - 2);
                                ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Z, foot.z - 4);*/

                                ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::X, foot.x);
                                ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Y, foot.y);
                                ctx->write_physical_memory<double>(PawnRootComp + SceneComponent::RelativeLocation + FVector::Z, foot.z);
                                //camera
                                ctx->write_physical_memory<double>(VehicleRootComp + UCharacterMovementComponent::DeferredUpdatedMoveComponent + FVector::X, foot.x);
                                ctx->write_physical_memory<double>(VehicleRootComp + UCharacterMovementComponent::DeferredUpdatedMoveComponent + FVector::Y, foot.y);
                                ctx->write_physical_memory<double>(VehicleRootComp + UCharacterMovementComponent::DeferredUpdatedMoveComponent + FVector::Z, foot.z);

                        /*        ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::X, foot.x - 2);
                                ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Y, foot.y - 2);
                                ctx->write_physical_memory<double>(MeshRootComp + SceneComponent::RelativeLocation + FVector::Z, foot.z - 4);*/

                                ctx->write_physical_memory<double>(PawnRootComp + UCharacterMovementComponent::DeferredUpdatedMoveComponent + FVector::X, foot.x);
                                ctx->write_physical_memory<double>(PawnRootComp + UCharacterMovementComponent::DeferredUpdatedMoveComponent + FVector::Y, foot.y);
                                ctx->write_physical_memory<double>(PawnRootComp + UCharacterMovementComponent::DeferredUpdatedMoveComponent + FVector::Z, foot.z);
                                ctx->write_physical_memory<char>(PawnRootComp + SceneComponent::bComponentToWorldUpdated, 1);
								ctx->write_physical_memory<char>(PawnRootComp + UCharacterMovementComponent::bDeferUpdateMoveComponent, 1);
                           //     ctx->write_physical_memory<char>(VehicleRootComp + SceneComponent::bComponentToWorldUpdated, 1);
                         //       ctx->write_physical_memory<char>(MeshRootComp + SceneComponent::bComponentToWorldUpdated, 1);

                                // rootHead.y, rootHead.z


                            }
                        }

                    }
                }
            }
        }
  