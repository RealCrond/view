#pragma once
#include "common.h"

class IDispEvent
{
	virtual void DispEvent(CMessage* pCMsg) = 0;
};
