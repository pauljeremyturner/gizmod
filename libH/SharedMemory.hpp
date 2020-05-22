    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  SharedMemory.hpp
*** \brief SharedMemory header
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

#ifndef __SharedMemory_h
#define __SharedMemory_h

#if HAVE_CONFIG_H
#include "config.h"
#endif

//////////////////////////////////////////////////////////////////////////////
// Namespace
///////////////////////////////////////

namespace H {

//////////////////////////////////////////////////////////////////////////////
// Helper Macros
///////////////////////////////////////

/** 
 * \def   makeSharedPointer
 * Helper macro to define a new shared_ptr
**/
#define makeSharedPointer(X)	typedef shared_ptr<X> X##Ptr

/** 
 * \def   newSharedPtr
 * Helper macro to instantiate a new managed pointer
**/
#define newSharedPtr(x, y)	x##Ptr y = x##Ptr(new x)

//////////////////////////////////////////////////////////////////////////////

}

#endif // __SharedMemory_h
