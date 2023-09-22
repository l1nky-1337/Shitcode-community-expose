#ifndef VECTOR_HPP
#define VECTOR_HPP
#pragma once

#define M_PI 3.14159265358979323846264338327950288419716939937510

#define M_PI2                       3.14159265358979323846f
#define URotationToRadians(URotation)		((URotation)* (M_PI2 / 32768.0f))
#define URotationToDegree( URotation )		( ( URotation ) * ( 360.0f / 65536.0f ) ) 

#define DegreeToURotation( Degree )			( ( Degree ) * ( 65536.0f / 360.0f ) )
#define DegreeToRadian( Degree )			( ( Degree ) * ( M_PI2 / 180.0f ) )

#define RadianToURotation( URotation )		( ( URotation ) * ( 32768.0f / M_PI2 ) ) 
#define RadianToDegree( Radian )			( ( Radian ) * ( 180.0f / M_PI2 ) )

class Vector3
{
public:
	double x, y, z;

	Vector3()
	{
		x = y = z = 0.0f;
	}

	Vector3(double X, double Y, double Z)
	{
		x = X; y = Y; z = Z;
	}

	Vector3(double XYZ)
	{
		x = XYZ; y = XYZ; z = XYZ;
	}

	Vector3(double* v)
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	Vector3(const double* v)
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	inline Vector3& operator=(const Vector3& v)
	{
		x = v.x; y = v.y; z = v.z; return *this;
	}

	inline Vector3& operator=(const double* v)
	{
		x = v[0]; y = v[1]; z = v[2]; return *this;
	}

	inline double& operator[](int i)
	{
		return ((double*)this)[i];
	}

	inline double operator[](int i) const
	{
		return ((double*)this)[i];
	}

	inline Vector3& operator+=(const Vector3& v)
	{
		x += v.x; y += v.y; z += v.z; return *this;
	}

	inline Vector3& operator-=(const Vector3& v)
	{
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	inline Vector3& operator*=(const Vector3& v)
	{
		x *= v.x; y *= v.y; z *= v.z; return *this;
	}

	inline Vector3& operator/=(const Vector3& v)
	{
		x /= v.x; y /= v.y; z /= v.z; return *this;
	}

	inline Vector3& operator+=(double v)
	{
		x += v; y += v; z += v; return *this;
	}

	inline Vector3& operator-=(double v)
	{
		x -= v; y -= v; z -= v; return *this;
	}

	inline Vector3& operator*=(double v)
	{
		x *= v; y *= v; z *= v; return *this;
	}

	inline Vector3& operator/=(double v)
	{
		x /= v; y /= v; z /= v; return *this;
	}

	inline Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	inline Vector3 operator+(const Vector3& v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	inline Vector3 operator-(const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3 operator*(const Vector3& v) const
	{
		return Vector3(x * v.x, y * v.y, z * v.z);
	}

	inline Vector3 operator/(const Vector3& v) const
	{
		return Vector3(x / v.x, y / v.y, z / v.z);
	}

	inline Vector3 operator+(double v) const
	{
		return Vector3(x + v, y + v, z + v);
	}

	inline Vector3 operator-(double v) const
	{
		return Vector3(x - v, y - v, z - v);
	}

	inline Vector3 operator*(double v) const
	{
		return Vector3(x * v, y * v, z * v);
	}

	inline Vector3 operator/(double v) const
	{
		return Vector3(x / v, y / v, z / v);
	}

	inline double Distance(Vector3 v)
	{
		return sqrtf((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y) + (v.z - z) * (v.z - z));
	}

	inline double Length() const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	inline double LengthSqr() const
	{
		return (x * x + y * y + z * z);
	}

	inline double LengthXY() const
	{
		return sqrtf(x * x + y * y);
	}

	inline double LengthXZ() const
	{
		return sqrtf(x * x + z * z);
	}

	inline double DistTo(const Vector3& v) const
	{
		return (*this - v).Length();
	}

	inline double Dot(const Vector3& v) const
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	inline Vector3 Cross(const Vector3& v) const
	{
		return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	inline bool IsZero() const
	{
		return (x > -0.01f && x < 0.01f
			&& y > -0.01f && y < 0.01f
			&& z > -0.01f && z < 0.01f);
	}

	inline void Reset()
	{
		x = 0.f; y = 0.f; z = 0.f;
	}
};


D3DXMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0))
{
	double radPitch = (rot.x * double(M_PI) / 180.f);
	double radYaw = (rot.y * double(M_PI) / 180.f);
	double radRoll = (rot.z * double(M_PI) / 180.f);

	double SP = sin(radPitch);
	double CP = cos(radPitch);
	double SY = sin(radYaw);
	double CY = cos(radYaw);
	double SR = sin(radRoll);
	double CR = cos(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}

struct FTransform
{
	FQuat rot;
	Vector3 translation;
	char pad[4];
	Vector3 scale;
	char pad1[4];

	D3DMATRIX ToMatrixWithScale()
	{
		D3DMATRIX m;
		m._41 = translation.x;
		m._42 = translation.y;
		m._43 = translation.z;

		double x2 = rot.x + rot.x;
		double y2 = rot.y + rot.y;
		double z2 = rot.z + rot.z;

		double xx2 = rot.x * x2;
		double yy2 = rot.y * y2;
		double zz2 = rot.z * z2;
		m._11 = (1.0f - (yy2 + zz2)) * scale.x;
		m._22 = (1.0f - (xx2 + zz2)) * scale.y;
		m._33 = (1.0f - (xx2 + yy2)) * scale.z;

		double yz2 = rot.y * z2;
		double wx2 = rot.w * x2;
		m._32 = (yz2 - wx2) * scale.z;
		m._23 = (yz2 + wx2) * scale.y;

		double xy2 = rot.x * y2;
		double wz2 = rot.w * z2;
		m._21 = (xy2 - wz2) * scale.y;
		m._12 = (xy2 + wz2) * scale.x;

		double xz2 = rot.x * z2;
		double wy2 = rot.w * y2;
		m._31 = (xz2 + wy2) * scale.z;
		m._13 = (xz2 - wy2) * scale.x;

		m._14 = 0.0f;
		m._24 = 0.0f;
		m._34 = 0.0f;
		m._44 = 1.0f;

		return m;
	}
};
static D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut;
	pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
	pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
	pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
	pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
	pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
	pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
	pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
	pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
	pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
	pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
	pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
	pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
	pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
	pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
	pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
	pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

	return pOut;
}
// Class Engine.InstancedStaticMeshComponent
// Size= 0x770 (Inherited= 0x620)
namespace UInstancedStaticMeshComponent{ //UInstancedStaticMeshComponent : UStaticMeshComponent 
	char pad_620[0x8]; // 0x620(0x08)
	int32_t NumCustomDataFloats; // 0x648(0x04)
}
//ou 

// Class Engine.StaticMeshComponent
// Size= 0x620 (Inherited= 0x5a0)
namespace UStaticMeshComponent { //UStaticMeshComponent : UMeshComponent
	int32_t ForcedLodModel; // 0x5a0(0x04)
	int32_t PreviousLODLevel; // 0x5a4(0x04)
	int32_t MinLOD; // 0x5a8(0x04)
	int32_t SubDivisionStepSize; // 0x5ac(0x04)
	//struct UStaticMesh* StaticMesh; // 0x5b0(0x08)
	//struct FColor WireframeColorOverride; // 0x5b8(0x04)
	char bForceNaniteForMasked = 1; // 0x5bc(0x01)
	char bDisallowNanite = 1; // 0x5bc(0x01)
	char bForceDisableNanite = 1; // 0x5bc(0x01)
	char bEvaluateWorldPositionOffset = 1; // 0x5bc(0x01)
	char bEvaluateWorldPositionOffsetInRayTracing = 1; // 0x5bc(0x01)
	char pad_5BC_5 = 3; // 0x5bc(0x01)
	char pad_5BD[0x3]; // 0x5bd(0x03)
	int32_t WorldPositionOffsetDisableDistance; // 0x5c0(0x04)
	char pad_5C4_0 = 1; // 0x5c4(0x01)
	char bOverrideWireframeColor = 1; // 0x5c4(0x01)
	char bOverrideMinLOD = 1; // 0x5c4(0x01)
	char bOverrideNavigationExport = 1; // 0x5c4(0x01)
	char bForceNavigationObstacle = 1; // 0x5c4(0x01)
	char bDisallowMeshPaintPerInstance = 1; // 0x5c4(0x01)
	char bIgnoreInstanceForTextureStreaming = 1; // 0x5c4(0x01)
	char bOverrideLightMapRes = 1; // 0x5c4(0x01)
	char bCastDistanceFieldIndirectShadow = 1; // 0x5c5(0x01)
	char bOverrideDistanceFieldSelfShadowBias = 1; // 0x5c5(0x01)
	char bUseSubDivisions = 1; // 0x5c5(0x01)
	char bUseDefaultCollision = 1; // 0x5c5(0x01)
	char bSortTriangles = 1; // 0x5c5(0x01)
	char bReverseCulling = 1; // 0x5c5(0x01)
	char pad_5C5_6 = 2; // 0x5c5(0x01)
	char pad_5C6[0x2]; // 0x5c6(0x02)
	int32_t OverriddenLightMapRes; // 0x5c8(0x04)
	float DistanceFieldIndirectShadowMinVisibility; // 0x5cc(0x04)
	float DistanceFieldSelfShadowBias; // 0x5d0(0x04)
	float StreamingDistanceMultiplier; // 0x5d4(0x04)
	//struct TArray<None> LodData; // 0x5d8(0x10)
	//struct TArray<None> StreamingTextureData; // 0x5e8(0x10)
	//struct FLightmassPrimitiveSettings LightmassSettings; // 0x5f8(0x18)
	char pad_610[0x10]; // 0x610(0x10) //du coup le bone mesh - 10 pour le cache et -- 0x10 pour l'array

	
};

uint64_t boneArray_var;
static FTransform GetBoneTransform(_QWORD mesh, int index)
{
	boneArray_var = ctx->read_physical_memory<uint64_t>(mesh + 0x600);
	if (!boneArray_var)
		boneArray_var = ctx->read_physical_memory<uint64_t>(mesh + 0x610); //0x610
	return ctx->read_physical_memory<FTransform>(boneArray_var + (index * sizeof(FTransform)));
}

Vector3 GetBoneWithRotation(uintptr_t mesh, int bone_id)
{
	uintptr_t bone_array = ctx->read_physical_memory<uintptr_t>(mesh + 0x600);
	if (bone_array == NULL) bone_array = ctx->read_physical_memory<uintptr_t>(mesh + 0x600 + 0x10);
	FTransform bone = ctx->read_physical_memory<FTransform>(bone_array + (bone_id * 0x60));
	FTransform component_to_world = ctx->read_physical_memory<FTransform>(mesh + 0x240);
	D3DMATRIX matrix = MatrixMultiplication(bone.ToMatrixWithScale(), component_to_world.ToMatrixWithScale());
	return Vector3(matrix._41, matrix._42, matrix._43);
}
static Vector3 GetBoneWithRotationAndBuff(_QWORD pMeshComponent, int32_t BoneIdx, char* buff, FTransform MeshComponentToWorld)
{
	FTransform BoneArray = *(FTransform*)(buff + BoneIdx * 0x60);
	D3DMATRIX Matrix = MatrixMultiplication(BoneArray.ToMatrixWithScale(), MeshComponentToWorld.ToMatrixWithScale());
	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}

static double Calc3D_Dist(const Vector3& Src, const Vector3& Dst) {
	return sqrtf(pow((Src.x - Dst.x), 2) + pow((Src.y - Dst.y), 2) + pow((Src.z - Dst.z), 2));
}

#endif