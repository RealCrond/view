#include "pch.h"
#include "dispevent.h"

CDispEvent::CDispEvent()
{

}

CDispEvent::~CDispEvent()
{

}


void CDispEvent::DispEvent(CMessage *const pcMsg)
{

}

bool CDispEvent::HasRegEvent(signed int nEvtId) const
{
	bool bRet = false;
	//const MSGMAP* pMap = GetWebMessageMap();
	//if (NULL == pMap)
	//{
	//	return bRet;
	//}

	//MSGMAP_ENTRY* pBegin = const_cast<MSGMAP_ENTRY*>(pMap->lpEntries);
	//while (NULL != pBegin->pFn)
	//{
	//	if (nEvtId == pBegin->nEvtId)
	//	{
	//		bRet = TRUE;
	//		break;
	//	}
	//	pBegin++;
	//}

	return bRet;
}