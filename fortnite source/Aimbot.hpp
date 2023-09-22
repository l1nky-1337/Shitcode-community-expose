#pragma once

static bool isVisible(DWORD_PTR mesh)
{
	float fLastSubmitTime = ctx->read_physical_memory<float>(mesh + 0x360); //UPrimitiveComponent - BoundScale = 0x354; + LastSumbitTime = 0x4;
	float fLastRenderTimeOnScreen = ctx->read_physical_memory<float>(mesh + 0x368); //UPrimitiveComponent - BoundScale = 0x354; + LastRenderTimeOnScreen = 0xC;
	return fLastRenderTimeOnScreen + 0.06f >= fLastSubmitTime;
}

static auto move_to(float x, float y) -> void {
	float center_x = (ImGui::GetIO().DisplaySize.x / 2);
	float center_y = (ImGui::GetIO().DisplaySize.y / 2);

	float smooth = aimbot::aimspeed;
	smooth = aimbot2::aimspeed;
	smooth = aimbot3::aimspeed;
	smooth = aimbot4::aimspeed;
	smooth = aimbot5::aimspeed;

	float target_x = 0.f;
	float target_y = 0.f;

	if (x != 0.f)
	{
		if (x > center_x)
		{
			target_x = -(center_x - x);
			target_x /= smooth;
			if (target_x + center_x > center_x * 2.f) target_x = 0.f;
		}

		if (x < center_x)
		{
			target_x = x - center_x;
			target_x /= smooth;
			if (target_x + center_x < 0.f) target_x = 0.f;
		}
	}

	if (y != 0.f)
	{
		if (y > center_y)
		{
			target_y = -(center_y - y);
			target_y /= smooth;
			if (target_y + center_y > center_y * 2.f) target_y = 0.f;
		}

		if (y < center_y)
		{
			target_y = y - center_y;
			target_y /= smooth;
			if (target_y + center_y < 0.f) target_y = 0.f;
		}
	}

	MouseController::Move_Mouse((int)target_x, (int)(target_y));
}

