#include "CUtility.h"

CUtils::CUtils()
{

}

CUtils::~CUtils()
{

}

void CUtils::Log(char* log, ...)
{
	char result[1024] = { 0 };
	FILE* fh;
	fopen_s(&fh,"log.txt", "a+");

	va_list arg;
	va_start(arg, log);
	vsnprintf(result, sizeof(result) - 1, log, arg);
	fwrite(result, sizeof(char), strlen(result), fh);

	va_end(arg);

	fwrite("\n", sizeof(char), 1, fh);
	fclose(fh);
}