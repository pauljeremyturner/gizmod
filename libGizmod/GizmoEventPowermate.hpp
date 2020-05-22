    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  GizmoEventPowermate.hpp
*** \brief GizmoEventPowermate class header
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

#ifndef __GizmoEventPowermate_h
#define __GizmoEventPowermate_h

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "GizmoEvent.hpp"
#include "GizmoLinuxInputEvent.hpp"
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
 * \class GizmoEventPowermate
 * \brief Class for Powermate events
 *
 * This class is for all GizmoEventPowermates attached to the system.
**/
class GizmoEventPowermate : public GizmoEvent, public GizmoLinuxInputEvent {
public:
	// public member variabled
	float				ClickTime;			///< Length of button press in seconds
	
	// public functions
	
	// static public functions
	static void			buildEventsVectorFromBuffer(std::vector< boost::shared_ptr<GizmoEventPowermate> > & EventVector, H::DynamicBuffer<char> const & Buffer, bool SendNullEvents); ///< Build an event list from a read buffer
	
	// construction / deconstruction
	GizmoEventPowermate();						///< Default Constructor
	GizmoEventPowermate(struct input_event const & InputEvent, bool IsRemote = false); ///< Default Constructor
	virtual ~GizmoEventPowermate();					///< Destructor

protected:
	// private functions
	
	// private member variables
	
	// static private functions
	static void 			buildEventsVectorFromBufferFunctor(struct input_event & InputEvent, std::vector< boost::shared_ptr<GizmoEventPowermate> > * pEventVector, bool SendNullEvents); ///< Functor for building the events list

private: 
	// serialization
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<GizmoEvent>(*this);
		ar & boost::serialization::base_object<GizmoLinuxInputEvent>(*this);
		ar & ClickTime;
	}			
};

//////////////////////////////////////////////////////////////////////////////

} // Gizmod namespace

#endif // __GizmoEventPowermate_h
