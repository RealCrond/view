#pragma once
#include <vector>
#include "dispevent.h"
#include "firstctrl.h"
#include "secondctrl.h"
#include "thirdctrl.h"


class CDispEventManager
{
public:
	CDispEventManager();
	virtual ~CDispEventManager();

	void RegHandler(CDispEvent* const pDispEvnet);
	void UnregHandler(CDispEvent* const pDispEvnet);
	void ClearHandler();

	virtual void DispEvent(CMessage *const pcMsg);

private:
	void CreateWebObj();
	void DeleteWebObj();

private:
	std::vector<CDispEvent*>		m_vpDispEvent;
	CFirstCtrl*						m_pFirstCtrl;
	CSecondCtrl*					m_pSecondCtrl;
	CThirdCtrl*						m_pThirdCtrl;
};