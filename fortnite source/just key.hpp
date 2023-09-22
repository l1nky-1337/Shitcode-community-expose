static bool menu_key = false;

static auto shortcurts() -> void
{
	//while (1)
	//{
	//	if (MouseController::GetAsyncKeyState(VK_F2) & 1) {
	//		menu_key = !menu_key;
	//		ImGui::GetIO().MouseDrawCursor = is_open();
	//	}
	//	Sleep(1);
	//}

	if (GetAsyncKeyState(VK_F2))
	{
		
		if (menu_key == false)
		{
		//	ImGui::InsertNotification({ ImGuiToastType_Success, 3000, "Cheat opened !" });
			menu_key = true;
	
		}
		else if (menu_key == true)
		{
			//ImGui::InsertNotification({ ImGuiToastType_Success, 3000, "Cheat Closed !" });
			menu_key = false;
	
		}
		Sleep(100);
	}
}


static const char* keyNames[] =
{
	"",
	"LMB1",
	"LMB2",
	"Cancel",
	"Middle Mouse",
	"Mouse 5",
	"Mouse 4",
	"",
	"Backspace",
	"Tab",
	"",
	"",
	"Clear",
	"Enter",
	"",
	"",
	"Shift",
	"Control",
	"Alt",
	"Pause",
	"Caps",
	"",
	"",
	"",
	"",
	"",
	"",
	"Escape",
	"",
	"",
	"",
	"",
	"Space",
	"Page Up",
	"Page Down",
	"End",
	"Home",
	"Left",
	"Up",
	"Right",
	"Down",
	"",
	"",
	"",
	"Print",
	"Insert",
	"Delete",
	"",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",
	"",
	"",
	"",
	"",
	"",
	"Numpad 0",
	"Numpad 1",
	"Numpad 2",
	"Numpad 3",
	"Numpad 4",
	"Numpad 5",
	"Numpad 6",
	"Numpad 7",
	"Numpad 8",
	"Numpad 9",
	"Multiply",
	"Add",
	"",
	"Subtract",
	"Decimal",
	"Divide",
	"F1",
	"F2",
	"F3",
	"F4",
	"F5",
	"F6",
	"F7",
	"F8",
	"F9",
	"F10",
	"F11",
	"F12",
};
static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}
static int keystatus = 0;
static int realkey = 0;
static bool GetKey(int key)
{
	realkey = key;
	return true;
}
static void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				hotkeys::aimkey = i;
				keystatus = 0;
				return;
			}
		}
	}
}

static void ChangeKey_exploit(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				hotkeys_exploit::keybind = i;
				keystatus = 0;
				return;
			}
		}
	}
}
static void ChangeKey2(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				hotkeys2::aimkey2 = i;
				keystatus = 0;
				return;
			}
		}
	}
}
static void ChangeKey3(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				hotkeys3::aimkey3 = i;
				keystatus = 0;
				return;
			}
		}
	}
}
static void ChangeKey4(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				hotkeys4::aimkey4 = i;
				keystatus = 0;
				return;
			}
		}
	}
}
static void ChangeKey5(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				hotkeys5::aimkey5 = i;
				keystatus = 0;
				return;
			}
		}
	}
}
static void HotkeyButton(int aimkey, void* changekey, int status)
{
	const char* preview_value = "Press Key";
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
		Items_ArrayGetter(keyNames, aimkey, &preview_value);

	std::string aimkeys;
	if (preview_value[0] == '\0')
		aimkeys = "your key ?";
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = "Press key to bind";
	}
	if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20)))
	{
		if (status == 0)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}