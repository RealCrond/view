#pragma once
#include "stdafx.h"
#include "eventdisposer.h"

#include "ctrlapp1.h"
#include "ctrlapp2.h"
#include "ctrlapp3.h"

class CCtrlManager
{
public:
	CCtrlManager();
	virtual ~CCtrlManager();

	void RegHandler(CEventDisposer* const pEventDisposer);

	virtual void DispEvent(CMessage *const pcMsg);


private:
	std::vector<CEventDisposer*> m_vpDispEvent;

	CCtrlApp1* m_pCtrlApp1;
	CCtrlApp2* m_pCtrlApp2;
	CCtrlApp3* m_pCtrlApp3;
};
