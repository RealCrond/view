#include "stdafx.h"
#include "eventdisposer.h"

CEventDisposer::CEventDisposer()
{

}

CEventDisposer::~CEventDisposer()
{

}

bool CEventDisposer::HasRegEvent()
{
	std::map<int, DISPEVENT_FUNC>::iterator itr = m_mapMsgFunc.begin();
	if (itr != m_mapMsgFunc.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CEventDisposer::DispEvent(CMessage* pCMsg)
{
	std::map<int,DISPEVENT_FUNC>::iterator itr = m_mapMsgFunc.begin();
	if ( itr != m_mapMsgFunc.end() )
	{
		if ((*itr).first == pCMsg->nEventID)
		{
			DISPEVENT_FUNC pFunc = (*itr).second;
			(this->*pFunc)(pCMsg);
		}
		
	}
}