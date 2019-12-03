#pragma once
#include "eventdisposer.h"

class CCtrlApp1 : public CEventDisposer
{
public:
	CCtrlApp1();
	~CCtrlApp1();

private:
	int OnCameraSelectCmd(CMessage *const pcMsg);

	DECLEAR_MSG_MAP()
};