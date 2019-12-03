#pragma once
#include <string>
#include <Windows.h>


typedef struct tagCMessage
{
	int nEventID;
public:
	tagCMessage() {
		memset(this, 0, sizeof(tagCMessage));
	};
}*pCMessage,CMessage;

enum EmEventID
{
	emUnkonwnEventID = 0,
	emFistEventId,
	emSecondEventId,
	emThirdEventId,
};


typedef void	(__stdcall *VIEWDLLCALLBACK)(UINT nEventID, WPARAM wParam, LPARAM lParam);