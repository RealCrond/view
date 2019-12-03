#pragma once
#include "eventdisposer.h"

class CCtrlApp3 : public CEventDisposer
{
public:
	CCtrlApp3();
	~CCtrlApp3();

private:
	int OnCameraSelectCmd(CMessage *const pcMsg);

	DECLEAR_MSG_MAP()
};