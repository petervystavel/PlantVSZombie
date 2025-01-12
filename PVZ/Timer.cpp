#include "Timer.h"

bool Timer::Update(float dt)
{
	mProgress += dt;

	if (mProgress < mTime)
		return false;

	mProgress = 0.0f;

	return true;
}