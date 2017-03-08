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
}

percy::http::~http()
{
}


PERFORMANCE_DESCRIPTOR percy::http::connect(const APICALL &call) const
{
	CURL *curl;
	CURLcode res;
	string conn_url(this->base_url + call.url + "?"+call.param);
	PERFORMANCE_DESCRIPTOR response;
	struct curl_slist *header = NULL;

	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, conn_url.c_str());
		header = curl_slist_append(header, "Content-Length: 1");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
		curl_easy_setopt(curl, CURLOPT_POST, 1);
	}

	res = curl_easy_perform(curl);

	if (res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));

	printf("received response: %d", res);
	printf("host %s", conn_url.c_str());

	curl_slist_free_all(header); /* free the list again */
	curl_easy_cleanup(curl);

	return response;
}



