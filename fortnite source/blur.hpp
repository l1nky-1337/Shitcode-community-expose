#pragma once
#include<string>
#include<sstream>
#include<vector>
#include<math.h>

#include <d3dx11.h>
#include <d3d9.h>

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"


extern void DrawBackgroundBlur(ImDrawList* drawList, IDirect3DDevice9* device);
