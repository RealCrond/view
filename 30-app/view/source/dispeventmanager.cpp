#include "dispeventmanager.h"

CDispEventManager::CDispEventManager():
	m_pFirstCtrl(NULL),
	m_pSecondCtrl(NULL),
	m_pThirdCtrl(NULL)
{
	CreateWebObj();
}

CDispEventManager::~CDispEventManager()
{
	DeleteWebObj();
}

void CDispEventManager::CreateWebObj()
{
#define NEW_REG(pIMtc, className) \
	pIMtc =  new className();\
	RegHandler(pIMtc);

	NEW_REG(m_pFirstCtrl, CDispEvent);
	NEW_REG(m_pSecondCtrl, CDispEvent);
	NEW_REG(m_pThirdCtrl, CDispEvent);
}

void CDispEventManager::DeleteWebObj()
{
#define DEL_UNREG(pcObj) \
	UnregHandler(pcObj); \
	if(NULL != pcObj) \
	{ \
		delete pcObj; \
		pcObj = NULL; \
    }

	DEL_UNREG(m_pFirstCtrl);
	DEL_UNREG(m_pSecondCtrl);
	DEL_UNREG(m_pThirdCtrl);
}

void CDispEventManager::RegHandler(CDispEvent* const pDispEvnet)
{
	m_vpDispEvent.push_back(pDispEvnet);
}

void CDispEventManager::UnregHandler(CDispEvent* const pDispEvnet)
{
	std::vector<CDispEvent*>::iterator itr = m_vpDispEvent.begin();
	for (; itr != m_vpDispEvent.end(); itr++)
	{
		if (*itr == pDispEvnet)
		{
			m_vpDispEvent.erase(itr);
			break;
		}
	}
}

void CDispEventManager::ClearHandler()
{
	m_vpDispEvent.clear();
}

void CDispEventManager::DispEvent(CMessage *const pcMsg)
{
	bool bRet = false;

	//TWebmtcMtMsg tWebmtcMtMsg = *((TWebmtcMtMsg*)pcMsg->content);

	std::vector<CDispEvent*>::iterator itr = m_vpDispEvent.begin();
	for (; itr != m_vpDispEvent.end(); itr++)
	{
		//if ((*itr)->HasRegEvent(tWebmtcMtMsg.m_emEvtId))
		//{
		//	(*itr)->DispEvent(pcMsg);
		//	bRet = true;
		//}
	}

	if (false == bRet)
	{
		//不识别的消息
	}
}

