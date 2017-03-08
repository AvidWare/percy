// percy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "http.h"
#include "runner.h"

int main()
{
	percy::http server("http://localhost/api");
	percy::runner runner(server, "", "");
	runner.start();

    return 0;
}

