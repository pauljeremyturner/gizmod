    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  GizmoEventWindowFocus.hpp
*** \brief GizmoEventWindowFocus class header
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

#ifndef __GizmoEventWindowFocus_h
#define __GizmoEventWindowFocus_h

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "GizmoEvent.hpp"
#include "X11FocusWatcher.hpp"
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>

//////////////////////////////////////////////////////////////////////////////
// Namespace
///////////////////////////////////////

namespace Gizmod {

//////////////////////////////////////////////////////////////////////////////
// Typedef, enum's
///////////////////////////////////////
	
//////////////////////////////////////////////////////////////////////////////
// Class Definition
///////////////////////////////////////

/**
 * \class GizmoEventWindowFocus
 * \brief Class for WindowFocus events
 *
 * Raised when a Window Focus event is triggered
 *
 * Note that there is NO GUARANTEE that event orders are logical
 * For example, FOCUS_IN events might occur BEFORE a FOCUS_OUT
 * event, however, the events are true -- The current focus will
 * always be the last event with a FOCUS_IN type.
 *
 * This is due to the way X (and your WM's focus stealing prevention)
 * works (or perhaps doesn't work).
**/
class GizmoEventWindowFocus : public X11FocusEvent, public GizmoEvent {
public:
	// public functions
		
	// construction / deconstruction
	GizmoEventWindowFocus();					///< Serialize Constructor
	GizmoEventWindowFocus(X11FocusEvent const & Event, bool IsRemote = false); ///< Default Constructor
	virtual ~GizmoEventWindowFocus();				///< Destructor

protected:
	// private functions
	
	// private member variables
	
private: 
	// serialization
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<X11FocusEvent>(*this);
		ar & boost::serialization::base_object<GizmoEvent>(*this);
	}			
};

//////////////////////////////////////////////////////////////////////////////

} // Gizmod namespace

#endif // __GizmoEventWindowFocus_h
