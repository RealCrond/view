#pragma once

#include <map>

enum EmEvent_Api
{
	emEvt_Unknown,
	emFirst,
	emSecond,
	emThird,
};

typedef struct tagTWebmtcMtMsg
{
	//tagTWebmtcMtMsg() { memset(this, 0, sizeof(tagTWebmtcMtMsg)); }
	//signed char m_achIP[_nIPLen_Max_ + 1];                           ///< 用户IP
	int m_nFcgiNodeId;                                      ///< Fcgi Node Id
	//EM_EVENT_ID m_emEvtId;                                  ///< Event Id
	//s8 m_achUserId[_nIPLen_Max_ + 1];                       ///< 用户Id (唯一标志符)
	//u32 m_dwSessionId;                                      ///< skymtc用户Id
	//BOOL32 bFreeLoginUser;                                  ///< 免登录用户
	//BOOL32 bSynchronous;                                    ///< 同步消息	
	//u32 m_dwEventType;                                      ///< EventType
	//s32 m_dwWebapiVersion;                                 ///<  版本号长度 
	//s8 m_achEventId[MAX_USER_NAME_LEN + 1];                  ///< 属性Id (唯一标志符)
	//s8 m_achJsonBody[_nJsonBodyLen_Max_ + 1];              ///< Json body data
public:
	tagTWebmtcMtMsg() { memset(this, 0, sizeof(tagTWebmtcMtMsg)); }
} TWebmtcMtMsg;

//消息头部结构
typedef struct tagCMessage {
	//源结点
	unsigned long srcnode;
	//目的结点
	unsigned long dstnode;
	//目的应用实例
	unsigned long dstid;
	//源目的实例
	unsigned long srcid;
	//消息类型
	unsigned short type;
	//消息号
	unsigned short event;
	//消息体长度
	unsigned short length;
	//消息体
	char *content;

	//如果支持同步消息
#ifdef SYNCMSG
	//同步消息应答
	u8 *output;
	//同步消息应答长度
	u16 outlen;
	//未使用
	u16 expire;
#endif

	//实例别名
	char *dstAlias;
	//实例别名长度
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
	bool HasRegEvent(signed int nEvtId) const;

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