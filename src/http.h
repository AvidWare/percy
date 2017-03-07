
/**
*    Project:	
*
*    File:		http.h
*
*    Purpose:	
*
*    @author Isak Bosman
*    @version 1.0 03/06/2017
*/

#pragma once
#ifndef __percy__http__
#define __percy__http__

#include "stdafx.h"

/*
*  Class:		http
*
*  Summary:		
*
*  Functions:
*				|-- Name
*						Description
*/
namespace percy
{
   class http
   {
   public:
      /*
		*  Function:	Default constructor
		*
		*  Summary:		Self explanatory
		*
		*	Arguments:	None
		*/
      explicit http();

      /*
		*  Function:	Default destructor
		*
		*  Summary:		Self explanatory
		*
		*	Arguments:	None
		*/
      virtual ~http();

   private:
      std::string base_url;
      
   };
}

#endif
