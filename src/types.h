#pragma once
#include "stdafx.h"

using namespace std;

#define MAX_PARAM 10

typedef struct _JSON_{} JSON, *PJSON, *LPJSON;

typedef struct _APICALL : JSON {
   string   url;              // The url of the request
   DWORD    delay;            // The time delay override
   string   parameters;       // The uri parameters - decoded
   DWORD    response_code;    // The http response code
   string   formbody;         // The POST form body
   BOOL     success;          // Whether the call succeeded
   string   error;            // The specific error message
   string   method;           // The http method GET, POST, PUT, DELETE...
} APICALL, *PAPICALL, *LPAPICALL;

typedef struct _SETTINGS : JSON {
  
} SETTINGS, *PSETTINGS, *LPSETTINGS;

typedef struct _PERFORMANCE_DESCRIPTOR : JSON {
   double name_lookup_time;            // Time until name resolution
   double connect_time;                // Connection time to host
   double application_connect_time;    // Time until handshake was completed
   double pre_transfer_time;           // The time it took from start until the file transfer begins
   double start_transfer_time;         // Time until first byte is received
   double total_time;                  // Total time of request until response is fully received
   double download_speed;              // The speed of the download in bytes per second
   double upload_speed;                // The upload speed in bytes per second
   double content_length;              // The value of the Content-Length response header value
   double downloaded_bytes;            // The total amount of bytes downloaded
} PERFORMANCE_DESCRIPTOR, *PPERFORMANCE_DESCRIPTOR, *LPPERFORMANCE_DESCRIPTOR;


