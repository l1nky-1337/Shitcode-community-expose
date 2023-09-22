#ifndef W2S_HPP
#define W2S_HPP
char Off_team_id;
uintptr_t CamManager;
uintptr_t Off_player_controller;
_QWORD LocalPawn_base;
_QWORD uworld;
_QWORD Off_player_array;
_QWORD Off_rootcomponent;
_QWORD game_state;
int32_t player_array;
Vector3 Off_relativelocation;
_QWORD PlayerStateOff;
_QWORD Off_currweapon;
_QWORD fov_pointer;
_QWORD location_pointer;
_QWORD rotation_pointer;
_QWORD MyPlayer;
_QWORD value_fov_pointer;
_QWORD value_fov_pointer_angle;
static double GetCrossDistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
bool IsVec3Valid(Vector3 vec3)
{
	return !(vec3.x == 0 && vec3.y == 0 && vec3.z == 0);
}
Vector3 GetLoc(Vector3 Loc)
{
	Vector3 Location = Vector3(Loc.x, Loc.y, Loc.z);
	return Location;
}
typedef struct _LootEntity {
	std::string GNames;
	uintptr_t ACurrentItem;
}LootEntity;
static std::vector<LootEntity> LootentityList;


typedef struct _ItemBase {
	int32 actorscount;
	uint64_t actorsarray;
}_ItemBase;
std::vector<_ItemBase> itemBaseList;

typedef struct _Item {
	uint64_t actor;
	std::string ItemName;
	BYTE bWTier;
	int type;
}_Item;
std::vector<_Item> itemList;
uint64_t AFortPickupAthena = 0;

typedef struct _Entity {
	int type;
	uint64_t actor;
	uint64_t mesh;
	uint64_t currweapon;
	uint64_t playerstate;
}_Entity;
std::vector<_Entity> EntityList;

typedef struct _Ground {
	DWORD64 actor;
	int type;
}_Ground;
std::vector<_Ground> GroundList;
float zoom;
Vector3 RotatePoint(Vector3 pointToRotate, Vector3 centerPoint, int posX, int posY, int sizeX, int sizeY, float angle, float zoom, bool* viewCheck, bool angleInRadians = false);
Vector3 RotatePoint(Vector3 EntityPos, Vector3 LocalPlayerPos, int posX, int posY, int sizeX, int sizeY, float angle, float zoom, bool* viewCheck, bool angleInRadians)
{
	float r_1, r_2;
	float x_1, y_1;

	r_1 = -(EntityPos.y - LocalPlayerPos.y);
	r_2 = EntityPos.x - LocalPlayerPos.x;

	float Yaw = angle + 360.0f;

	float yawToRadian = Yaw * (float)(M_PI / 180.0F);
	x_1 = (float)(r_2 * (float)cos((float)(yawToRadian)) - r_1 * sin((float)(yawToRadian))) / 80;
	y_1 = (float)(r_2 * (float)sin((float)(yawToRadian)) + r_1 * cos((float)(yawToRadian))) / 80;

	*viewCheck = y_1 < 0;

	x_1 *= zoom;
	y_1 *= zoom;

	int sizX = sizeX / 2;
	int sizY = sizeY / 2;

	x_1 += sizX;
	y_1 += sizY;

	if (x_1 < 0)
		x_1 = 0;

	if (x_1 > sizeX - 0)
		x_1 = sizeX - 0;

	if (y_1 < 0)
		y_1 = 0;

	if (y_1 > sizeY - 0)
		y_1 = sizeY - 0;


	x_1 += posX;
	y_1 += posY;


	return Vector3(x_1, y_1, 0);
}
class FRotator
{
public:
	FRotator() : Pitch(0.f), Yaw(0.f), Roll(0.f)
	{

	}

	FRotator(double _Pitch, double _Yaw, double _Roll) : Pitch(_Pitch), Yaw(_Yaw), Roll(_Roll)
	{

	}
	~FRotator()
	{

	}

	double Pitch;
	double Yaw;
	double Roll;
	inline FRotator get() {
		return FRotator(Pitch, Yaw, Roll);
	}
	inline void set(double _Pitch, double _Yaw, double _Roll) {
		Pitch = _Pitch;
		Yaw = _Yaw;
		Roll = _Roll;
	}

	inline FRotator Clamp() {
		FRotator result = get();
		if (result.Pitch > 180)
			result.Pitch -= 360;
		else if (result.Pitch < -180)
			result.Pitch += 360;
		if (result.Yaw > 180)
			result.Yaw -= 360;
		else if (result.Yaw < -180)
			result.Yaw += 360;
		if (result.Pitch < -89)
			result.Pitch = -89;
		if (result.Pitch > 89)
			result.Pitch = 89;
		while (result.Yaw < -180.0f)
			result.Yaw += 360.0f;
		while (result.Yaw > 180.0f)
			result.Yaw -= 360.0f;

		result.Roll = 0;
		return result;

	}
	double Length() {
		return sqrt(Pitch * Pitch + Yaw * Yaw + Roll * Roll);
	}

	FRotator operator+(FRotator angB) { return FRotator(Pitch + angB.Pitch, Yaw + angB.Yaw, Roll + angB.Roll); }
	FRotator operator-(FRotator angB) { return FRotator(Pitch - angB.Pitch, Yaw - angB.Yaw, Roll - angB.Roll); }
	FRotator operator/(float flNum) { return FRotator(Pitch / flNum, Yaw / flNum, Roll / flNum); }
	FRotator operator*(float flNum) { return FRotator(Pitch * flNum, Yaw * flNum, Roll * flNum); }
	bool operator==(FRotator angB) { return Pitch == angB.Pitch && Yaw == angB.Yaw && Yaw == angB.Yaw; }
	bool operator!=(FRotator angB) { return Pitch != angB.Pitch || Yaw != angB.Yaw || Yaw != angB.Yaw; }

};

double NormalizeAxis(double angle)
{
	while (angle > 180.0) angle -= 360.0;
	while (angle < -180.0) angle += 360.0;
	return angle;
}
static float ClampAxis(float angle) {
	// returns Angle in the range (-360,360)
	angle = fmodf(angle, 360.0f);

	if (angle < 0.0f) {
		// shift to [0,360) range
		angle += 360.0f;
	}

	return angle;
}
static float NormalizeAxis(float angle) {
	angle = ClampAxis(angle);

	if (angle > 180.0f) {
		// shift to (-180,180]
		angle -= 360.0f;
	}

	return angle;
}
FRotator Rotator(FQuat* F)
{
	const double SingularityTest = F->z * F->x - F->w * F->y;
	const double YawY = 2.f * (F->w * F->z + F->x * F->y);
	const double YawX = (1.f - 2.f * ((F->y * F->y) + (F->z * F->z)));

	const double SINGULARITY_THRESHOLD = 0.4999995f;
	const double RAD_TO_DEG = 57.295776;
	double Pitch, Yaw, Roll;

	if (SingularityTest < -SINGULARITY_THRESHOLD)
	{
		Pitch = -90.f;
		Yaw = (atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = NormalizeAxis(-Yaw - (2.f * atan2(F->x, F->w) * RAD_TO_DEG));
	}
	else if (SingularityTest > SINGULARITY_THRESHOLD)
	{
		Pitch = 90.f;
		Yaw = (atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = NormalizeAxis(Yaw - (2.f * atan2(F->x, F->w) * RAD_TO_DEG));
	}
	else
	{
		Pitch = (asin(2.f * SingularityTest) * RAD_TO_DEG);
		Yaw = (atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = (atan2(-2.f * (F->w * F->x + F->y * F->z), (1.f - 2.f * ((F->x * F->x) + (F->y * F->y)))) * RAD_TO_DEG);
	}

	FRotator RotatorFromQuat = FRotator{ Pitch, Yaw, Roll };
	return RotatorFromQuat;
}





struct DecryptionOfCamera
{
	Vector3 Location;
	Vector3 Rotation;
	float FieldOfView;
	char Useless[0x18];
};
//DecryptionOfCamera Viewpoint_W2S()
//{
//
//		
//		//48 8B C4 48 83 EC 68 F2 0F 10 41 ? 0F 10 49 18 88 50 F0 0F 10 11 F2 0F 11 40 ? F2 0F 10 41 ? F2 0F 11 40 ? F3 0F 10 41 ? 0F 11 48 D0 F3 0F 10 49 //ViewPoint
//		//ou
//		//48 8D 0D ? ? ? ? F3 0F 11 40 ? 0F 28 40 C8 F3 0F 11 48 ? 0F 28 48 D8 0F 29 05 ? ? ? ? //ViewPoint
//		DecryptionOfCamera CameraViewPoint = ctx->read_physical_memory<DecryptionOfCamera>(DriverVar::module + 0xEDC66E0); //14F0E8BD0
//		char v1; // r8
//		BYTE* v2 = (BYTE*)&CameraViewPoint;
//		int i; // edx
//		__int64 result; // rax
//
//		v1 = 0x40;
//		for (i = 0; i < 0x40; ++i)
//		{
//			*v2 ^= v1;
//			result = (unsigned int)(i + 0x17);
//			v1 += i + 0x17;
//			v2++;
//		}
//
//		return CameraViewPoint;
//	
//	
//}  

DecryptionOfCamera Viewpoint_W2S() {
	char v1; // r8
	DecryptionOfCamera ViewPoint = ctx->read_physical_memory<DecryptionOfCamera>(DriverVar::module + 0xEDC66E0); // 0xED57310 = EncryptedViewPoint
	BYTE* v2 = (BYTE*)&ViewPoint;
	int i; // edx
	__int64 result; // rax

	v1 = 0x40;
	for (i = 0; i < 0x40; ++i) {
		*v2 ^= v1;
		result = (unsigned int)(i + 0x17);
		v1 += i + 0x17;
		v2++;
	}

	return ViewPoint;
}



Vector3 ProjectWorldToScreen(Vector3 WorldLocation)
{

	DecryptionOfCamera vCamera = Viewpoint_W2S();
		D3DMATRIX tempMatrix = Matrix(vCamera.Rotation, Vector3(0, 0, 0));
		Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
		Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
		Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);
		Vector3 vDelta = WorldLocation - vCamera.Location;
		Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));
		//aimbot::aimfov = vCamera.FieldOfView + 200.f;
		//aimbot2::aimfov = vCamera.FieldOfView + 200.f;
		//aimbot3::aimfov = vCamera.FieldOfView + 200.f;
		//aimbot4::aimfov = vCamera.FieldOfView + 200.f;
		//aimbot5::aimfov = vCamera.FieldOfView + 200.f;
		//aimbot::adsfov = vCamera.FieldOfView + 80.f;
		//aimbot2::adsfov = vCamera.FieldOfView + 80.f;
		//aimbot3::adsfov = vCamera.FieldOfView + 80.f;
		//aimbot4::adsfov = vCamera.FieldOfView + 80.f;
		//aimbot5::adsfov = vCamera.FieldOfView + 80.f;
		if (vTransformed.z < 1.f) vTransformed.z = 1.f;
		
		    return Vector3((DriverVar::width / 2.0f) + vTransformed.x * (((DriverVar::width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (DriverVar::height / 2.0f) - vTransformed.y * (((DriverVar::width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);

		
}


//Vector3 ProjectWorldToScreen(Vector3 WorldLocation)
//{
//	DecryptionOfCamera ViewPoint = Viewpoint_W2S();
//	D3DMATRIX tempMatrix = Matrix(ViewPoint.Rotation);
//	Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
//	Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
//	Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);
//	Vector3 vDelta = WorldLocation - ViewPoint.Location;
//	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));
//	if (vTransformed.z < 1.f)
//		vTransformed.z = 1.f;
//	return Vector3((DriverVar::width / 2.0f) + vTransformed.x * (((DriverVar::width / 2.0f) / tanf(ViewPoint.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (DriverVar::height / 2.0f) - vTransformed.y * (((DriverVar::height / 2.0f) / tanf(ViewPoint.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);
//}


void radarFlex()
{
	
		DecryptionOfCamera vCamera = Viewpoint_W2S();
		if (visuals::radar)
		{
			auto& style = ImGui::GetStyle();
			style.WindowRounding = 0;
			ImGui::SetNextWindowPos(ImVec2(70, 250));
			ImGui::SetNextWindowSize(ImVec2(250, 250));
			ImGui::Begin(_XOR_(""), &visuals::radar, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);

			ImVec2 siz = ImGui::GetWindowSize();
			ImVec2 pos = ImGui::GetWindowPos();
			float RadarCenterX = pos.x + (siz.x / 2);
			float RadarCenterY = pos.y + (siz.y / 2);
			ImDrawList* windowDrawList = ImGui::GetWindowDrawList();


			windowDrawList->AddRect(ImVec2(pos.x, pos.y), ImVec2(pos.x + siz.x, pos.y + siz.y), ImGui::GetColorU32(ImVec4(100, 100, 100, 255)), 0.0F, -1, 1.5f);
			windowDrawList->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(pos.x, pos.y), ImGui::GetColorU32(ImVec4(100, 100, 100, 100)), 1.f);
			windowDrawList->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(pos.x + siz.x, pos.y), ImGui::GetColorU32(ImVec4(100, 100, 100, 100)), 1.f);
			windowDrawList->AddLine(ImVec2(pos.x, RadarCenterY), ImVec2(pos.x + siz.x, RadarCenterY), ImGui::GetColorU32(ImVec4(100, 100, 100, 100)), 1.f);
			windowDrawList->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(RadarCenterX, pos.y + siz.y), ImGui::GetColorU32(ImVec4(100, 100, 100, 100)), 1.f);
			windowDrawList->AddCircleFilled(ImVec2(RadarCenterX, RadarCenterY), 2, ImGui::GetColorU32(ImVec4(100, 100, 100, 100)));

			auto entityListCopy = EntityList;

			for (auto& entity : entityListCopy)
			{
				DWORD64 rootcomponent = ctx->read_physical_memory<DWORD64>(entity.actor + Actor::RootComponent);
				if (!rootcomponent)continue;

				Vector3 Relativelocation = ctx->read_physical_memory<Vector3>(rootcomponent + SceneComponent::RelativeLocation);
				if (!IsVec3Valid(Relativelocation))continue;

				DWORD64 LocalRootcomp = ctx->read_physical_memory<DWORD64>(LocalPawn_base + Actor::RootComponent);
				Vector3 LocalRelativeLocation = ctx->read_physical_memory<Vector3>(LocalRootcomp + SceneComponent::RelativeLocation);
				bool viewCheck = true;
				Vector3 EntitiesPos = RotatePoint(Relativelocation, LocalRelativeLocation, pos.x, pos.y, siz.x, siz.y, zoom, 2, &viewCheck);
				zoom = vCamera.Rotation.y + 295;
				int s = 4;
				windowDrawList->AddRect(ImVec2(EntitiesPos.x - s, EntitiesPos.y - s), ImVec2(EntitiesPos.x + s, EntitiesPos.y + s), IM_COL32(cross_r, cross_g, cross_b, 255));

			}
			ImGui::End();
		}
	}


#endif