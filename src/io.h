
/**
*    Project:	
*
*    File:		io.h
*
*    Purpose:	
*
*    @author Isak Bosman
*    @version 1.0 03/06/2017
*/

#pragma once
#ifndef __percy_io__
#define __percy_io__

#include "stdafx.h"
#include "dirent.h"

/*
*  Class:		io
*
*  Summary:		
*
*  Functions:
*				|-- Name
*						Description
*/
namespace percy
{
   class io
   {
   public:
      /*
		*  Function:	Default destructor
		*
		*  Summary:		Self explanatory
		*
		*	Arguments:	None
		*/
      static std::string ReadLine(const std::string &path_to_file);
   };
}

#endif
