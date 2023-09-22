
bool AlphaCheck = false;
bool enable_server_info = true;
bool enable_exploit_client = false;
bool enable_exploit_server = false;
bool vehicle_speed_exploit = false;
bool tpbullet = false;
bool tp_players = false;
bool tp_players_sky = false;
bool tp_jump_car = false;
bool BCARFLY = false;
bool boat_speed_toggle = false;
struct FQuat
{
	double x;
	double y;
	double z;
	double w;
};
ImFont* Logo;
ImFont* yep;
ImFont* yep2;
ImFont* light;
ImFont* test;


ImFont* ico = nullptr;
ImFont* ico_combo = nullptr;
ImFont* ico_button = nullptr;
ImFont* ico_grande = nullptr;
ImFont* segu = nullptr;
ImFont* default_segu = nullptr;
ImFont* bold_segu = nullptr;
namespace VisibleColCheck {
	float r = 0;
	float g = 255;
	float b = 0;
}
namespace InVisibleColCheck {
	float r = 255;
	float g = 0;
	float b = 0;
}

static float closestDistance = FLT_MAX;
static float closestDistance2 = FLT_MAX;
static DWORD_PTR closestPawn = NULL;
static DWORD_PTR closestPawnExploit = NULL;
static bool targetlocked = false;
static bool isaimbotting;

bool color_random = true;
float crosshair_r = 255;
float crosshair_g = 0;
float crosshair_b = 0;
float crosshair_a = 255;
bool color_crosshair = true;
float title_r = 255;
float title_g = 0;
float title_b = 0;
float title_a = 255;
bool title_color = true;
float box_r = 255;
float box_g = 0;
float box_b = 0;
float box_a = 255;
bool box_color = true;

//int GameUI_r = static_cast<int>(3.0f * 1000);
//int GameUI_g = static_cast<int>(0.0f * 1000);
//int GameUI_b = static_cast<int>(0.0f * 1000);
BYTE GameUI_a = 0x3F;
int design_blur_value = 255;
int rounding_value = 0;
float gui_r = 100;
float gui_g = 0;
float gui_b = 255;
float gui_a = 255;
int set_color_box = ImColor(gui_r, gui_g, gui_b, gui_a);
bool color_ramdom_esp = true;
int cheatStatus = 2;
namespace DriverVar
{
    static uint32_t ProcID;
    static std::uintptr_t module;
    static int32_t UsermodepID;
    static int64_t peb;

    static DWORD ScreenCenterX = NULL;
    static DWORD ScreenCenterY = NULL;

    static int width, height;
}
namespace aimbot
{
    static bool aimbot = false;
    static bool smooth = false;
    static bool fovcircle = false;
    static bool triggerbot = false;
    static bool prediction = false;

   static float aimspeed = 5.f;
    static float hipfire = 13.f;
    static float aimfov = 300.f;
    static float aimdistance = 300.f;
	static bool silent;
    static float lock = 0.f;
    static float adsfov = 300.f;
	static float adsfovv = 300.f;
    static float adsfovW2S = 250.f;
    static int hitbox = 0;
}
namespace aimbot2
{
    static bool aimbot = false;
    static bool smooth = false;
    static bool fovcircle = false;
    static bool prediction = false;

   static float aimspeed = 5.f;
    static float hipfire = 7.f;
    static float aimfov = 250.f;
     static float aimdistance = 300.f;
    static float lock = 0.f;
    static float adsfov = 300.f;

    static int hitbox = 0;
}
namespace aimbot3
{
    static bool aimbot = false;
    static bool smooth = false;
    static bool fovcircle = false;
    static bool prediction = false;

   static float aimspeed = 5.f;
    static float hipfire = 8.f;
    static float aimfov = 300.f;
     static float aimdistance = 300.f;
    static float lock = 0.f;
    static float adsfov = 350.f;

    static int hitbox = 0;
}
namespace aimbot4
{
    static bool aimbot = false;
    static bool smooth = false;
    static bool fovcircle = false;
    static bool prediction = false;

   static float aimspeed = 5.f;
    static float hipfire = 10.f;
    static float aimfov = 220.f;
     static float aimdistance = 300.f;
    static float lock = 0.f;
    static float adsfov = 300.f;

    static int hitbox = 0;
}
namespace aimbot5
{
    static bool aimbot = false;
    static bool smooth = false;
    static bool fovcircle = false;
    static bool prediction = false;

    static float aimspeed = 5.f;
    static float hipfire = 7.f;
    static float aimfov = 350.f;
     static float aimdistance = 300.f;
    static float lock = 0.f;
    static float adsfov = 400.f;

    static int hitbox = 0;
}
namespace hotkey_manettte
{
	bool enablecontroller;
}
namespace hotkeys_exploit
{
    static int keybind = 0;

}
namespace hotkeys
{
    static int aimkey = 0;
   
}
namespace hotkeys2
{
    static int aimkey2 = 0;
}
namespace hotkeys3
{
    static int aimkey3 = 0;
}
namespace hotkeys4
{
    static int aimkey4 = 0;
}
namespace hotkeys5
{
    static int aimkey5 = 0;
}
namespace visuals
{
    static bool boxeinf = false;
    static bool skeleton = false;
    static bool name = false;
    static bool supply = true;
	static bool vehicle = true;
    static bool ammo = false;
    static bool teamid = false;
    static bool CheckBOT = false;
    static bool weapon = false;
    static bool ammobox = true;
	static bool Crouching = false;
	static bool aiming = false;
	static bool parachute = false;

	bool silent_aim = false;

    static bool lines = false;
    static bool outline = false;
	static bool corner = false;
    static bool radar = false;
    static bool distance = false;
    static bool OutsideZone = false;
    static bool items = false;
    static bool chest = true;
    static bool animal = true;
    static bool VehicleEsp = true;
    static int boxMode = 0;
    static int skelMode = 0;
    static int lineMode = 0;
    static int radarstyle = 0;

    static float MaxSkeletonDrawDistance = 50.f;
    static float MaxDistance = 150.f;
    static float ItemDistance = 50.f;
    static float ChestDistance = 50.f;
    static float SupplyDistance = 50.f;
    static float AmmoDistance = 50.f;
    static float VehicleDistance = 50.f;

    static bool smg = 0;
    static bool rifle = 0;
    static bool shotgun;
}
namespace thickness {

    static int SkeletonThick = 1;
    static int box_thick = 1;
}
namespace colors {

    static float invisible[3] = { 1.0f , 0.0f , 0.0f };
    static float visible[3] = { 1.0f , 0.0f , 0.0f };
    static float fov[3] = { 1.0f , 1.0f , 1.0f };
	static float fovv[3] = { 0.0f , 0.0f , 0.0f};
}
namespace setting {

    static int settsMode = 0;
}
namespace items {

    static bool Common = false;
    static bool UnCommon = false;
    static bool rare = false;
    static bool purple = false;
    static bool gold = false;
    static bool mythic;
}


namespace external_def
{
    bool rainbow{ false };
    bool bNotify_info{ false };
    bool g_3d_box = false;
    bool g_3d_box_triangle = false;
    bool g_3d_hand = false;
    bool g_3d_head = false;
    bool Esp_box = false;
    bool g_buried = false;
    bool g_crossh_int = false;
    bool filled_box = false;
    namespace Settings {
        // item set ==============================================================


        bool fovCircleByAngle= false;
        float fovValueViewPoint;
        bool cross_hair_nazi = false;
        int faken_rot;
        bool cross_hair = false;
        DWORD refresh_loop = 4500;

    }
}
static const char* settsName[] =
{
    "Default",
	  "Default1",
		"Default2",
		  "Default3",
			"Default4",
			  "Default5",
				"Default6",
				  "Default7",
					"Default8",
					  "Default9",
						"Default10",
                        "Default11",
                        "Default12",
                        "Default13",
                        "Default14",
                        "Default15",
                        "Default16",
                        "Default17",
                        "Default18",
                        "Default19",
                        "Default20",
                        "Default21",
                        "Default22",
                        "Default23",
                        "Default24",
                        "Default25",
};

static const char* Hitbox[] =
{
    "Head",
    "Neck",
    "Ass",
    "Random"
};

static const char* linesMode[] =
{
    "Bottom",
    "Top",
    "Center"
};
static DWORD hitbox_selector = 0;
static DWORD select_hitbox()
{
 

    if (aimbot::hitbox == 0)
        hitbox_selector = 106;
    else if (aimbot::hitbox == 1)
        hitbox_selector = 67;
    else if (aimbot::hitbox == 2)
        hitbox_selector = 2;
    return hitbox_selector;
}

void RBONE()
{
    if (aimbot::hitbox == 3)
    {

        int selct = 68 - 0 + 1;
        hitbox_selector = rand() % selct + 3;
        Sleep(30);
    }
}