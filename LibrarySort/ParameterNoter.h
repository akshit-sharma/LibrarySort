#pragma once

// source : https://msdn.microsoft.com/en-us/library/windows/desktop/ms682516(v=vs.85).aspx

#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define MAX_THREADS 3
#define BUF_SIZE 255

class ParameterNoter{

// Sample custom data structure for threads to use.
// This is passed by void pointer so it can be any data type
// that can be passed using a single void pointer (LPVOID).
typedef struct MyData {
	int val1;
	int val2;
} MYDATA, *PMYDATA;

public:
	DWORD WINAPI MyThreadFunction(LPVOID lpParam);
	void ErrorHandler(LPTSTR lpszFunction);

};