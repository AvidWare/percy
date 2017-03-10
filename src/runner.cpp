#include "runner.h"

percy::runner::runner(const http & server, 
					  const string & settings_path, 
					  const string & runner_file) : 
					  _server(server), 
					  _settings_file(settings_path), 
					  _runner_file(runner_file){}

percy::runner::~runner()
{
}

void percy::runner::start() const
{
	APICALL call;
	call.method = "POST";
	call.url = "/users/login";
	call.parameters = "username=admin&password=password&deviceId=SLDKJ2390";
	PERFORMANCE_DESCRIPTOR result = this->_server.connect(call);

   printf("\n--------------------------------------------------\n");
   printf("Name Lookup: %.3f secs \n", result.name_lookup_time);
   printf("Connect Time: %.3f secs \n", result.connect_time);
   printf("Application Connect Time: %.3f secs \n", result.application_connect_time);
   printf("Pre Transfer Time: %.3f secs \n", result.pre_transfer_time);
   printf("Start Transfer Time: %.3f secs \n", result.start_transfer_time);
   printf("--------------------------------------------------\n");
   printf("Total Time: %.3f secs \n", result.total_time);
   printf("--------------------------------------------------\n");
   printf("Download Speed: %.3f Kbps \n", (result.download_speed / 125));
   printf("Upload Speed: %.3f Kbps \n", (result.download_speed / 125));
   printf("Content Length Header: %.3f \n", result.content_length);
   printf("Downloaded Bytes: %.3f Bytes \n", result.downloaded_bytes);
   printf("--------------------------------------------------\n");

}
