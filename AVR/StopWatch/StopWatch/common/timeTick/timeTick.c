#include "timeTick.h"

uint32_t timeTick;

void incTick()
{
	timeTick++;
}

void Tick_init()
{
	timeTick = 0;
}

uint32_t getTick()
{
	return timeTick;
}