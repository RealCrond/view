#pragma once

#include <map>

enum EmEvent_Api
{
	emEvt_Unknown,
	emFirst,
	emSecond,
	emThird,
};

//��Ϣͷ���ṹ
typedef struct tagCMessage {
	//Դ���
	unsigned long srcnode;
	//Ŀ�Ľ��
	unsigned long dstnode;
	//Ŀ��Ӧ��ʵ��
	unsigned long dstid;
	//ԴĿ��ʵ��
	unsigned long srcid;
	//��Ϣ����
	unsigned short type;
	//��Ϣ��
	unsigned short event;
	//��Ϣ�峤��
	unsigned short length;
	//��Ϣ��
	char *content;

	//���֧��ͬ����Ϣ
#ifdef SYNCMSG
	//ͬ����ϢӦ��
	u8 *output;
	//ͬ����ϢӦ�𳤶�
	u16 outlen;
	//δʹ��
	u16 expire;
#endif

	//ʵ������
	char *dstAlias;
	//ʵ����������
	unsigned char dstAliasLen;
}*PTCmessage,CMessage;

class IDispEvent
{
public:
	virtual void DispEvent(CMessage *const pcMsg) = 0;
};

class CDispEvent;
typedef unsigned long (CDispEvent::*DISPEVENT_PFUN)(CMessage *const pcMsg);


//Event Disposer
class CDispEvent : public IDispEvent
{
public:
	CDispEvent();
	virtual ~CDispEvent();
	virtual void DispEvent(CMessage *const pcMsg);

private:
	std::map<unsigned short, DISPEVENT_PFUN>	m_mapMsgFunc;
	std::map<unsigned short, std::string>		m_mapMsgHelper;
};

#define   RegMsgFunc(dwEvent, pfMsgFunc)   RegMsgFuncEx(dwEvent ,pfMsgFunc ,#dwEvent)
//RegMsgFunc(Ev_MtApi_Vc_StackInitRes_Ntf,       (PFMsgFunc)&CMtcConfCtrl::OnStackInitRes_Ntf);


#define DECLARE_WEB_MSG_MAP() \
private: \
	static const std::map<unsigned short, DISPEVENT_PFUN>	m_s_WebMessageEntries[]; \
protected: \
	static const std::map<unsigned short, DISPEVENT_PFUN>*	m_s_WebMessageMap; \
	virtual const MSGMAP* GetWebMessageMap() const; \


#define BEGIN_WEB_MSG_MAP( theClass  ) \
	const MSGMAP* theClass::GetWebMessageMap() const \
{ return &theClass::m_s_WebMessageMap; } \
	const MSGMAP theClass::m_s_WebMessageMap = \
{ &theClass::m_s_WebMessageEntries[0] }; \
	const MSGMAP_ENTRY theClass::m_s_WebMessageEntries[] = \
{ \


//#define END_WEB_MSG_MAP() \
//{ \
//	emEvt_Unknown,  0 } \
//}; \


//#define ON_WEB_MSG( eventid, callfunc ) \
//    {  eventid,  (DISPEVENT_PFUN)(u32 (CDispEvent::*)(CMessage *const))&callfunc },

#define END_WEB_MSG_MAP() \
{ 	emEvt_Unknown,  0 } \
}; \

#define ON_WEB_MSG( eventid, callfunc ) \
   m_mapMsgFunc.insert(make_pair(eventid, (DISPEVENT_PFUN)(u32 (CDispEvent::*)(CMessage *const))&callfunc)),