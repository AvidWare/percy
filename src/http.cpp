#include "stdafx.h"

/**
*    Project:	
*
*    File:		http.cpp
*
*    Purpose:	
*
*    @author Isak Bosman
*    @version 1.0 03/06/2017
*/
#include "http.h"

 percy::http::http()
{
    CURL *curl;
    CURLcode res;

    
    curl = curl_easy_init();
    if (curl)
       curl_easy_setopt(curl, CURLOPT_URL, "http://localhost");

    res = curl_easy_perform(curl);

   if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
         curl_easy_strerror(res));

   printf("received response: %d", res);

   curl_easy_cleanup(curl);
}

percy::http::~http()
{
}

