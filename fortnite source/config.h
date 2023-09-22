#pragma once

static BOOL WritePrivateProfileInt(LPCSTR lpAppName, LPCSTR lpKeyName, int nInteger, LPCSTR lpFileName) {
    char lpString[1024];
    sprintf(lpString, _XOR_("%d"), nInteger);
    return WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName);
}
static BOOL WritePrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, float nInteger, LPCSTR lpFileName) {
    char lpString[1024];
    sprintf(lpString, _XOR_("%f"), nInteger);
    return WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName);
}
static float GetPrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, FLOAT flDefault, LPCSTR lpFileName)
{
    char szData[32];

    GetPrivateProfileStringA(lpAppName, lpKeyName, std::to_string(flDefault).c_str(), szData, 32, lpFileName);

    return (float)atof(szData);
}

static void Save_Settings(LPCSTR path)
{
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("crouching_esp")), visuals::Crouching, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("aiming_esp")), visuals::aiming, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("Glider_esp")), visuals::parachute, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("Radar_esp")), visuals::radar, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("3D_boxing")), external_def::g_3d_box, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("3D_Hand")), external_def::g_3d_hand, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("3D_Head")), external_def::g_3d_head, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_skeleton")), visuals::skeleton, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("Name_esp")), visuals::name, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_snaplines")), visuals::lines, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_linemode")), visuals::lineMode, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_debugname")), visuals::weapon, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_ammocount")), visuals::ammo, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_teamid")), visuals::teamid, path);

    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_item")), visuals::items, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_chest")), visuals::chest, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_ammobox")), visuals::ammobox, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_vehicle")), visuals::OutsideZone, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_supply")), visuals::supply, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_common")), items::Common, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_uncommon")), items::UnCommon, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_purple")), items::purple, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_rare")), items::rare, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_mythic")), items::mythic, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_gold")), items::gold, path);

    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimbot")), aimbot::aimbot, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_smooth")), aimbot::smooth, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov")), aimbot::aimfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov")), aimbot::adsfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth")), aimbot::aimspeed, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed")), aimbot::hipfire, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle")), aimbot::fovcircle, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimkey")), hotkeys::aimkey, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_hitbox")), aimbot::hitbox, path);

    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimbot2")), aimbot2::aimbot, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_smooth2")), aimbot2::smooth, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov2")), aimbot2::aimfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov2")), aimbot2::adsfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth2")), aimbot2::aimspeed, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed2")), aimbot2::hipfire, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle2")), aimbot2::fovcircle, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimkey2")), hotkeys2::aimkey2, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_hitbox2")), aimbot2::hitbox, path);

    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimbot3")), aimbot3::aimbot, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_smooth3")), aimbot3::smooth, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov3")), aimbot3::aimfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov3")), aimbot3::adsfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth3")), aimbot3::aimspeed, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed3")), aimbot3::hipfire, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle3")), aimbot3::fovcircle, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimkey3")), hotkeys3::aimkey3, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_hitbox3")), aimbot3::hitbox, path);

    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimbot4")), aimbot4::aimbot, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_smooth4")), aimbot4::smooth, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov4")), aimbot4::aimfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov4")), aimbot4::adsfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth4")), aimbot4::aimspeed, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed4")), aimbot4::hipfire, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle4")), aimbot4::fovcircle, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimkey4")), hotkeys4::aimkey4, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_hitbox4")), aimbot4::hitbox, path);

    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimbot5")), aimbot5::aimbot, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_smooth5")), aimbot5::smooth, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov5")), aimbot5::aimfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov5")), aimbot5::adsfov, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth5")), aimbot5::aimspeed, path);
    WritePrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed5")), aimbot5::hipfire, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle5")), aimbot5::fovcircle, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_aimkey5")), hotkeys5::aimkey5, path);
    WritePrivateProfileInt((_XOR_("Aimbot")), (_XOR_("save_var_hitbox5")), aimbot5::hitbox, path);

    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_invir")), colors::invisible[0], path);
    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_invig")), colors::invisible[1], path);
    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_invib")), colors::invisible[2], path);
    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_visibr")), colors::visible[0], path);
    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_visibg")), colors::visible[1], path);
    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_visibb")), colors::visible[2], path);
    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_fovr")), colors::fov[0], path);
    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_fovg")), colors::fov[1], path);
    WritePrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_fovb")), colors::fov[2], path);

    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_playerdistance")), visuals::MaxDistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_esqueletoistance")), visuals::MaxSkeletonDrawDistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_itemdistance")), visuals::ItemDistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_chestdistance")), visuals::ChestDistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_ammoboxdistance")), visuals::AmmoDistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_vehiceldistance")), visuals::VehicleDistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_supplydistance")), visuals::SupplyDistance, path);

    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance")), aimbot::aimdistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance2")), aimbot2::aimdistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance3")), aimbot3::aimdistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance4")), aimbot4::aimdistance, path);
    WritePrivateProfileInt((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance5")), aimbot4::aimdistance, path);

    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_rainbowmod")), color_random, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_redcol")), cross_r, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_greencol")), cross_g, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_bluecol")), cross_b, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_rainbowmodCrosshair")), color_crosshair, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_redcolcrosshair")), crosshair_r, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_greencolcrosshair")), crosshair_g, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_bluecolcrosshair")), crosshair_b, path);
    //esp new features
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_pyramideesp")), external_def::g_3d_box_triangle, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_parachute")), visuals::parachute, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_crouched")), visuals::Crouching, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_rainbow")), external_def::rainbow, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_blur")), design_blur_value, path);
    WritePrivateProfileInt((_XOR_("Colors")), (_XOR_("save_var_rounding")), rounding_value, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_item")), item_size, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_2DDD2D")), external_def::g_buried, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_2DDD2DSimple")), external_def::Esp_box, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_ColCheckVisR")), VisibleColCheck::r, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_ColCheckVisG")), VisibleColCheck::g, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_ColCheckVisB")), VisibleColCheck::b, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_ColCheckInVisR")), InVisibleColCheck::r, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_ColCheckInVisG")), InVisibleColCheck::g, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_ColCheckInVisB")), InVisibleColCheck::b, path);
    WritePrivateProfileInt((_XOR_("Visuals")), (_XOR_("save_var_RGBSETESP")), box_color, path);
    WritePrivateProfileFloat((_XOR_("Visuals")), (_XOR_("save_var_BOXSIZE")), boxsize, path);
  //  ImGui::InsertNotification({ ImGuiToastType_Success, 6000, "config saved !" });
}
static void Load_Settings(LPCSTR path)
{
    visuals::name = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("crouching_esp")), visuals::Crouching, path);
    visuals::name = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("aiming_esp")), visuals::aiming, path);
    visuals::name = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("Glider_esp")), visuals::parachute, path);
    visuals::name = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("Radar_esp")), visuals::radar, path);
    external_def::g_3d_box = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("3D_boxing")), external_def::g_3d_box, path);
    external_def::g_3d_hand = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("3D_Hand")), external_def::g_3d_hand, path);
    external_def::g_3d_head = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("3D_Head")), external_def::g_3d_head, path);
    visuals::name = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("Name_esp")), visuals::name, path);
    visuals::boxeinf = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_playeresp")), visuals::boxeinf, path);
    visuals::radar = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_radar")), visuals::radar, path);
    visuals::boxMode = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_boxstyle")), visuals::boxMode, path);
    visuals::skeleton = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_skeleton")), visuals::skeleton, path);
    visuals::name = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_playername")), visuals::name, path);
    visuals::outline = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_outline")), visuals::outline, path);
    visuals::lines = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_snaplines")), visuals::lines, path);
    visuals::lineMode = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_linemode")), visuals::lineMode, path);
    visuals::weapon = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_debugname")), visuals::weapon, path);
    visuals::ammo = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_ammocount")), visuals::ammo, path);
    visuals::teamid = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_teamid")), visuals::teamid, path);

    visuals::items = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_item")), visuals::items, path);
    visuals::chest = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_chest")), visuals::chest, path);
    visuals::ammobox = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_ammobox")), visuals::ammobox, path);
    visuals::OutsideZone = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_vehicle")), visuals::OutsideZone, path);
    visuals::supply = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_supply")), visuals::supply, path);
    items::Common = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_common")), items::Common, path);
    items::UnCommon = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_uncommon")), items::UnCommon, path);
    items::purple = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_purple")), items::purple, path);
    items::rare = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_rare")), items::rare, path);
    items::mythic = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_mythic")), items::mythic, path);
    items::gold = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_gold")), items::gold, path);

    aimbot::aimbot = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimbot")), aimbot::aimbot, path);
    aimbot::smooth = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_smooth")), aimbot::smooth, path);
    aimbot::aimfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov")), aimbot::aimfov, path);
    aimbot::adsfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov")), aimbot::adsfov, path);
    aimbot::aimspeed = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth")), aimbot::aimspeed, path);
    aimbot::hipfire = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed")), aimbot::hipfire, path);
    aimbot::fovcircle = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle")), aimbot::fovcircle, path);
    hotkeys::aimkey = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimkey")), hotkeys::aimkey, path);
    aimbot::hitbox = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_hitbox")), aimbot::hitbox, path);

    aimbot2::aimbot = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimbot2")), aimbot2::aimbot, path);
    aimbot2::smooth = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_smooth2")), aimbot2::smooth, path);
    aimbot2::aimfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov2")), aimbot2::aimfov, path);
    aimbot2::adsfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov2")), aimbot2::adsfov, path);
    aimbot2::aimspeed = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth2")), aimbot2::aimspeed, path);
    aimbot2::hipfire = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed2")), aimbot2::hipfire, path);
    aimbot2::fovcircle = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle2")), aimbot2::fovcircle, path);
    hotkeys2::aimkey2 = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimkey2")), hotkeys2::aimkey2, path);
    aimbot2::hitbox = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_hitbox2")), aimbot2::hitbox, path);

    aimbot3::aimbot = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimbot3")), aimbot3::aimbot, path);
    aimbot3::smooth = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_smooth3")), aimbot3::smooth, path);
    aimbot3::aimfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov3")), aimbot3::aimfov, path);
    aimbot3::adsfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov3")), aimbot3::adsfov, path);
    aimbot3::aimspeed = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth3")), aimbot3::aimspeed, path);
    aimbot3::hipfire = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed3")), aimbot3::hipfire, path);
    aimbot3::fovcircle = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle3")), aimbot3::fovcircle, path);
    hotkeys3::aimkey3 = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimkey3")), hotkeys3::aimkey3, path);
    aimbot3::hitbox = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_hitbox3")), aimbot3::hitbox, path);

    aimbot4::aimbot = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimbot4")), aimbot4::aimbot, path);
    aimbot4::smooth = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_smooth4")), aimbot4::smooth, path);
    aimbot4::aimfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov4")), aimbot4::aimfov, path);
    aimbot4::adsfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov4")), aimbot4::adsfov, path);
    aimbot4::aimspeed = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth4")), aimbot4::aimspeed, path);
    aimbot4::hipfire = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed4")), aimbot4::hipfire, path);
    aimbot4::fovcircle = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle4")), aimbot4::fovcircle, path);
    hotkeys4::aimkey4 = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimkey4")), hotkeys4::aimkey4, path);
    aimbot4::hitbox = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_hitbox4")), aimbot4::hitbox, path);

    aimbot5::aimbot = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimbot5")), aimbot5::aimbot, path);
    aimbot5::smooth = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_smooth5")), aimbot5::smooth, path);
    aimbot5::aimfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotfov5")), aimbot5::aimfov, path);
    aimbot5::adsfov = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_adsfov5")), aimbot5::adsfov, path);
    aimbot5::aimspeed = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_aimbotsmooth5")), aimbot5::aimspeed, path);
    aimbot5::hipfire = GetPrivateProfileFloat((_XOR_("Aimbot")), (_XOR_("save_var_hipfirespeed5")), aimbot5::hipfire, path);
    aimbot5::fovcircle = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_fovcircle5")), aimbot5::fovcircle, path);
    hotkeys5::aimkey5 = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_aimkey5")), hotkeys5::aimkey5, path);
    aimbot5::hitbox = GetPrivateProfileIntA((_XOR_("Aimbot")), (_XOR_("save_var_hitbox5")), aimbot5::hitbox, path);

    colors::invisible[0] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_invir")), colors::invisible[0], path);
    colors::invisible[1] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_invig")), colors::invisible[1], path);
    colors::invisible[2] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_invib")), colors::invisible[2], path);
    colors::visible[0] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_visibr")), colors::visible[0], path);
    colors::visible[1] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_visibg")), colors::visible[1], path);
    colors::visible[2] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_visibb")), colors::visible[2], path);
    colors::fov[0] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_fovr")), colors::fov[0], path);
    colors::fov[1] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_fovg")), colors::fov[1], path);
    colors::fov[2] = GetPrivateProfileFloat((_XOR_("Colors")), (_XOR_("save_var_fovb")), colors::fov[2], path);

    visuals::MaxDistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_playerdistance")), visuals::MaxDistance, path);
    visuals::MaxSkeletonDrawDistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_esqueletoistance")), visuals::MaxSkeletonDrawDistance, path);
    visuals::ItemDistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_itemdistance")), visuals::ItemDistance, path);
    visuals::ChestDistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_chestdistance")), visuals::ChestDistance, path);
    visuals::AmmoDistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_ammoboxdistance")), visuals::AmmoDistance, path);
    visuals::VehicleDistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_vehiceldistance")), visuals::VehicleDistance, path);
    visuals::SupplyDistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_supplydistance")), visuals::SupplyDistance, path);

    aimbot::aimdistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance")), aimbot::aimdistance, path);
    aimbot2::aimdistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance2")), aimbot2::aimdistance, path);
    aimbot3::aimdistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance3")), aimbot3::aimdistance, path);
    aimbot4::aimdistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance4")), aimbot4::aimdistance, path);
    aimbot5::aimdistance = GetPrivateProfileIntA((_XOR_("Distance")), (_XOR_("save_var_aimbotdistance5")), aimbot5::aimdistance, path);


    color_random = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_rainbowmod")), color_random, path);
    cross_r = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_redcol")), cross_r, path);
    cross_g = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_greencol")), cross_g, path);
    cross_b = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_bluecol")), cross_b, path);
    color_crosshair = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_rainbowmodCrosshair")), color_crosshair, path);
    crosshair_r = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_redcolcrosshair")), crosshair_r, path);
    crosshair_g = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_greencolcrosshair")), crosshair_g, path);
    crosshair_b = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_bluecolcrosshair")), crosshair_b, path);
    design_blur_value = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_blur")), design_blur_value, path);
    rounding_value = GetPrivateProfileIntA((_XOR_("Colors")), (_XOR_("save_var_rounding")), rounding_value, path);
    //esp new features
    external_def::g_3d_box_triangle = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_pyramideesp")), external_def::g_3d_box_triangle, path);
    visuals::parachute = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_parachute")), visuals::parachute, path);
    visuals::Crouching = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_crouched")), visuals::Crouching, path);
    external_def::rainbow = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_rainbow")), external_def::rainbow, path);
    item_size = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_item")), item_size, path);
    external_def::g_buried = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_2DDD2D")), external_def::g_buried, path);
    external_def::Esp_box = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_2DDD2DSimple")), external_def::Esp_box, path);
    VisibleColCheck::r = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_ColCheckVisR")), VisibleColCheck::r, path);
    VisibleColCheck::g = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_ColCheckVisG")), VisibleColCheck::g, path);
    VisibleColCheck::b = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_ColCheckVisB")), VisibleColCheck::b, path);
    InVisibleColCheck::r = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_ColCheckInVisR")), InVisibleColCheck::r, path);
    InVisibleColCheck::g = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_ColCheckInVisG")), InVisibleColCheck::g, path);
    InVisibleColCheck::b = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_ColCheckInVisB")), InVisibleColCheck::b, path);
    box_color = GetPrivateProfileIntA((_XOR_("Visuals")), (_XOR_("save_var_RGBSETESP")), box_color, path);
        boxsize = GetPrivateProfileFloat((_XOR_("Visuals")), (_XOR_("save_var_BOXSIZE")), boxsize, path);
  //  ImGui::InsertNotification({ ImGuiToastType_Success, 6000, "config loaded !" });
};