#pragma once
#include "eventdisposer.h"

class CCtrlApp2 : public CEventDisposer
{
public:
	CCtrlApp2();
	~CCtrlApp2();

private:
	int OnCameraSelectCmd(CMessage *const pcMsg);

	DECLEAR_MSG_MAP()
};