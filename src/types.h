#pragma once
#include "stdafx.h"

using namespace std;

#define MAX_PARAM 10

typedef struct _APICALL {
   string url;
   DWORD delay;
   string param[MAX_PARAM];
   DWORD response_code;
   BOOL success;
   string error;
} APICALL, *PAPICALL, *LPAPICALL;


