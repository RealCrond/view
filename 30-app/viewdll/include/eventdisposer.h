#pragma once
#include "IDispevent.h"

class CEventDisposer;
typedef	void	(CEventDisposer::*DISPEVENT_FUNC)(CMessage* pCMsg);

class CEventDisposer : public IDispEvent
{
public:
	CEventDisposer();
	virtual ~CEventDisposer();

	virtual void DispEvent(CMessage* pCMsg);

	bool HasRegEvent();

	int testFunc(CMessage *const pcMsg);

protected:
	std::map<int, DISPEVENT_FUNC> m_mapMsgFunc;
	std::map<int, std::string> m_mapMsgAlias;

};


#define DECLEAR_MSG_MAP() \
private: \
	std::map<int, DISPEVENT_FUNC>	m_mapMsgFunc;  \
	std::map<int, std::string>		m_mapMsgAlias; \
	virtual const std::map<int, DISPEVENT_FUNC> GetMessageMap() const;	\
	virtual void BuildMsgMap();	\


#define BEGIN_MSG_MAP(theClass) \
	const std::map<int, DISPEVENT_FUNC> theClass::GetMessageMap() const	\
	{	\
		return m_mapMsgFunc;	\
	}	\
	void theClass::BuildMsgMap(){	\


#define REG_MSG(eventID, callFunc)	\
	m_mapMsgFunc.insert(	\
	std::make_pair<int, DISPEVENT_FUNC>( eventID, (DISPEVENT_FUNC)( int (CEventDisposer::*)(CMessage *const) )&callFunc )	\
	);	\

#define END_MSG_MAP()	\
	}	\