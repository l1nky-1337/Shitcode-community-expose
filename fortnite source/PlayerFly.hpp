
enum class EMovementMode
{
	MOVE_None = 0,
	MOVE_Walking = 1,
	MOVE_NavWalking = 2,
	MOVE_Falling = 3,
	MOVE_Swimming = 4,
	MOVE_Flying = 5,
	MOVE_Custom = 6,
	MOVE_MAX = 7,
};
bool playerFly = false;

void PlayerFly()
{
	if (enable_exploit_client)
	{
		if (LocalPawn_base)
		{
			if (playerFly)
			{
				uintptr_t MovementRead = ctx->read_physical_memory<uintptr_t>(LocalPawn_base + 0x160 + 0x201);
				ctx->write_physical_memory<BYTE>(MovementRead, 5);
	
			}
		}
	}
}