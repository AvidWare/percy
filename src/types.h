#pragma once
#include "stdafx.h"

using namespace std;

#define MAX_PARAM 10

typedef struct _JSON_{} JSON, *PJSON, *LPJSON;

typedef struct _APICALL : JSON {
   string url;
   DWORD delay;
   string param[MAX_PARAM];
   DWORD response_code;
   BOOL success;
   string error;
} APICALL, *PAPICALL, *LPAPICALL;

typedef struct _SETTINGS : JSON {


} SETTINGS, *PSETTINGS, *LPSETTINGS;

typedef struct _PERFORMANCE_DESCRIPTOR : JSON {


} PERFORMANCE_DESCRIPTOR, *PPERFORMANCE_DESCRIPTOR, *LPPERFORMANCE_DESCRIPTOR;


