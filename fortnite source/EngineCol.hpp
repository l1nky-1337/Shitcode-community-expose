#ifndef ENGINECOL_HPP
#define ENGINECOL_HPP
#include "stdafx.hpp"


//4EC ref
//if (v3) //48 8B 05 ? ? ? ? 48 33 C4 48 89 45 30 4C 8B 3A 45 33 ED 40 8A 79 30 4C 8B E2 F3 44 0F 10 0D
//{
//	v8 = _mm_min_ps(_mm_max_ps(v7, (__m128)xmmword_14C9DABB0), (__m128)xmmword_14C9DABA0);
//	v9 = _mm_srli_epi32(_mm_sub_epi32((__m128i)v8, (__m128i)xmmword_14C9DABB0), 0x14u);
//	v10 = _mm_shuffle_epi32(
//		_mm_or_si128(
//			_mm_cvttps_epi32(_mm_add_ps(_mm_mul_ps((__m128)xmmword_14C9DABE0, v8), (__m128)xmmword_14C9DABF0)),
//			_mm_srli_epi32(
//				_mm_madd_epi16(
//					_mm_unpacklo_epi64(
//						_mm_unpacklo_epi32(
//							_mm_cvtsi32_si128(*(_DWORD*)&aSZ[4 * _mm_cvtsi128_si32(v9)]),
//							_mm_cvtsi32_si128(*(_DWORD*)&aSZ[4 * _mm_extract_epi16(v9, 2)])),
//						_mm_cvtsi32_si128(*(_DWORD*)&aSZ[4 * _mm_extract_epi16(v9, 4)])),
//					_mm_or_si128(
//						_mm_load_si128((const __m128i*) & xmmword_14C9DABD0),
//						_mm_and_si128(_mm_srli_epi32((__m128i)v8, 0xCu), (__m128i)xmmword_14C9DABC0))),
//				0x10u)),
//		198);
//	v11 = _mm_packs_epi32(v10, v10);
//	v12 = _mm_cvtsi128_si32(_mm_packus_epi16(v11, v11));
//}
//else
//{
//	HIBYTE(v113) = (int)(float)((float)(fminf(fmaxf(v111.m128_f32[3], 0.0), 1.0) * 255.0) + 0.5);
//	v6 = v134;
//	LOBYTE(v113) = (int)(float)((float)(fminf(fmaxf(v111.m128_f32[2], 0.0), 1.0) * 255.0) + 0.5);
//	BYTE1(v113) = (int)(float)((float)(fminf(fmaxf(v111.m128_f32[1], 0.0), 1.0) * 255.0) + 0.5);
//	BYTE2(v113) = (int)(float)((float)(fminf(fmaxf(v111.m128_f32[0], 0.0), 1.0) * 255.0) + 0.5);
//	v12 = v113;
//}

//if (dword_14EB1C37C && (*(_DWORD*)(a1 + 8) & 0x40030) == 0 && (unsigned __int8)qword_14E95BF10 >= 3u) //48 8D 6C 24 ? 48 81 EC ? ? ? ? 45 8A F8 44 0F B6 F2 - ref STAT_NiagaraComponentActivate
//{
//	v11 = sub_140DE0B7C(a1, v65, 0i64, 0i64);
//	if (*(_DWORD*)(v11 + 8))
//		v12 = *(void**)v11;
//	else
//		v12 = &unk_14A945FBC;
//	sub_140CBED48(&qword_14E95BF10, &unk_14C13F4F0, v12);
//	sub_140CAE330(v65);
//}

namespace EngineVar {
	static constexpr uintptr_t Color = 0xC9DABD0; //C9DABD0
	static constexpr uintptr_t ColorBeforeSimple = 0xC9DABA0; //C9DABA0
	static bool ColorUI = false;
}



namespace EngineVoid {
	static void ChangeColor(int red, int green, int blue) {
			ctx->write_physical_memory<int>(DriverVar::module + EngineVar::Color + 3, red);
			ctx->write_physical_memory<int>(DriverVar::module + EngineVar::Color + 7, green);
			ctx->write_physical_memory<int>(DriverVar::module + EngineVar::Color + 0xB, blue);	
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ChangeColorBeforeSimple(int red, int green, int blue) {
		ctx->write_physical_memory<int>(DriverVar::module + EngineVar::ColorBeforeSimple + 3, red); //7
		ctx->write_physical_memory<int>(DriverVar::module + EngineVar::ColorBeforeSimple + 7, green); //3
		ctx->write_physical_memory<int>(DriverVar::module + EngineVar::ColorBeforeSimple + 0xB, blue); //B
	
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void GreenNite()
	{
		ChangeColorBeforeSimple(0x3A, 0x44, 0x3A);
	}
	void DarkNite()
	{
		//ChangeColorBeforeSimple(0x3A, 0x44, 0x3A);
		ChangeColor(3, 3, 3);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ChangeToRed() { ChangeColor(57, 0, 0); }
	static void ChangeToGreen() { ChangeColor(0, 57, 0); }
	static void ChangeToBlue() { ChangeColor(0, 0, 57); }
	static void Reset() { ChangeColor(0, 0, 0);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	void changeREDREEL()
	{
		
		ChangeColor(3, 0, 0);
		
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void changeTURQUASE()
	{

		ChangeColor(0, 3, 1);

	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void changeBLUE()
	{

		ChangeColor(0, 1, 3);

	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void changeBlack()
	{

		ChangeColor(0, 0, 0);

	}
	int RedEngine = 3;
	int GreenEngine = 3;
	int BlueEngine = 3;

	void ChangeColorCUstom()
	{
		ChangeColor(RedEngine, GreenEngine, BlueEngine);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ZoneAlertToScreen()
	{
		bool OutiseZoneToScreenAlert = ctx->read_physical_memory<bool>(LocalPawn_base + 0x5a00);
		if (visuals::OutsideZone)
		{
			if (LocalPawn_base)
			{
				if (OutiseZoneToScreenAlert == true)
				{
					ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(0, 0), 9999, IM_COL32(cross_r, cross_g, cross_b, 70), 100);
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void GameUIRainbow()
	{
		if (EngineVar::ColorUI)
		{
			
			ctx->write_physical_memory<int>(DriverVar::module + EngineVar::Color + 3, scaledGameUI_r);
			ctx->write_physical_memory<int>(DriverVar::module + EngineVar::Color + 7, scaledGameUI_g);
			ctx->write_physical_memory<int>(DriverVar::module + EngineVar::Color + 0xB, scaledGameUI_b);
				//ctx->write_physical_memory<int>(DriverVar::module + EngineVar::Color + 0xF, 0x3F);
			
		}
	}

}


#endif