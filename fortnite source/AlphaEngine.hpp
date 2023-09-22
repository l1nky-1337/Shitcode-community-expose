#ifndef ALPHAENGINE_HPP
#define ALPHAENGINE_HPP
#include "stdafx.hpp"
uintptr_t Alpha = 0xDD92EE0 + 0xE;
BYTE Valeur = 127;

void ChangeAlphaEngine(BYTE value)
{
	ctx->write_physical_memory<BYTE>(DriverVar::module + Alpha, value);
}

#endif