    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  GizmoUtils.hpp
*** \brief GizmoUtils class header
***
*****************************************
  *****************************************
    **/
  
/*
  
  Copyright (c) 2007, Tim Burrell
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at 

	http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and 
  limitations under the License. 
  
*/

#ifndef __GizmoUtils_h
#define __GizmoUtils_h

#if HAVE_CONFIG_H
#include "config.h"
#endif

//////////////////////////////////////////////////////////////////////////////
// Typedef, enum's
///////////////////////////////////////
	
//////////////////////////////////////////////////////////////////////////////
// Class Definition
///////////////////////////////////////

/**
 * \class GizmoUtils
 * \brief Helper functions for the Gizmos
**/
class GizmoUtils {
public:
	// static public functions
	static int				bitDifference(unsigned char ReferenceCode, unsigned char ActualCode); ///< Return how many bits difference in two bitstrings
	
	// construction / deconstruction 
	GizmoUtils();							///< Default Constructor
	virtual ~GizmoUtils();						///< Destructor
	
private:
	// private functions
};

#endif // __GizmoUtils_h
