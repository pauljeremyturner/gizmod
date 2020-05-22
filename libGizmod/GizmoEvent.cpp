    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  GizmoEvent.cpp
*** \brief GizmoEvent class body
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

#include "GizmoEvent.hpp"
#include "../libH/Debug.hpp"
#include "../libH/Exception.hpp"
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;
using namespace H;
using namespace Gizmod;

////////////////////////////////////////////////////////////////////////////
// Type Defs
///////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Construction
///////////////////////////////////////

/**
 * \brief GizmoEvent Default Constructor
**/
GizmoEvent::GizmoEvent(GizmoEventClass Class, bool IsRemote) {
	mClass = Class;
	mIsRemote = IsRemote;
}

/**
 * \brief GizmoEvent Serialize Constructor
**/
GizmoEvent::GizmoEvent() {
	mClass = GIZMO_EVENTCLASS_STANDARD;
	mIsRemote = false;
}

/**
 * \brief GizmoEvent Destructor
**/
GizmoEvent::~GizmoEvent() {
}

////////////////////////////////////////////////////////////////////////////
// Class Body
///////////////////////////////////////

/**
 * \brief  Get the class of Gizmo
 * \return GizmoClass of the Gizmo
 * 
 * Note that this is also implemented in Python as a property so it can
 * be accessed as a variable by referencing ".GizmoClass"
**/
GizmoEventClass GizmoEvent::getClass() {
	return mClass;
}

/**
 * \brief  Get whether or not it's a remote event
 * \return True if the remote is from afar
 * 
 * Note that this is also implemented in Python as a property so it can
 * be accessed as a variable by referencing ".RemoteEvent"
**/
bool GizmoEvent::isRemote() {
	return mIsRemote;
}

/**
 * \brief  Set whether or not it's a remote event
 * \param  IsRemote True if the remote is from afar
**/
void GizmoEvent::setIsRemote(bool IsRemote) {
	mIsRemote = IsRemote;
}
