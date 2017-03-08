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
	call.param = "username=admin&password=password&deviceId=SLDKJ2390";
	this->_server.connect(call);
}
