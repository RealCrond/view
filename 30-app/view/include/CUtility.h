#pragma once
#include <stdarg.h> 
#include <stdio.h>
#include <string>

class CUtils
{
public:
	CUtils();
	~CUtils();

public:
	static void Log(char* log, ...);
};