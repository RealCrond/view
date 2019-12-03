#include "stdafx.h"
#include "ctrlmgr.h"


CCtrlManager::CCtrlManager():
	m_pCtrlApp1(NULL),
	m_pCtrlApp2(NULL),
	m_pCtrlApp3(NULL)
{
#define NEW_REG(pIMtc, clsName) \
	pIMtc = new clsName();      \
	RegHandler(pIMtc);

	NEW_REG(m_pCtrlApp1, CCtrlApp1)
	NEW_REG(m_pCtrlApp2, CCtrlApp2)
	NEW_REG(m_pCtrlApp3, CCtrlApp3)
}

CCtrlManager::~CCtrlManager()
{

}

void CCtrlManager::RegHandler(CEventDisposer* const pEventDisposer)
{
	m_vpDispEvent.push_back(pEventDisposer);
}

void CCtrlManager::DispEvent(CMessage *const pcMsg)
{
	std::vector<CEventDisposer*>::iterator itr = m_vpDispEvent.begin();
	if ( itr != m_vpDispEvent.end() )
	{
		(*itr)->DispEvent(pcMsg);
	}
}