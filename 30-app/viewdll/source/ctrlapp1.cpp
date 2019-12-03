#include "stdafx.h"
#include "ctrlapp1.h"

CCtrlApp1::CCtrlApp1()
{

}

CCtrlApp1::~CCtrlApp1()
{

}

BEGIN_MSG_MAP(CCtrlApp1)
	REG_MSG(emFistEventId, CCtrlApp1::OnCameraSelectCmd)

END_MSG_MAP()

int CCtrlApp1::OnCameraSelectCmd(CMessage *const pcMsg)
{
	return 0;
}