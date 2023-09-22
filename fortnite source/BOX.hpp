float item_size = 22;
float boxsize = 0.430f;
static ImFont* Verdana, * Verdana2, * DefaultFont;

static auto string_To_UTF8(const std::string& str) -> std::string
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}
static auto WStringToUTF8(const wchar_t* lpwcszWString) -> std::string
{
	char* pElementText;
	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
	std::string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}
static auto MBytesToWString(const char* lpcszString) -> std::wstring
{
	int len = strlen(lpcszString);
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
	wchar_t* pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
	std::wstring wString = (wchar_t*)pUnicode;
	delete[] pUnicode;
	return wString;
}
void DrawStrokeText(int x, int y, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);

	ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetBackgroundDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetBackgroundDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y), IM_COL32(cross_r, cross_g, cross_b, cross_a), utf_8_2.c_str());
}
static auto DrawLine(int x1, int y1, int x2, int y2, ImU32 color, int thickness) -> void
{
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), IM_COL32(cross_r, cross_g, cross_b, 255), thickness);
}
static auto DrawLineV2(int x1, int y1, int x2, int y2, ImColor color, int thickness) -> void
{
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), IM_COL32(crosshair_r, crosshair_g, crosshair_b, cross_a), thickness);
}
static auto DrawTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, RGBA* color) -> void
{
	ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}
static auto DrawFilledRect(int x, int y, int w, int h, ImU32& color)-> void
{
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::GetColorU32(color), 0, 0);
}
static auto DrawRectBox(int x, int y, int w, int h, ImU32& color) -> void
{
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::GetColorU32(color), 0, 0);
}

static auto DrawFilledRect(int x, int y, int w, int h, RGBA* color)-> void
{
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
}
void draw_line(ImVec2 a, ImVec2 b, ImU32 col)
{
	ImGui::GetBackgroundDrawList()->AddLine(a, b, col);
}
void draw_line3D(ImVec2 a, ImVec2 b, ImU32 color)
{
	ImGui::GetBackgroundDrawList()->AddLine(a, b, color);
}

void draw_border(ImVec2 corners2d[8], ImU32 col)
{
	draw_line(corners2d[0], corners2d[1], col);
	draw_line(corners2d[0], corners2d[2], col);
	draw_line(corners2d[0], corners2d[4], col);
	draw_line(corners2d[1], corners2d[3], col);
	draw_line(corners2d[1], corners2d[5], col);
	draw_line(corners2d[2], corners2d[3], col);
	draw_line(corners2d[2], corners2d[6], col);
	draw_line(corners2d[3], corners2d[7], col);
	draw_line(corners2d[4], corners2d[5], col);
	draw_line(corners2d[4], corners2d[6], col);
	draw_line(corners2d[6], corners2d[7], col);
	draw_line(corners2d[5], corners2d[7], col);
}

// Utilisation des variables Headbox, CornerHeight, CornerWidth, Colorsimple et Colordouble
void draw_corner_box(Vector3 head, Vector3 bottom, float boxsize, ImVec4 col)
{
	Vector3 Headbox = ProjectWorldToScreen(Vector3(head.x, head.y, head.z + 15));
	float CornerHeight = abs(Headbox.y - bottom.y);
	float CornerWidth = CornerHeight * boxsize;

	ImVec2 corners2d[8];

	// Calcul des coordonnées des coins
	corners2d[0] = ImVec2(Headbox.x - CornerWidth, Headbox.y - CornerHeight);
	corners2d[1] = ImVec2(Headbox.x + CornerWidth, Headbox.y - CornerHeight);
	corners2d[2] = ImVec2(Headbox.x - CornerWidth, Headbox.y + CornerHeight);
	corners2d[3] = ImVec2(Headbox.x + CornerWidth, Headbox.y + CornerHeight);
	corners2d[4] = ImVec2(bottom.x - CornerWidth, bottom.y - CornerHeight);
	corners2d[5] = ImVec2(bottom.x + CornerWidth, bottom.y - CornerHeight);
	corners2d[6] = ImVec2(bottom.x - CornerWidth, bottom.y + CornerHeight);
	corners2d[7] = ImVec2(bottom.x + CornerWidth, bottom.y + CornerHeight);

	// Dessin du contour de la boîte
	draw_border(corners2d, ImGui::GetColorU32(col));
}
void draw_corners(ImVec2 corners2d[8], std::float_t length, ImU32 color)
{
	ImVec2 mid_points[12][2];

	auto calculate_mid_points = [&](const ImVec2 a, const ImVec2 b, ImVec2* c, ImVec2* d, const std::float_t e)
	{
		c->x = b.x + (a.x - b.x) / e * (e - 1.0f);
		c->y = b.y + (a.y - b.y) / e * (e - 1.0f);

		d->x = b.x + (a.x - b.x) / e;
		d->y = b.y + (a.y - b.y) / e;
	};

	calculate_mid_points(corners2d[0], corners2d[1], &mid_points[0][0], &mid_points[0][1], length);
	calculate_mid_points(corners2d[0], corners2d[2], &mid_points[1][0], &mid_points[1][1], length);
	calculate_mid_points(corners2d[0], corners2d[4], &mid_points[2][0], &mid_points[2][1], length);
	calculate_mid_points(corners2d[1], corners2d[3], &mid_points[3][0], &mid_points[3][1], length);
	calculate_mid_points(corners2d[1], corners2d[5], &mid_points[4][0], &mid_points[4][1], length);
	calculate_mid_points(corners2d[2], corners2d[3], &mid_points[5][0], &mid_points[5][1], length);
	calculate_mid_points(corners2d[2], corners2d[6], &mid_points[6][0], &mid_points[6][1], length);
	calculate_mid_points(corners2d[3], corners2d[7], &mid_points[7][0], &mid_points[7][1], length);
	calculate_mid_points(corners2d[4], corners2d[5], &mid_points[8][0], &mid_points[8][1], length);
	calculate_mid_points(corners2d[4], corners2d[6], &mid_points[9][0], &mid_points[9][1], length);
	calculate_mid_points(corners2d[6], corners2d[7], &mid_points[10][0], &mid_points[10][1], length);
	calculate_mid_points(corners2d[5], corners2d[7], &mid_points[11][0], &mid_points[11][1], length);

	draw_line3D(corners2d[0], mid_points[0][0], color);
	draw_line3D(corners2d[0], mid_points[1][0], color);
	draw_line3D(corners2d[0], mid_points[2][0], color);
	draw_line3D(corners2d[1], mid_points[3][0], color);
	draw_line3D(corners2d[1], mid_points[4][0], color);
	draw_line3D(corners2d[2], mid_points[5][0], color);
	draw_line3D(corners2d[2], mid_points[6][0], color);
	draw_line3D(corners2d[3], mid_points[7][0], color);
	draw_line3D(corners2d[4], mid_points[8][0], color);
	draw_line3D(corners2d[4], mid_points[9][0], color);
	draw_line3D(corners2d[6], mid_points[10][0], color);
	draw_line3D(corners2d[5], mid_points[11][0], color);

	draw_line3D(corners2d[1], mid_points[0][1], color);
	draw_line3D(corners2d[2], mid_points[1][1], color);
	draw_line3D(corners2d[4], mid_points[2][1], color);
	draw_line3D(corners2d[3], mid_points[3][1], color);
	draw_line3D(corners2d[5], mid_points[4][1], color);
	draw_line3D(corners2d[3], mid_points[5][1], color);
	draw_line3D(corners2d[6], mid_points[6][1], color);
	draw_line3D(corners2d[7], mid_points[7][1], color);
	draw_line3D(corners2d[5], mid_points[8][1], color);
	draw_line3D(corners2d[6], mid_points[9][1], color);
	draw_line3D(corners2d[7], mid_points[10][1], color);
	draw_line3D(corners2d[7], mid_points[11][1], color);
}
static auto DrawCornerBox(int x, int y, int w, int h, int borderPx, ImU32& color) -> void
{
	DrawFilledRect(x + borderPx, y, w / 3, borderPx, color); //top 
	DrawFilledRect(x + w - w / 3 + borderPx, y, w / 3, borderPx, color); //top 
	DrawFilledRect(x, y, borderPx, h / 3, color); //left 
	DrawFilledRect(x, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color); //left 
	DrawFilledRect(x + borderPx, y + h + borderPx, w / 3, borderPx, color); //bottom 
	DrawFilledRect(x + w - w / 3 + borderPx, y + h + borderPx, w / 3, borderPx, color); //bottom 
	DrawFilledRect(x + w + borderPx, y, borderPx, h / 3, color);//right 
	DrawFilledRect(x + w + borderPx, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color);//right 
}
static auto DrawNormalBox(int x, int y, int w, int h, int borderPx, ImU32& color) -> void
{
	DrawFilledRect(x + borderPx, y, w, borderPx, color); //top 
	DrawFilledRect(x + w - w + borderPx, y, w, borderPx, color); //top 
	DrawFilledRect(x, y, borderPx, h, color); //left 
	DrawFilledRect(x, y + h - h + borderPx * 2, borderPx, h, color); //left 
	DrawFilledRect(x + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawFilledRect(x + w - w + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawFilledRect(x + w + borderPx, y, borderPx, h, color);//right 
	DrawFilledRect(x + w + borderPx, y + h - h + borderPx * 2, borderPx, h, color);//right 
}
static auto DrawNormalBox_filled(int x, int y, int w, int h, int borderPx, ImU32& color) -> void
{
	DrawRectBox(x + borderPx, y, w, borderPx, color); //top 
	DrawRectBox(x + w - w + borderPx, y, w, borderPx, color); //top 
	DrawRectBox(x, y, borderPx, h, color); //left 
	DrawRectBox(x, y + h - h + borderPx * 2, borderPx, h, color); //left 
	DrawRectBox(x + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawRectBox(x + w - w + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawRectBox(x + w + borderPx, y, borderPx, h, color);//right 
	DrawRectBox(x + w + borderPx, y + h - h + borderPx * 2, borderPx, h, color);//right 
}
static auto DrawString(float fontSize, int x, int y, bool bCenter, bool stroke, const char* pText, ...) -> void
{
	va_list va_alist;
	char buf[4096] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 2;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), IM_COL32(cross_r, cross_g, cross_b, cross_a), text.c_str());
}
static auto DrawString3(float fontSize, int x, int y, bool bCenter, bool stroke, const char* pText, ...) -> void
{
	va_list va_alist;
	char buf[4096] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 2;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), IM_COL32(0, 255, 0, 255), text.c_str());
}
static auto DrawString2(float fontSize, int x, int y, RGBA* color, bool bCenter, bool stroke, const char* pText, ...) -> void
{
	va_list va_alist;
	char buf[4096] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 2;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), text.c_str());
}
static auto DrawCircle(int x, int y, int radius, ImU32 color, int segments) -> void
{
	ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(x, y), radius, IM_COL32(cross_r, cross_g, cross_b, 255), segments, 2);
}
static auto DrawCirclev2(int x, int y, int radius, ImU32 color, int segments) -> void
{
	ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(x, y), radius, IM_COL32(cross_r, cross_g, cross_b, 0), segments, 2);
}
static auto DrawCircleFilled(int x, int y, int radius, RGBA* color) -> void
{
	ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}


static auto DrawOutlinedText(ImFont* pFont, const std::string& text, const ImVec2& pos, float size, ImU32 color, bool center) -> VOID
{
	ImGui::PushFont(Verdana);
	std::stringstream stream(text);
	std::string line;

	float y = 0.0f;
	int index = 0;

	while (std::getline(stream, line))
	{
		ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());

		if (center)
		{
			ImGui::GetBackgroundDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * index) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetBackgroundDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * index) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetBackgroundDrawList()->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * index), ImGui::GetColorU32(color), line.c_str());
		}
		else
		{
			ImGui::GetBackgroundDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * index) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetBackgroundDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * index) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetBackgroundDrawList()->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * index), ImGui::GetColorU32(color), line.c_str());
		}

		y = pos.y + textSize.y * (index + 1);
		index++;
	}
	ImGui::PopFont();
}

void TextCentered(std::string text) {
	auto windowWidth = ImGui::GetWindowSize().x;
	auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

	ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
	ImGui::Text(text.c_str());
}



static auto DrawBone(int64_t pMeshAddress, RGBA color, float thickness) -> void
{
	Vector3 vHeadBone = GetBoneWithRotation(pMeshAddress, 68);
	Vector3 vHip = GetBoneWithRotation(pMeshAddress, 2);
	Vector3 vNeck = GetBoneWithRotation(pMeshAddress, 67);
	Vector3 vUpperArmLeft = GetBoneWithRotation(pMeshAddress, 9);
	Vector3 vUpperArmRight = GetBoneWithRotation(pMeshAddress, 38);
	Vector3 vLeftHand = GetBoneWithRotation(pMeshAddress, 10);
	Vector3 vRightHand = GetBoneWithRotation(pMeshAddress, 39);
	Vector3 vLeftHand1 = GetBoneWithRotation(pMeshAddress, 11);
	Vector3 vRightHand1 = GetBoneWithRotation(pMeshAddress, 40);
	Vector3 vRightThigh = GetBoneWithRotation(pMeshAddress, 78);
	Vector3 vLeftThigh = GetBoneWithRotation(pMeshAddress, 71);
	Vector3 vRightCalf = GetBoneWithRotation(pMeshAddress, 79);
	Vector3 vLeftCalf = GetBoneWithRotation(pMeshAddress, 72);
	Vector3 vLeftFoot = GetBoneWithRotation(pMeshAddress, 74);
	Vector3 vRightFoot = GetBoneWithRotation(pMeshAddress, 81);
	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
	Vector3 vHipOut = ProjectWorldToScreen(vHip);
	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);;


	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), IM_COL32(cross_r, cross_g, cross_b, 255), 2.5f);
}

