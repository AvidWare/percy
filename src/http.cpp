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

percy::http::http(const std::string &base_url)
{
	this->base_url = base_url;

   /* In windows, this will init the winsock stuff */
   curl_global_init(CURL_GLOBAL_ALL);
}

percy::http::~http()
{
   curl_global_cleanup();
}

DWORD WINAPIV percy::http::ParseResponse(PCHAR ptr, UINT size, UINT nmemb, LPVOID userdata)
{
   return size * nmemb;
}


PERFORMANCE_DESCRIPTOR percy::http::connect(const APICALL &call) const
{
	CURL *curl;
	CURLcode res;
	string conn_url(this->base_url + call.url + "?" + call.parameters);
	PERFORMANCE_DESCRIPTOR response = {};
	struct curl_slist *header = NULL;

	curl = curl_easy_init();

	if (curl) {
		
	   curl_easy_setopt(curl, CURLOPT_URL, conn_url.c_str());
		header = curl_slist_append(header, "Content-Length: 0");
      header = curl_slist_append(header, "Accept: *");

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
		curl_easy_setopt(curl, CURLOPT_POST, 1);
      curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ParseResponse);
	}

	res = curl_easy_perform(curl);

   if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
      return response;
   }

   curl_easy_getinfo(curl, CURLINFO_NAMELOOKUP_TIME, &response.upload_speed);
   curl_easy_getinfo(curl, CURLINFO_APPCONNECT_TIME, &response.application_connect_time);
   curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &response.connect_time);
   curl_easy_getinfo(curl, CURLINFO_PRETRANSFER_TIME, &response.pre_transfer_time);
   curl_easy_getinfo(curl, CURLINFO_STARTTRANSFER_TIME, &response.start_transfer_time);
   curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &response.total_time);
   curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &response.content_length);
   curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &response.downloaded_bytes);
   curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &response.upload_speed);
   curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &response.download_speed);

	//printf("received response: %d", res);
	//printf("host %s", conn_url.c_str());

	curl_slist_free_all(header); /* free the list again */
	curl_easy_cleanup(curl);


	return response;
}



