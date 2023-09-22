namespace AFortPlayerController_notify
{
	constexpr auto OnPlayerPawnPossessed = 0x8d0; // FMulticastInlineDelegate
	constexpr auto OnEnteredEditMode = 0x8e0; // FMulticastInlineDelegate
	constexpr auto OnPickupCreated = 0x8f0; // FMulticastInlineDelegate
	constexpr auto OnLoadoutChanged = 0x900; // FMulticastInlineDelegate
	constexpr auto OnViewTargetChanged = 0x940; // FMulticastInlineDelegate
	constexpr auto OnInputFiltered = 0x950; // FMulticastInlineDelegate
	constexpr auto OnFortPawnChangedEvent = 0x978; // FMulticastInlineDelegate
	constexpr auto OnControllerComponentAttachedEvent = 0x988; // FMulticastInlineDelegate
	constexpr auto bInPossession = 0xa81; // bool
	constexpr auto AircraftInputComponent = 0xb28; // UInputComponent*
	constexpr auto MiniMapInputComponent = 0xb30; // UFortMiniMapInputComponent*
	constexpr auto SprintOverrideComponent = 0xb38; // UActorComponent*
	constexpr auto SkydiveMusicAudioComp = 0xb40; // UAudioComponent*
	constexpr auto bFailedToRespawn = 0xb48; // char : 1
	constexpr auto bIsDisconnecting = 0xb48; // char : 1
	constexpr auto bIsBeingKicked = 0xb48; // char : 1
	constexpr auto bHasInitiallySpawned = 0xb48; // char : 1
	constexpr auto bAssignedStartSpawn = 0xb48; // char : 1
	constexpr auto bReadyToStartMatch = 0xb48; // char : 1
	constexpr auto bClientPawnIsLoaded = 0xb48; // char : 1
	constexpr auto bWantsWeaponAutoPickup = 0xb48; // char : 1
	constexpr auto SpawnLoc = 0xb50; // FVector
	constexpr auto NumPreviousSpawns = 0xb68; // int32_t
	constexpr auto bCanSpectateBot = 0xb6c; // bool
	constexpr auto OnBlueprintReadyCheckCompleted = 0xb70; // FMulticastInlineDelegate
	constexpr auto OnDelayForPreServerTransitionAnimationEvent = 0xb90; // FMulticastInlineDelegate
	constexpr auto SimpleLoadingScreenSoundMix = 0xbb8; // USoundMix*
	constexpr auto SprintOverrideAbilityGameplayTag = 0xbcc; // FGameplayTag
	constexpr auto ManagedAIs = 0xbd0; // TArray<AFortAIPawn*>
	constexpr auto MyFortPawn = 0xbe0; // AFortPlayerPawn*
	constexpr auto MyFortPawnBeforeTakeoverOfScriptedPawn = 0xbe8; // AFortPlayerPawn*
	constexpr auto ScriptedPawnControllerBeforeTakeover = 0xbf0; // AController*
	constexpr auto bHasClientFinishedLoading = 0xbf8; // bool
	constexpr auto bHasServerFinishedLoading = 0xbf9; // bool
	constexpr auto TimeStartedWaiting = 0xbfc; // float
	constexpr auto TimeFinishedNavigationBuild = 0xc00; // float
	constexpr auto MaterialParameterCollection = 0xc08; // UMaterialParameterCollection*
	constexpr auto bLoadingScreenDropped = 0xc19; // bool
	constexpr auto PendingSpectatorLocation = 0xc20; // FVector
	constexpr auto ActorUnderReticle = 0xc38; // TWeakObjectPtr<AActor>
	constexpr auto AutoFireReticleTarget = 0xc40; // TWeakObjectPtr<AActor>
	constexpr auto AutofireTimerHandle = 0xc48; // FTimerHandle
	constexpr auto WeakspotUnderReticle = 0xc58; // TWeakObjectPtr<ABuildingWeakSpot>
	constexpr auto ActiveWeakSpots = 0xc60; // TArray<FBuildingWeakSpotData>
	constexpr auto IdleKickLastTimeActive = 0xc70; // float
	constexpr auto LastTimeActive = 0xc74; // float
	constexpr auto bRevertPlayerListenerChange = 0xc98; // bool
	constexpr auto VehicleInputComponent = 0xcb8; // UInputComponent*
	constexpr auto bHoldingPrimaryFireFromTouch = 0xcc0; // bool
	constexpr auto bSupportNextPieceAssist = 0xcc1; // bool
	constexpr auto bAutoBuildForTrapPlacement = 0xcc2; // bool
	constexpr auto bAutoBuildForFloorTrapPlacement = 0xcc3; // bool
	constexpr auto bAutoBuildForWallTrapPlacement = 0xcc4; // bool
	constexpr auto bAutoBuildForCeilingTrapPlacement = 0xcc5; // bool
	constexpr auto bNoControllerLighting = 0xcc6; // bool
	constexpr auto ReturnToMainMenuTimeoutDelay = 0xcc8; // float
	constexpr auto OnQuestObjectiveStateChanged = 0xcd0; // FMulticastInlineDelegate
	constexpr auto LastDamager = 0xcf8; // AFortPlayerController*
	constexpr auto LastFallInstigator = 0xd08; // AFortPlayerController*
	constexpr auto LastDamagerCreditThresholdDropElim = 0xd14; // float
	constexpr auto LastDamagerCreditThresholdSelfElim = 0xd18; // float
	constexpr auto LastDamagerCreditThresholdStormElim = 0xd1c; // float
	constexpr auto bGiveLastDamagerElimCreditOnDrop = 0xd20; // bool
	constexpr auto bGiveLastDamagerElimCreditOnSelfDamage = 0xd21; // bool
	constexpr auto bGiveLastDamagerElimCreditOnStormDamage = 0xd22; // bool
	constexpr auto OnMcpProfilesInitializedEvent = 0xd88; // FMulticastInlineDelegate
	constexpr auto OnEnterVehicleDriver = 0xf28; // FMulticastInlineDelegate
	constexpr auto OnEnterVehiclePassenger = 0xf38; // FMulticastInlineDelegate
	constexpr auto OnExitVehicle = 0xf48; // FMulticastInlineDelegate
	constexpr auto OnFullyExitVehicle = 0xf58; // FMulticastInlineDelegate
	constexpr auto OnVehicleSeatChanged = 0xf68; // FMulticastInlineDelegate
	constexpr auto OnVehicleAbilitiesRemoved = 0xf78; // FMulticastInlineDelegate
	constexpr auto OnTetherChanged = 0xf88; // FMulticastInlineDelegate
	constexpr auto OnClientRefreshHUDForRespawn = 0xf98; // FMulticastInlineDelegate
	constexpr auto bHoldingObject = 0xfd0; // char : 1
	constexpr auto DBNOCarryInputComponent = 0xfd8; // UInputComponent*
	constexpr auto HeldObjectsInputComponent = 0xfe0; // UInputComponent*
	constexpr auto bWantsToSprint = 0x1030; // char : 1
	constexpr auto bHoldingSprint = 0x1030; // char : 1
	constexpr auto bSprintToggleable = 0x1030; // char : 1
	constexpr auto bForcingJogFromToggle = 0x1030; // char : 1
	constexpr auto bForceJogHeld = 0x1030; // char : 1
	constexpr auto bForceBinaryForward = 0x1030; // char : 1
	constexpr auto bSprintWasCanceledByReload = 0x1030; // char : 1
	constexpr auto bShouldAttemptReloadOnEquip = 0x1030; // char : 1
	constexpr auto bSprintBehaviorIsOverridden = 0x1031; // char : 1
	constexpr auto bSprintByDefaultWhenSprintIsOverridden = 0x1031; // char : 1
	constexpr auto bSprintByDefault = 0x1031; // char : 1
	constexpr auto bAutoRunOn = 0x1031; // char : 1
	constexpr auto bUseHoldToSwapPickup = 0x1031; // char : 1
	constexpr auto bTargetingToggleable = 0x1031; // char : 1
	constexpr auto bTargetingToggleableWithTouch = 0x1031; // char : 1
	constexpr auto bMovementDisabledDueToCancellableAction = 0x1031; // char : 1
	constexpr auto bIsPlayerActivelyMoving = 0x1032; // char : 1
	constexpr auto bPlaceHeldObjectPressed = 0x1032; // char : 1
	constexpr auto bJumpInputPressed = 0x1032; // char : 1
	constexpr auto InMovementCancellableAction = 0x1034; // int32_t
	constexpr auto bAllowHoldForAmmoCrafting = 0x1038; // bool
	constexpr auto bIsClientTimingOut = 0x1039; // bool
	constexpr auto ClientTimeoutBlockInputTime = 0x103c; // float
	constexpr auto LastMoveInputFrame = 0x1048; // uint64_t
	constexpr auto LastPressGamepadSprintTime = 0x1050; // float
	constexpr auto bAutoRunWasHoldingForward = 0x1054; // bool
	constexpr auto bAtNameBaseScreen = 0x1055; // bool
	constexpr auto OnSetFirstPersonCamera = 0x1058; // FMulticastInlineDelegate
	constexpr auto CinematicCameraClassOverride = 0x10d8; // UFortCinematicCamera*
	constexpr auto bOnPressExecuteJetpack = 0x10e0; // bool
	constexpr auto bShowHitMarkersForFriendlyFire = 0x1100; // bool
	constexpr auto bServerSideHitMarkers = 0x1101; // bool
	constexpr auto OnUiChoiceCompleted = 0x1118; // FMulticastInlineDelegate
	constexpr auto OnRegainedFocus = 0x1128; // FMulticastInlineDelegate
	constexpr auto OnReloadCancelingSprint = 0x1138; // FMulticastInlineDelegate
	constexpr auto OnOpenVoteDialog = 0x1160; // FMulticastInlineDelegate
	constexpr auto bGamepadAbilityPending = 0x13fc; // bool
	constexpr auto bForceAllowCursorMode = 0x13fd; // bool
	constexpr auto bForceAllowCameraMode = 0x13fe; // bool
	constexpr auto bSuppressEventNotifications = 0x1400; // bool
	constexpr auto LastSpotTime = 0x1470; // float
	constexpr auto CurrentMarks = 0x1488; // TArray<TWeakObjectPtr<AFortMarkActor>>
	constexpr auto LoopingUIFeedbackComponents = 0x1498; // TMap<FName, UAudioComponent*>
	constexpr auto PreviewAbility = 0x14e8; // UFortGameplayAbility*
	constexpr auto bDisableNativeHitMarker = 0x14f0; // bool
	constexpr auto bDisableNativeDamageNumbers = 0x14f1; // bool
	constexpr auto IntensityGraphInfo = 0x1510; // FAIDirectorDebugInfo
	constexpr auto PIDValuesGraphInfo = 0x1538; // FAIDirectorDebugInfo
	constexpr auto PIDContributionsGraphInfo = 0x1560; // FAIDirectorDebugInfo
	constexpr auto AIDirectorDataManager = 0x1588; // AFortAIDirectorDataManager*
	constexpr auto MusicManager = 0x1590; // AFortMusicManager*
	constexpr auto OnBuildPreviewMarkerVisibilityChanged = 0x1598; // FMulticastInlineDelegate
	constexpr auto OnWeakSpotReset = 0x15a8; // FMulticastInlineDelegate
	constexpr auto bUsePredictedBuildingActors = 0x15c8; // bool
	constexpr auto bRegisterPredictedBuildingActorsWithGrid = 0x15c9; // bool
	constexpr auto bPredictedBuildingWallsHaveNoCollision = 0x15ca; // bool
	constexpr auto PredictedActorLifespan = 0x15cc; // float
	constexpr auto PredictedBuildingSMActors = 0x15d0; // TArray<TWeakObjectPtr<ABuildingSMActor>>
	constexpr auto BuildPreviewModeInputComponent = 0x1790; // UInputComponent*
	constexpr auto BuildPreviewMarker = 0x1798; // ABuildingPlayerPrimitivePreview*
	constexpr auto BuildPreviewMarkerExtraPiece = 0x17a0; // ABuildingPlayerPrimitivePreview*
	constexpr auto bAllowBuildingPreviewAutoRotation = 0x1810; // bool
	constexpr auto bRequireTraceToExistingBuildingToSetContext = 0x1811; // bool
	constexpr auto bAllowTraceToExistingBuildingToSetContextToRedirectToBlockingBuilding = 0x1812; // bool
	constexpr auto bRequireTraceToExistingBuildingToSetContextExcludeCurrentContext = 0x1813; // bool
	constexpr auto TargetedBuilding = 0x18e0; // ABuildingActor*
	constexpr auto TargetedVehicle = 0x18e8; // AActor*
	constexpr auto TargetedFortPawn = 0x18f0; // AFortPawn*
	constexpr auto ContextualConversionClass = 0x18f8; // ABuildingSMActor*
	constexpr auto StartUpgradeSound = 0x1900; // TSoftObjectPtr<USoundBase>
	constexpr auto HighlightedPrimaryBuildings = 0x1928; // TArray<ABuildingActor*>
	constexpr auto HighlightedInteractionBuildings = 0x1938; // TArray<ABuildingActor*>
	constexpr auto HighlightedPrimaryBuilding = 0x1948; // TWeakObjectPtr<ABuildingActor>
	constexpr auto BuildPreviewMarkerParentMaterial = 0x1950; // TSoftObjectPtr<UMaterialInterface>
	constexpr auto BuildPreviewMarkerMIDs = 0x1978; // TArray<UMaterialInstanceDynamic*>
	constexpr auto BuildPreviewRotationIterations = 0x1988; // char
	constexpr auto bBuildPreviewMirrored = 0x198c; // char : 1
	constexpr auto BuildPreviewMarkerOptionalAdjustment = 0x1990; // EFortBuildPreviewMarkerOptionalAdjustment
	constexpr auto bBuildFree = 0x1994; // char : 1
	constexpr auto bCraftFree = 0x19cc; // char : 1
	constexpr auto CurrentCostInfoType = 0x19d0; // EFortCostInfoTypes
	constexpr auto CurrentBuildableClass = 0x19d8; // ABuildingSMActor*
	constexpr auto PreviousBuildableClass = 0x19e0; // ABuildingSMActor*
	constexpr auto CurrentResourceLevel = 0x19e8; // EFortResourceLevel
	constexpr auto CurrentResourceType = 0x19e9; // EFortResourceType
	constexpr auto LastBuildableStateData0xc = 0x19f0; // FLastBuildableState
	constexpr auto QueuedDamageNumbers = 0x1ac0; // TArray<FFortDamageNumberInfo>
	constexpr auto DamageNumbersActor = 0x1ad0; // AFortDamageNumbersActor*
	constexpr auto EditModeInputComponent = 0x1ad8; // UInputComponent*
	constexpr auto EditBuildingActor = 0x1ae0; // ABuildingSMActor*
	constexpr auto EditModeDistance = 0x1ae8; // float
	constexpr auto LastBuildPreviewGridSnapLoc = 0x1af0; // FVector
	constexpr auto LastBuildPreviewGridSnapRot = 0x1b08; // FRotator
	constexpr auto LastBuildPreviewGridSnapCentroid = 0x1b20; // FVector
	constexpr auto PickerInputComponent = 0x1b38; // UInputComponent*
	constexpr auto TrapPickerDecoHelper = 0x1b40; // AFortDecoHelper*
	constexpr auto TouchEditResults = 0x1b48; // TArray<FHitResult>
	constexpr auto bBuildingPlacementTraceSkipInitialPenetrationOfBuildingSMActor = 0x1b59; // bool
	constexpr auto bBuildingPlacementTraceSkipInitialPenetrationOfStaticMesh = 0x1b5a; // bool
	constexpr auto ClientQuickBars = 0x1ba0; // AFortQuickBars*
	constexpr auto RecentlyRemovedQuickbarInfo = 0x1bb0; // TArray<FRecentlyRemovedQuickbarInfo>
	constexpr auto DelayedQuickBarActions = 0x1c10; // FDelayedQuickBarActionContainer
	constexpr auto ClientProcessedQuickBarActions = 0x1d30; // TSet<uint32_t>
	constexpr auto bShouldForceDeleteDroppedItems = 0x1d80; // bool
	constexpr auto QueuedItemsToDrop = 0x1dc0; // FQueuedItemsToDropViaPickup
	constexpr auto bAutoEquipBetterItems = 0x1e90; // char : 1
	constexpr auto WorldInventoryClass = 0x1e98; // AFortInventory*
	constexpr auto WorldInventory = 0x1ea0; // AFortInventory*
	constexpr auto OutpostInventory = 0x1ea8; // AFortInventory*
	constexpr auto ViewTargetInventory = 0x1eb0; // AFortInventory*
	constexpr auto bHasInitializedWorldInventory = 0x1f04; // char : 1
	constexpr auto bHasInitializedHeroInventory = 0x1f04; // char : 1
	constexpr auto bAccountInventoryWasUpdated = 0x1f04; // char : 1
	constexpr auto bForceWorldInventoryUpdate = 0x1f04; // char : 1
	constexpr auto bIsSavingGadgetLoadout = 0x1f04; // char : 1
	constexpr auto BotPilot = 0x1fd0; // UFortClientPilot_Base*
	constexpr auto BotManager = 0x1ff0; // UFortClientBotManager*
	constexpr auto ClientBotManagerClass = 0x2000; // UFortClientBotManager*
	constexpr auto CosmeticLoadoutPC = 0x2020; // FFortAthenaLoadout
	constexpr auto LocalPawnCustomizationAssetLoader = 0x2198; // UFortCustomizationAssetLoader*
	constexpr auto bDropWeaponsDuringAllMissionStates = 0x21b8; // bool
	constexpr auto LatestRewardReport = 0x21d8; // FFortRewardReport
	constexpr auto MyPlayerInfo = 0x2248; // UFortRegisteredPlayerInfo*
	constexpr auto UpdatedObjectiveStats = 0x2250; // TArray<FFortUpdatedObjectiveStat>
	constexpr auto bHasUnsavedPrimaryMissionProgress = 0x2260; // bool
	constexpr auto StatManager = 0x22a0; // UStatManager*
	constexpr auto HeartbeatManager = 0x22a8; // UHeartbeatManager*
	constexpr auto StatEventManager = 0x22b0; // UFortStatEventManager*
	constexpr auto CachedPersistentGameplayStats = 0x22b8; // FFortPersistentGameplayStatContainer
	constexpr auto LastEmotePlayed = 0x22d8; // UFortMontageItemDefinitionBase*
	constexpr auto EmoteUsageCounts = 0x22e0; // TMap<UFortMontageItemDefinitionBase*, int32_t>
	constexpr auto AnalyticsBuildingWallTooLowLocations = 0x2330; // TArray<FVector>
	constexpr auto NearbyEmotingPawns = 0x2340; // TSet<AFortPlayerPawn*>
	constexpr auto NearbyEmotingPawnCount = 0x2390; // TMap<FName, int32_t>
	constexpr auto McpProfileGroup = 0x23e0; // UMcpProfileGroup*
	constexpr auto CommonPublicMcpProfile = 0x23e8; // UFortMcpProfileCommonPublic*
	constexpr auto CommonCoreMcpProfile = 0x23f0; // UFortMcpProfileCommonCore*
	constexpr auto MainMcpProfile = 0x23f8; // UFortMcpProfileCampaign*
	constexpr auto AthenaProfile = 0x2400; // UFortMcpProfileAthena*
	constexpr auto MetadataProfile = 0x2408; // UFortMcpProfileMetadata*
	constexpr auto CreativeModeProfile = 0x2410; // UFortMcpProfileCreative*
	constexpr auto TutorialCompletedState = 0x2418; // EFortPCTutorialCompletedState
	constexpr auto bShouldReceiveCriticalMatchBonus = 0x2450; // bool
	constexpr auto bIgnoreExperienceOwnership = 0x2451; // bool
	constexpr auto OnPlayerChangedBuildMode = 0x2458; // FMulticastInlineDelegate
	constexpr auto OnAutoRunEnabled = 0x2468; // FMulticastInlineDelegate
	constexpr auto VoiceInputSourceEffectPresetChain = 0x25d8; // USoundEffectSourcePresetChain*
	constexpr auto LocationUnderReticle = 0x2680; // FVector
	constexpr auto bEnableVoiceChatPTT = 0x2698; // char : 1
	constexpr auto bVoiceChatPTTTransmit = 0x2698; // char : 1
	constexpr auto bInfiniteAmmo = 0x2698; // char : 1
	constexpr auto bInfiniteConsumables = 0x2698; // char : 1
	constexpr auto bInfiniteMagazine = 0x2698; // char : 1
	constexpr auto bNoCoolDown = 0x2698; // char : 1
	constexpr auto bInfiniteDurability = 0x2698; // char : 1
	constexpr auto bUsePickers = 0x2698; // char : 1
	constexpr auto bPickerOpen = 0x2699; // char : 1
	constexpr auto bPickerEnabled = 0x2699; // char : 1
	constexpr auto bCheatGhost = 0x2699; // char : 1
	constexpr auto bCheatFly = 0x2699; // char : 1
	constexpr auto bEnableShotLogging = 0x2699; // char : 1
	constexpr auto bIsNearActiveEncounters = 0x2699; // char : 1
	constexpr auto OverriddenBackpackSize = 0x269c; // int32_t
	constexpr auto CurrentReplaySpotLight = 0x26a0; // AFortReplayMovableSpotLight*
	constexpr auto AimHelpMode = 0x26a8; // uint32_t
	constexpr auto JumpStaminaCost = 0x26ac; // EFortJumpStaminaCost
	constexpr auto CameraPrototypeName = 0x26b0; // FName
	constexpr auto bHideHudEnglishText = 0x26f0; // bool
	constexpr auto bAutoChangeMaterial = 0x26f1; // bool
	constexpr auto bServerAutoChangeMaterial = 0x26f2; // bool
	constexpr auto bPeripheralLightingEnabled = 0x26f3; // bool
	constexpr auto bRudderControlEnabled = 0x26f4; // bool
	constexpr auto RudderDeadZone = 0x26f8; // float
	constexpr auto RudderMaxThrottle = 0x26fc; // float
	constexpr auto ActiveSprayInstances = 0x2700; // TArray<AFortSprayDecalInstance*>
	constexpr auto ActiveToyInstances = 0x2710; // TArray<AActor*>
	constexpr auto ToySummonCounts = 0x2720; // TMap<ClassPtrProperty, int32_t>
	constexpr auto bSyncPeripheralLightingWithEmoteMusic = 0x2770; // bool
	constexpr auto bPushEmoteAudioDataToCosmeticMaterials = 0x2771; // bool
	constexpr auto LastEmoteMusicFFT100hz = 0x2774; // float
	constexpr auto LastEmoteMusicFFT2000hz = 0x2778; // float
	constexpr auto EmoteMusicBeatThreshold = 0x277c; // float
	constexpr auto EmoteMusicEnvelopeBeatCount = 0x2780; // float
	constexpr auto bZeroingCameraRoll = 0x28d8; // bool
	constexpr auto bTryPickupSwap = 0x28d9; // bool
	constexpr auto bClientSideEditPrediction = 0x28da; // bool
	constexpr auto ClientSideEditPredictionTimeout = 0x28dc; // float
	constexpr auto PendingEnterEditModeActor = 0x28e8; // ABuildingSMActor*
	constexpr auto RandomCharacterIndex = 0x28f0; // int32_t
	constexpr auto AntiAddictionPlayTimeMultiplier = 0x28f4; // float
	constexpr auto bUsesWidgetForFPSDisplay = 0x28f8; // bool
	constexpr auto bShowFPS = 0x28f9; // bool
	constexpr auto OnShowFPSChange = 0x2900; // FMulticastInlineDelegate
	constexpr auto bShowTemperature = 0x2910; // bool
	constexpr auto OnShowTemperatureChange = 0x2918; // FMulticastInlineDelegate
	constexpr auto LockOnInfo = 0x2980; // FLockOnInfo
	constexpr auto bLockPrimaryInputMethodToMouse = 0x29d0; // bool
	constexpr auto IndicatorManager = 0x29e8; // UFortIndicatorManager*
	constexpr auto bFinalXPUpdateFailed = 0x2a00; // bool
	constexpr auto TestUserWidget = 0x2a08; // UUserWidget*
	constexpr auto PreviousStasisMode = 0x2a10; // EFortPawnStasisMode
	constexpr auto BattleMapSpectatorClass = 0x2a18; // ABattleMapPawnLive*
	constexpr auto bReleaseBuildingContextOnPlace = 0x2a3d; // bool
	constexpr auto TurboPlaceFirstInterval = 0x2a40; // float
	constexpr auto TurboPlaceInterval = 0x2a44; // float
	constexpr auto bCreativeTurboDelete = 0x2a48; // bool
	constexpr auto TurboDeleteFirstInterval = 0x2a4c; // float
	constexpr auto TurboDeleteInterval = 0x2a50; // float
	constexpr auto bTurboBuild = 0x2a55; // bool
	constexpr auto TurboBuildFirstInterval = 0x2a58; // float
	constexpr auto TurboBuildRequestFailedInterval = 0x2a5c; // float
	constexpr auto TurboBuildInterval = 0x2a60; // float
	constexpr auto FortControllerComponent_Telemetry = 0x2a70; // UFortControllerComponent_Telemetry*
	constexpr auto InventoryNetworkManagementComponent = 0x2a78; // UFortControllerComponent_InventoryNetworkManagement*
	constexpr auto InteractionComponent = 0x2a80; // UFortControllerComponent_Interaction*
	constexpr auto QuestsComponent = 0x2a88; // UFortControllerComponent_Quests*
	constexpr auto QuestGatesComponent = 0x2a90; // UFortControllerComponent_QuestGates*
	constexpr auto QuickEditComponent = 0x2a98; // UFortControllerComponent_QuickEdit*
	constexpr auto SmartBuildComponent = 0x2aa0; // UFortControllerComponent_SmartBuild*
	constexpr auto CollectionsComponent = 0x2aa8; // UFortControllerComponent_Collections*
	constexpr auto PendingExecuteInventoryItemHandle = 0x2ab0; // FItemVariantHandle
	constexpr auto QuickHealItemPickerClass = 0x2ae0; // UQuickHealItemPicker*
	constexpr auto OnPlayerSpawnedBuildingActor = 0x2ae8; // FMulticastInlineDelegate
	constexpr auto MeshParentIds = 0x2af8; // TArray<FString>
	constexpr auto OnToggleFullscreenMap = 0x2b08; // FMulticastInlineDelegate
	constexpr auto OnBoundActionFreed = 0x2b90; // FMulticastInlineDelegate
	constexpr auto ForcedInputRotationSpeed = 0x2c58; // float
	constexpr auto PendingClientRestartPawn = 0x2c60; // APawn*
	constexpr auto TargetGrids = 0x2c88; // TArray<FFortWorldPartitionGridRangeOverrides>
	constexpr auto BusHeightScaleNonBusSkydiving = 0x2ca0; // FString
}
void hook_notify()
{
    if (enable_exploit_server)
    {
        if (LocalPawn_base)
        {
            if (enable_server_info)
            {
                DWORD_PTR Player = ctx->read_physical_memory<DWORD_PTR>(uworld + 0x30);
                if (Player)
                {
                    int ActorCount = ctx->read_physical_memory<int>(Player + 0xA0);
                    uint64_t AActors = ctx->read_physical_memory<uint64_t>(Player + 0x98);
                    for (int i = 0; i < ActorCount; i++)
                    {
                        uintptr_t CurrentItemPawn = ctx->read_physical_memory<uintptr_t>(AActors + (i * sizeof(uintptr_t)));



                        //mesh
                        auto mesh = ctx->read_physical_memory<uintptr_t>(closestPawnExploit + Character::Mesh);
                        uint64_t bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x5F8);
                        if (!bonearray) bonearray = ctx->read_physical_memory<uint64_t>(mesh + 0x608);
                        FTransform ComponentToWorld = ctx->read_physical_memory<FTransform>(mesh + 0x240);
                        Vector3 rootHead;
                        Vector3 foot;
                        rootHead = GetBoneWithRotation(mesh, 106);
                        foot = GetBoneWithRotation(mesh, 0);


                        //playercontroller
                        auto dyingCheck = ctx->read_physical_memory<char>(CurrentItemPawn + FortPawn::bIsDying);
                        auto kicked = ctx->read_physical_memory<char>(CurrentItemPawn + AFortPlayerController_notify::bIsBeingKicked);
						auto knocked = ctx->read_physical_memory<char>(CurrentItemPawn + FortPawn::bIsKnockedback);
                        if (LocalPawn_base)
                        {

                            if (dyingCheck)
                            {
                               // ImGui::InsertNotification({ ImGuiToastType_Info, 800, "Player : dead" });
                            }
							if (kicked)
							{
								//ImGui::InsertNotification({ ImGuiToastType_Info, 800, "Player : kicked" });
							}
							if (knocked)
							{
							//	ImGui::InsertNotification({ ImGuiToastType_Info, 800, "Player : knocked back" });
							}
						
                        }            
                    }
                }
            }
        }
    }
}

