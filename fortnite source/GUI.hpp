#include <imgui/imgui_internal.h>
#include <blur.hpp>
static int curtab;
static bool checkbox;
static float slider;
static float anti;
static float aim;
static int slider1;

const char* weapon_selection[]{ "ASSAULT", "SHOTGUN", "SMG", "SNIPER" };
static int curWeapon = 0;
static int curTheme = 2;
static int combo;
static int selectedItem = 0;
static bool selected[4];
static std::string previewValue = "";

float r1;
float g1;
float b2;
float a1 = 0.5;
static const char* type[]{ "Fake-lag", "Desync" };
static int combo2;
float color_edit4[4] = { 1.00f, 0.00f, 0.20f, 0.80f };

float accent_color[4] = { 1.00f, 0.00f, 0.20f, 0.80f };

static int select_count = 0;
int tab_count = 0, tabs = 0;
bool active = false;
float size_child = 0;


#include <windows.h>
#include <Lmcons.h>
#include <iostream>
#include <stdafx.hpp>



int hitler()
{
    return 0;
}

static auto menu() -> void
{
    ImGuiStyle* style = &ImGui::GetStyle();


    ImVec4 colorback = ImColor(16, 16, 16, design_blur_value);

    static int MenuTab = 0;
    static int VisualTab = 0;
    static int VisualTab_ESP = 0;
    static int VisualTab_Misc = 0;
    static auto flags = ImGuiWindowFlags_NoCollapse || ImGuiWindowFlags_NoResize || ImGuiWindowFlags_NoScrollbar;
    float TextSpaceLine = 90.f;
    float SpaceLineTwo = 280.f;
    float SpaceLineThr = 420.f;


    ImGui::SetNextWindowSize(ImVec2(500.0f, 700.0f));
    ImGui::Begin(_XOR_("INFARCTED"), &menu_key, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse); // Create a window called "Hello, world!" and append into it.
    {




        if (ImGui::BeginTabBar(_XOR_("TabRegion")))
        {
            if (ImGui::BeginTabItem(_XOR_("Aimbot")))
            {
                if (ImGui::CollapsingHeader(_XOR_("Weapon Configuration")))
                {
                    ImGui::Combo((_XOR_(" ")), &curWeapon, weapon_selection, IM_ARRAYSIZE(weapon_selection));
                    if (curWeapon == 0)
                    {
                        ImGui::Checkbox((_XOR_("Aimbot")), &aimbot::aimbot);
                        ImGui::SameLine();
                        ImGui::Checkbox((_XOR_("Smooth")), &aimbot::smooth);
                        ImGui::Checkbox((_XOR_("Show FOV")), &aimbot::fovcircle);
                        ImGui::SameLine();
                        ImGui::Checkbox((_XOR_("FOV Size (By Angle)")), &external_def::Settings::fovCircleByAngle);
                        if (!external_def::Settings::fovCircleByAngle)
                        {
                            ImGui::Text((_XOR_("FOV: ")));
                            ImGui::SliderFloat(_XOR_("##fovkrai"), &aimbot::aimfov, 1.f, 700.f, _XOR_("%.2f"));
                            ImGui::Text((_XOR_("FOV If Aiming: ")));
                            ImGui::SliderFloat(_XOR_("##ads"), &aimbot::adsfov, 1.f, 700.f, _XOR_("%.2f"));
                        }
                        ImGui::Text((_XOR_("Smooth: ")));
                        ImGui::SliderFloat(_XOR_("##smoothkrai"), &aimbot::aimspeed, 1.0f, 50.0f, _XOR_("%.2f"));
                        ImGui::Text((_XOR_("Aimbot Distance: ")));
                        ImGui::SliderFloat(_XOR_("##aimdistance"), &aimbot::aimdistance, 1.f, 300.0f, _XOR_("%.2f"));
                        ImGui::Text((_XOR_("Aim Key: ")));
                        ImGui::Checkbox((_XOR_("Controller LT/L2 = ADS")), &hotkey_manettte::enablecontroller);
                        if (!hotkey_manettte::enablecontroller)
                        {
                            HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);
                        }
                        ImGui::Text((_XOR_("Hitbox: ")));
                        ImGui::Combo((_XOR_("##BONES")), &aimbot::hitbox, Hitbox, IM_ARRAYSIZE(Hitbox));
                    }
                    else if (curWeapon == 1)
                    {
                        ImGui::Checkbox((_XOR_("Aimbot")), &aimbot2::aimbot);
                        ImGui::SameLine();
                        ImGui::Checkbox((_XOR_("Smooth")), &aimbot2::smooth);
                        ImGui::Checkbox((_XOR_("Show FOV")), &aimbot2::fovcircle);
                        ImGui::SameLine();
                        ImGui::Checkbox((_XOR_("FOV Size (By Angle)")), &external_def::Settings::fovCircleByAngle);
                        if (!external_def::Settings::fovCircleByAngle)
                        {
                            ImGui::Text((_XOR_("FOV: "))); ;
                            ImGui::SliderFloat(_XOR_("##fovkrai2"), &aimbot2::aimfov, 1.f, 700.f, _XOR_("%.2f"));
                            ImGui::Text((_XOR_("FOV If Aiming: ")));
                            ImGui::SliderFloat(_XOR_("##ads2"), &aimbot2::adsfov, 1.f, 700.f, _XOR_("%.2f"));
                        }
                        ImGui::Text((_XOR_("Smooth: ")));
                        ImGui::SliderFloat(_XOR_("##smoothkrai2"), &aimbot2::aimspeed, 1.0f, 50.0f, _XOR_("%.2f"));
                        ImGui::Text((_XOR_("Aimbot Distance: ")));
                        ImGui::SliderFloat(_XOR_("##aimdistance2"), &aimbot2::aimdistance, 1.f, 300.0f, _XOR_("%.2f"));
                        ImGui::Text((_XOR_("Aim Key: ")));
                        ImGui::Checkbox((_XOR_("Controller LT/L2 = ADS")), &hotkey_manettte::enablecontroller);
                        if (!hotkey_manettte::enablecontroller)
                        {
                            HotkeyButton(hotkeys2::aimkey2, ChangeKey2, keystatus);
                        }
                        ImGui::Text((_XOR_("Hitbox: ")));
                        ImGui::Combo((_XOR_("##BONES2")), &aimbot2::hitbox, Hitbox, IM_ARRAYSIZE(Hitbox));


                    }
                    else if (curWeapon == 2)
                    {
                        ImGui::Checkbox((_XOR_("Aimbot")), &aimbot3::aimbot);
                        ImGui::SameLine();
                        ImGui::Checkbox((_XOR_("Smooth")), &aimbot3::smooth);
                        ImGui::Checkbox((_XOR_("Show FOV")), &aimbot3::fovcircle);
                        ImGui::SameLine();
                        ImGui::Checkbox((_XOR_("FOV Size (By Angle)")), &external_def::Settings::fovCircleByAngle);
                        if (!external_def::Settings::fovCircleByAngle)
                        {
                            ImGui::Text((_XOR_("FOV: ")));
                            ImGui::SliderFloat(_XOR_("##fovkrai3"), &aimbot3::aimfov, 1.f, 700.f, _XOR_("%.2f"));
                            ImGui::Text((_XOR_("FOV If Aiming: ")));
                            ImGui::SliderFloat(_XOR_("##ads3"), &aimbot3::adsfov, 1.f, 700.f, _XOR_("%.2f"));
                        }
                        ImGui::Text((_XOR_("Smooth: ")));
                        ImGui::SliderFloat(_XOR_("##smoothkrai3"), &aimbot3::aimspeed, 1.0f, 50.0f, _XOR_("%.2f"));
                        ImGui::Text((_XOR_("Aimbot Distance: ")));
                        ImGui::SliderFloat(_XOR_("##aimdistance3"), &aimbot3::aimdistance, 1.f, 300.0f, _XOR_("%.2f"));
                        ImGui::Text((_XOR_("Aim Key: ")));
                        ImGui::Checkbox((_XOR_("Controller LT/L2 = ADS")), &hotkey_manettte::enablecontroller);
                        if (!hotkey_manettte::enablecontroller)
                        {
                            HotkeyButton(hotkeys3::aimkey3, ChangeKey3, keystatus);
                            //  ImGui::Keybind("Keybind", &hotkeys3::aimkey3, &keystatus);
                        }
                        ImGui::Text((_XOR_("Hitbox: ")));
                        ImGui::Combo((_XOR_("##BONES3")), &aimbot3::hitbox, Hitbox, IM_ARRAYSIZE(Hitbox));
                    }
                    else if (curWeapon == 3)
                    {
                        ImGui::Checkbox((_XOR_("Aimbot")), &aimbot5::aimbot);
                        ImGui::SameLine();
                        ImGui::Checkbox((_XOR_("Smooth")), &aimbot5::smooth);
                        ImGui::Checkbox((_XOR_("Show FOV")), &aimbot5::fovcircle);
                        ImGui::SameLine();
                        ImGui::Checkbox((_XOR_("FOV Size (By Angle)")), &external_def::Settings::fovCircleByAngle);
                        if (!external_def::Settings::fovCircleByAngle)
                        {
                            ImGui::Text((_XOR_("FOV: ")));
                            ImGui::SliderFloat(_XOR_("##fovkrai4"), &aimbot5::aimfov, 1.f, 700.f, _XOR_("%.2f"));
                            ImGui::Text((_XOR_("FOV If Aiming: ")));
                            ImGui::SliderFloat(_XOR_("##ads5"), &aimbot5::adsfov, 1.f, 700.f, _XOR_("%.2f"));
                        }
                        ImGui::Text((_XOR_("Smooth: ")));
                        ImGui::SliderFloat(_XOR_("##smoothkrai4"), &aimbot5::aimspeed, 1.0f, 50.0f, _XOR_("%.2f"));
                        ImGui::Text((_XOR_("Aimbot Distance: ")));
                        ImGui::SliderFloat(_XOR_("##aimdistance5"), &aimbot5::aimdistance, 1.f, 300.0f, _XOR_("%.2f"));
                        ImGui::Text((_XOR_("Aim Key: ")));
                        ImGui::Checkbox((_XOR_("Controller LT/L2 = ADS")), &hotkey_manettte::enablecontroller);
                        if (!hotkey_manettte::enablecontroller)
                        {
                            HotkeyButton(hotkeys5::aimkey5, ChangeKey5, keystatus);
                        }
                        ImGui::Text((_XOR_("Hitbox: ")));
                        ImGui::Combo((_XOR_("##BONES4")), &aimbot5::hitbox, Hitbox, IM_ARRAYSIZE(Hitbox));
                    }
                }

                if (ImGui::CollapsingHeader(_XOR_("Crosshair")))
                {
                    ImGui::Checkbox(_XOR_("RGB Mode"), &color_crosshair);

                    ImGui::Checkbox(_XOR_("Cross (EFK)"), &external_def::Settings::cross_hair);
                    ImGui::SameLine();
                    ImGui::Checkbox(_XOR_("Cross"), &external_def::g_crossh_int);
                    ImGui::SameLine();
                    ImGui::Checkbox(_XOR_("Nazi"), &external_def::Settings::cross_hair_nazi);
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem(_XOR_("Visual")))
            {
                if (ImGui::CollapsingHeader(_XOR_("Player box")))
                {

                    ImGui::Checkbox((_XOR_("Box (2D Corner)")), &external_def::g_buried);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Box (2D)")), &external_def::Esp_box);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Box (3D)")), &external_def::g_3d_box);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Box (3D Pyramide)")), &external_def::g_3d_box_triangle);

                    ImGui::Checkbox((_XOR_("Box (Head)")), &external_def::g_3d_head);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Show Lines")), &visuals::lines);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Skeleton")), &visuals::skeleton);

                }
                if (ImGui::CollapsingHeader(_XOR_("Player information")))
                {
                    ImGui::Checkbox((_XOR_("Show Distance")), &visuals::name);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Parachute open check")), &visuals::parachute);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Aiming check")), &visuals::aiming);

                    ImGui::Checkbox((_XOR_("Crouched check")), &visuals::Crouching);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Team-ID")), &visuals::teamid);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("WeaponName")), &visuals::weapon);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Get Ammo")), &visuals::ammo);

                    ImGui::Checkbox((_XOR_("Is a bot")), &visuals::CheckBOT);

                }

                if (ImGui::CollapsingHeader(_XOR_("Entity (Items)")))
                {
                    ImGui::Checkbox((_XOR_("Draw Items")), &visuals::items);
                    ImGui::Checkbox((_XOR_("Weapons : Common")), &items::Common);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Weapons : Green")), &items::UnCommon);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Weapons : Blue")), &items::rare);

                    ImGui::Checkbox((_XOR_("Weapons : Purple")), &items::purple);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Weapons : Gold")), &items::gold);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Weapons : Mythic")), &items::mythic);
                    ImGui::Text(_XOR_("Size Text"));
                    ImGui::SliderFloat(_XOR_("item size"), &item_size, 5.0f, 30.0f, _XOR_("%.2f"));

                }


                if (ImGui::CollapsingHeader(_XOR_("Box settings")))
                {
                    ImGui::Text((_XOR_("ESP Distance")));
                    ImGui::SliderFloat(_XOR_("espdistance"), &visuals::MaxDistance, 1.0f, 500.0f, _XOR_("%.2f"));
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Rainbow ESP")), &box_color);
                    ImGui::Text(_XOR_("Lines Style"));
                    ImGui::Combo((_XOR_("##LINESSTYLE")), &visuals::lineMode, linesMode, IM_ARRAYSIZE(linesMode));
                    ImGui::SameLine();
                    ImGui::SliderFloat(_XOR_("BoxSize"), &boxsize, 0.400f, 4.800f, _XOR_("%.2f"));


                }


                if (ImGui::CollapsingHeader(_XOR_("Radar")))
                {
                    //ImGui::Checkbox((_XOR_("Notify game information")), &external_def::bNotify_info);
                    ImGui::Checkbox((_XOR_("Draw Radar")), &visuals::radar);
                    ImGui::Text(_XOR_("Zoom of radar"));
                    ImGui::SliderFloat(_XOR_("Radar zoom"), &zoom, 30.f, 300.f, _XOR_("%.2f"));


                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem(_XOR_("Engine")))
            {
                if (ImGui::CollapsingHeader(_XOR_("Color Engine")))
                {
                    if (ImGui::Button((_XOR_("Red Game + New HUD"))))
                    {
                        EngineVar::ColorUI = false;
                        EngineVoid::changeREDREEL();
                    }
                    ImGui::SameLine();
                    if (ImGui::Button((_XOR_("Green Game + New HUD"))))
                    {
                        EngineVar::ColorUI = false;
                        EngineVoid::changeTURQUASE();
                    }
                    ImGui::SameLine();
                    if (ImGui::Button((_XOR_("Blue Game + New HUD"))))
                    {
                        EngineVar::ColorUI = false;
                        EngineVoid::changeBLUE();
                    }
                    if (ImGui::Button((_XOR_("DarkNite"))))
                    {
                        EngineVar::ColorUI = false;
                        EngineVoid::Reset();
                    }
                    if (ImGui::Button((_XOR_("RESET Game"))))
                    {
                        EngineVar::ColorUI = false;
                        EngineVoid::DarkNite();

                    }
                    ImGui::Checkbox((_XOR_("Custom Color")), &AlphaCheck);
                    if (AlphaCheck)
                    {
                        ImGui::SliderInt(_XOR_("Red Color Eng"), &EngineVoid::RedEngine, 0, 3);
                        ImGui::SliderInt(_XOR_("Green Color Eng"), &EngineVoid::GreenEngine, 0, 3);
                        ImGui::SliderInt(_XOR_("Blue Color Eng"), &EngineVoid::BlueEngine, 0, 3);
                        if (ImGui::Button((_XOR_("Apply Color"))))
                        {
                            EngineVoid::ChangeColorCUstom();
                        }
                    }
                }
                if (ImGui::CollapsingHeader(_XOR_("World interact")))
                {
                    ImGui::Checkbox(_XOR_("OutsideZone Alert Screen"), &visuals::OutsideZone);

                }
                ImGui::EndTabItem();
            }


            if (ImGui::BeginTabItem(_XOR_("Exploit")))
            {
                if (ImGui::CollapsingHeader(_XOR_("vehicle (Player to Player Disabled)")))
                {
                    //ImGui::Checkbox((_XOR_("Player TP")), &tp_players);
                    //ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Jump car")), &tp_jump_car);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Teleport to sky")), &tp_players_sky);

                    ImGui::Text(_XOR_("Teleport key :"));
                    if (tp_players or tp_players_sky or tp_jump_car)
                    {
                        HotkeyButton(hotkeys_exploit::keybind, ChangeKey_exploit, keystatus);
                    }
                }
                if (ImGui::CollapsingHeader(_XOR_("Boat (Risk ban high)")))
                {

                    ImGui::Checkbox((_XOR_("Boat speedhack (07/05/2022)")), &boat_speed_toggle);

                }
                if (ImGui::CollapsingHeader(_XOR_("Weapon (disable)")))
                {

                    //     ImGui::Checkbox((_XOR_("Bullet tp")), &tpbullet);

                }
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(_XOR_("Teleport-Vehicle")))
            {
                if (ImGui::CollapsingHeader(_XOR_("Mega city (Chest)")))
                {
                    ImGui::Checkbox((_XOR_("Teleport to mega chest")), &megachest);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Exit mega city")), &megachestexit);
                }
                if (ImGui::CollapsingHeader(_XOR_("Temple (Chest)")))
                {
                    ImGui::Checkbox((_XOR_("Teleport to Temple#1 chest")), &Templechest);
                    ImGui::SameLine();
                    ImGui::Checkbox((_XOR_("Teleport to Temple#2 chest")), &Templechest2);

                    ImGui::Checkbox((_XOR_("Exit Temple chest")), &Templechestexit);
                }
                if (ImGui::CollapsingHeader(_XOR_("Ice (Chest)")))
                {
                    ImGui::Checkbox((_XOR_("Teleport to Ice chest")), &Icechest);
                    ImGui::SameLine();

                    ImGui::Checkbox((_XOR_("Exit Ice chest")), &Icechestexit);
                }
                if (ImGui::CollapsingHeader(_XOR_("Castle (Chest)")))
                {
                    ImGui::Checkbox((_XOR_("Teleport to Castle chest")), &Castlechest);
                    ImGui::SameLine();

                    ImGui::Checkbox((_XOR_("Exit Castle chest")), &Castlechestexit);
                }
                if (ImGui::CollapsingHeader(_XOR_("Citadelle (Chest)")))
                {
                    ImGui::Checkbox((_XOR_("Teleport to Citadelle chest")), &Citadellechest);
                    ImGui::SameLine();

                    ImGui::Checkbox((_XOR_("Exit Citadelle chest")), &Citadellechestexit);
                }
                if (ImGui::CollapsingHeader(_XOR_("Tuto how to use")))
                {
                    ImGui::Text((_XOR_("Press 'F' + 'E' 3sec")));

                }
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(_XOR_("Settings")))
            {
                if (ImGui::CollapsingHeader(_XOR_("Save/Load configuration")))
                {
                    ImGui::Combo((_XOR_("name")), &setting::settsMode, settsName, IM_ARRAYSIZE(settsName));
                    if (ImGui::Button(((_XOR_("Save"))), ImVec2(100, 20)))
                    {
                        if (setting::settsMode == 0)
                            Save_Settings((_XOR_("C:\\Default.ini")));
                        if (setting::settsMode == 1)
                            Save_Settings((_XOR_("C:\\Default1.ini")));
                        if (setting::settsMode == 2)
                            Save_Settings((_XOR_("C:\\Default2.ini")));
                        if (setting::settsMode == 3)
                            Save_Settings((_XOR_("C:\\Default3.ini")));
                        if (setting::settsMode == 4)
                            Save_Settings((_XOR_("C:\\Default4.ini")));
                        if (setting::settsMode == 5)
                            Save_Settings((_XOR_("C:\\Default5.ini")));
                        if (setting::settsMode == 6)
                            Save_Settings((_XOR_("C:\\Default6.ini")));
                        if (setting::settsMode == 7)
                            Save_Settings((_XOR_("C:\\Default7.ini")));
                        if (setting::settsMode == 8)
                            Save_Settings((_XOR_("C:\\Default8.ini")));
                        if (setting::settsMode == 9)
                            Save_Settings((_XOR_("C:\\Default9.ini")));
                        if (setting::settsMode == 10)
                            Save_Settings((_XOR_("C:\\Default10.ini")));
                        if (setting::settsMode == 11)
                            Save_Settings((_XOR_("C:\\Default11.ini")));
                        if (setting::settsMode == 12)
                            Save_Settings((_XOR_("C:\\Default12.ini")));
                        if (setting::settsMode == 13)
                            Save_Settings((_XOR_("C:\\Default13.ini")));
                        if (setting::settsMode == 14)
                            Save_Settings((_XOR_("C:\\Default14.ini")));
                        if (setting::settsMode == 15)
                            Save_Settings((_XOR_("C:\\Default15.ini")));
                        if (setting::settsMode == 16)
                            Save_Settings((_XOR_("C:\\Default16.ini")));
                        if (setting::settsMode == 17)
                            Save_Settings((_XOR_("C:\\Default17.ini")));
                        if (setting::settsMode == 18)
                            Save_Settings((_XOR_("C:\\Default18.ini")));
                        if (setting::settsMode == 19)
                            Save_Settings((_XOR_("C:\\Default19.ini")));
                        if (setting::settsMode == 20)
                            Save_Settings((_XOR_("C:\\Default20.ini")));
                        if (setting::settsMode == 21)
                            Save_Settings((_XOR_("C:\\Default21.ini")));
                        if (setting::settsMode == 22)
                            Save_Settings((_XOR_("C:\\Default22.ini")));
                        if (setting::settsMode == 23)
                            Save_Settings((_XOR_("C:\\Default23.ini")));
                        if (setting::settsMode == 24)
                            Save_Settings((_XOR_("C:\\Default24.ini")));
                        if (setting::settsMode == 25)
                            Save_Settings((_XOR_("C:\\Default25.ini")));
                    }
                    ImGui::SameLine();
                    if (ImGui::Button(((_XOR_("Load"))), ImVec2(100, 20)))
                    {
                        if (setting::settsMode == 0)
                            Load_Settings((_XOR_("C:\\Default.ini")));
                        if (setting::settsMode == 1)
                            Load_Settings((_XOR_("C:\\Default1.ini")));
                        if (setting::settsMode == 2)
                            Load_Settings((_XOR_("C:\\Default2.ini")));
                        if (setting::settsMode == 3)
                            Load_Settings((_XOR_("C:\\Default3.ini")));
                        if (setting::settsMode == 4)
                            Load_Settings((_XOR_("C:\\Default4.ini")));
                        if (setting::settsMode == 5)
                            Load_Settings((_XOR_("C:\\Default5.ini")));
                        if (setting::settsMode == 6)
                            Load_Settings((_XOR_("C:\\Default6.ini")));
                        if (setting::settsMode == 7)
                            Load_Settings((_XOR_("C:\\Default7.ini")));
                        if (setting::settsMode == 8)
                            Load_Settings((_XOR_("C:\\Default8.ini")));
                        if (setting::settsMode == 9)
                            Load_Settings((_XOR_("C:\\Default9.ini")));
                        if (setting::settsMode == 10)
                            Load_Settings((_XOR_("C:\\Default10.ini")));
                        if (setting::settsMode == 11)
                            Load_Settings((_XOR_("C:\\Default11.ini")));
                        if (setting::settsMode == 12)
                            Load_Settings((_XOR_("C:\\Default12.ini")));
                        if (setting::settsMode == 13)
                            Load_Settings((_XOR_("C:\\Default13.ini")));
                        if (setting::settsMode == 14)
                            Load_Settings((_XOR_("C:\\Default14.ini")));
                        if (setting::settsMode == 15)
                            Load_Settings((_XOR_("C:\\Default15.ini")));
                        if (setting::settsMode == 16)
                            Load_Settings((_XOR_("C:\\Default16.ini")));
                        if (setting::settsMode == 17)
                            Load_Settings((_XOR_("C:\\Default17.ini")));
                        if (setting::settsMode == 18)
                            Load_Settings((_XOR_("C:\\Default18.ini")));
                        if (setting::settsMode == 19)
                            Load_Settings((_XOR_("C:\\Default19.ini")));
                        if (setting::settsMode == 20)
                            Load_Settings((_XOR_("C:\\Default20.ini")));
                        if (setting::settsMode == 21)
                            Load_Settings((_XOR_("C:\\Default21.ini")));
                        if (setting::settsMode == 22)
                            Load_Settings((_XOR_("C:\\Default22.ini")));
                        if (setting::settsMode == 23)
                            Load_Settings((_XOR_("C:\\Default23.ini")));
                        if (setting::settsMode == 24)
                            Load_Settings((_XOR_("C:\\Default24.ini")));
                        if (setting::settsMode == 25)
                            Load_Settings((_XOR_("C:\\Default25.ini")));



                    }

                    ImGui::EndTabItem();
                }
                if (ImGui::Button(_XOR_("CLOSE CHEAT"), ImVec2(120, 40)))
                {
                    cheatStatus = 1;

                    system(_XOR_("taskkill /f /im mmc.exe"));
                    exit(0);
                }
            }

        }
    }

    ImGui::End();

}

void render()
{
    LPDIRECT3D9              g_pD3D = NULL;
    LPDIRECT3DDEVICE9       g_pd3dDevice = NULL;
    D3DPRESENT_PARAMETERS    g_d3dpp = {};
    auto& io = ImGui::GetIO();
    auto& style = ImGui::GetStyle();

    io.MouseDrawCursor = menu_key;
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));

    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));

    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGui::Begin("##Invisible", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs);
    ImGui::GetWindowDrawList()->PushClipRectFullScreen();

    ImGui::PopStyleColor(2);

    //enable_use_info();
    if (menu_key)
    {

        //enable_use_info();
        menu();
    }

    init_all();

    ImGui::Render();
    ImVec4 clear_color = ImVec4(0., 0., 0., 0.);
    g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
    g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)&clear_color);
    g_d3dpp.FullScreen_RefreshRateInHz = true;

    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    g_pSwapChain->Present(1, 0);
}

WPARAM MainLoop()
{


    static RECT old_rc;
    ZeroMemory(&Message, sizeof(MSG));
    while (Message.message != WM_QUIT)
    {
        if (PeekMessage(&Message, MyWnd, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        POINT p;
        POINT xy;
        GetCursorPos(&p);
        io.MousePos.x = p.x;
        io.MousePos.y = p.y;
        if (GetAsyncKeyState(VK_LBUTTON)) {
            io.MouseDown[0] = true;
            io.MouseClicked[0] = true;
            io.MouseClickedPos[0].x = io.MousePos.x;
            io.MouseClickedPos[0].x = io.MousePos.y;
        }
        else
            io.MouseDown[0] = false;
        render();

    }

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    CleanupDeviceD3D();
    DestroyWindow(MyWnd);
    return Message.wParam;
}
