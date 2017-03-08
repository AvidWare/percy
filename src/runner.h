/**
*    Project:
*
*    File:		runner.h
*
*    Purpose:
*
*    @author Isak Bosman
*    @version 1.0 03/06/2017
*/
#pragma once
#ifndef __percy__runner__
#define __percy__runner__

#include "stdafx.h"
#include "http.h"
#include "parser.h" 

	/*
	*  Class:		runner
	*
	*  Summary:
	*
	*  Functions:
	*				|-- Name
	*						Description
	*/
namespace percy {
	class runner
	{
	public:
		explicit runner(const http &server, const string &settings_path, const string &runner_file);
		virtual ~runner();
		void start() const;
	private:
		http _server;
		SETTINGS _settings;
		string _settings_file;
		string _runner_file;
	};
}
#endif
