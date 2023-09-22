#pragma once
#include <FN-font.h>

RECT GameRect;
MARGINS Margin = { -1 };
RECT rc2;

ID3D11Device* g_pd3dDevice;
ID3D11DeviceContext* g_pd3dDeviceContext;
IDXGISwapChain* g_pSwapChain;
ID3D11RenderTargetView* g_mainRenderTargetView;

HWND GameWnd;
HWND MyWnd;
WNDCLASSEX wClass;

MSG Message = { NULL };

ImFont* SkeetFont;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void CreateRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
	pBackBuffer->Release();
}
void CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}
void CleanupDeviceD3D()
{
	CleanupRenderTarget();
	if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
	if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			CleanupRenderTarget();
			g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			CreateRenderTarget();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

HRESULT DirectXInit(HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC SwapChainDesc;
	ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	SwapChainDesc.Windowed = TRUE;
	SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	SwapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	SwapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	SwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	SwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	SwapChainDesc.BufferDesc.Height = 0;
	SwapChainDesc.BufferDesc.Width = 0;
	SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	SwapChainDesc.BufferCount = 1;
	SwapChainDesc.OutputWindow = MyWnd;
	SwapChainDesc.SampleDesc.Count = 8;
	SwapChainDesc.SampleDesc.Quality = 0;


	UINT createDeviceFlags = 0;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &SwapChainDesc, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
		return false;

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	auto& style = ImGui::GetStyle();

	ImGui::SetNextWindowSize(io.DisplaySize);
	io.IniFilename = NULL;




	io.Fonts->AddFontFromMemoryTTF(&seguoe, sizeof seguoe, 18, NULL, io.Fonts->GetGlyphRangesCyrillic());

	default_segu = io.Fonts->AddFontFromMemoryTTF(&seguoe, sizeof seguoe, 18, NULL, io.Fonts->GetGlyphRangesCyrillic());

	segu = io.Fonts->AddFontFromMemoryTTF(&seguoe, sizeof seguoe, 40, NULL, io.Fonts->GetGlyphRangesCyrillic());

	bold_segu = io.Fonts->AddFontFromMemoryTTF(&bold_segue, sizeof bold_segue, 40, NULL, io.Fonts->GetGlyphRangesCyrillic());

	ico = io.Fonts->AddFontFromMemoryTTF(&icon, sizeof icon, 24, NULL, io.Fonts->GetGlyphRangesCyrillic());

	ico_combo = io.Fonts->AddFontFromMemoryTTF(&icon, sizeof icon, 19, NULL, io.Fonts->GetGlyphRangesCyrillic());

	ico_button = io.Fonts->AddFontFromMemoryTTF(&icon, sizeof icon, 25, NULL, io.Fonts->GetGlyphRangesCyrillic());

	ico_grande = io.Fonts->AddFontFromMemoryTTF(&icon, sizeof icon, 40, NULL, io.Fonts->GetGlyphRangesCyrillic());

	ImGui::StyleColorsDark();

	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

	ID3D11Texture2D* pBackBuffer;
	g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);

	ImGui_ImplWin32_Init(MyWnd);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

	pBackBuffer->Release();

	SetWindowPos(MyWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);

}
bool SetupWindow()
{
	while (!MyWnd) {
		MyWnd = SetUp::HiJackNotepadWindow();
		Sleep(10);
	}

	MARGINS margin = { -1 };
	DwmExtendFrameIntoClientArea(MyWnd, &margin);
	SetMenu(MyWnd, NULL);
	SetWindowLongPtr(MyWnd, GWL_STYLE, WS_VISIBLE);
	SetWindowLongPtr(MyWnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT);

	ShowWindow(MyWnd, SW_SHOW);
	UpdateWindow(MyWnd);

	SetWindowLong(MyWnd, GWL_EXSTYLE, GetWindowLong(MyWnd, GWL_EXSTYLE) | WS_EX_LAYERED | WS_EX_TRANSPARENT);

	return true;
}
//.rdata:000000014B867740		ymmword 0000803F0000803F0000803F0000803F0000803F0000803F0000803F0000803F
//.rdata:000000014DA40250		xmmword 400000003F8000003F8000003F800000h
//.rdata : 000000014C894D7C		xmmword 3F800000BF800000BF800000BF800000h
//.rdata : 000000014BE64470		xmmword 3F8000003F8000003F800000h
//.rdata : 000000014C891460		xmmword 3F8000003F8000003F800000h
//.rdata : 000000014BE71F14		xmmword 3F8000003F8000003F800000BF800000h
//.rdata : 000000014BDC0E40		xmmword 3F8000003F8000003F8000003F800000h
//.rdata : 000000014BE6ECE0		xmmword 3F8000003F8000003F8000003F800000h
//.rdata : 000000014C8915E0		xmmword 3F8000003F8000003F8000003F800000h
//.data : 000000014E6F2F24		xmmword 3F8000003F8000003F80000000000001h
//.data : 000000014E727094		xmmword 3F8000003F8000003F80000000000000h
//.rdata : 000000014DA3FDEC		xmmword 3F8000003F19999A3F3333333F666666h
//.rdata : 000000014BDC1804		xmmword 3F800000000000000000000000000000h
//.data : 000000014E726A9C		xmmword 3F800000000000000000000000000000h
//.rdata : 000000014DA3F990		xmmword 3F19999A3F8000003F8000003F800000h
//.rdata : 000000014C895050		xmmword 3F0000003F8000003F8000003F800000h
//.rdata : 000000014C891F10		xmmword 3EB333333F8000003F8000003F800000h
//.rdata : 000000014C8951B0		xmmword 3DCCCCCD3F8000003F8000003F800000h


void init_all()
{
	if (LocalPawn_base)
	{
		//ctx->write_physical_memory<BYTE>(LocalPawn_base + Character::Mesh + 0x194, 0xFF);
		/*list_exploit();
		list_tp();*/
		//Controller::InitControllers();

		notify_game_information();


		ColorChangeCrosshair();
		//TitleRainbow();


		//visual exploit read init
		EngineVoid::GameUIRainbow();
		EngineVoid::ZoneAlertToScreen();

		//EngineVoid::chams_test();
		//write<float>(DriverVar::module + 0xC891F18, 2);


		//server exploit
		//InitTable::InitFunction();
		//VehicleExploit_hook::infinity_fuel();

		//CarToPing_hook();
		//test_tp();
		//Client Exploit
		//SpinBot_Client_hook();
		//SpinBot_Client_entity_actor_hook();
		//enable_use_info();

	//	ctx->write_physical_memory<bool>(Off_player_controller + 0x2000, true);

	}

	draw_eso();
	pre_start_ploop();
	//FOVINITANGLE();
	ColorChange();
	Watermark_Product();
	shortcurts();
	BoxRainbow();
	GameRainbow();
	crosshair();
	crosshairglow();
	crosshair_nazi();
}