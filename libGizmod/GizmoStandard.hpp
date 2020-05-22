    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  GizmoStandard.hpp
*** \brief GizmoStandard class header
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

#ifndef __GizmoStandard_h
#define __GizmoStandard_h

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "Gizmo.hpp"
#include "GizmoLinuxInputDevice.hpp"
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
 * \class GizmoStandard
 * \brief Standard Gizmos
 *
 * This class contains all of the helper functions for making use of standard devices
**/
class GizmoStandard : public Gizmo, public GizmoLinuxInputDevice {
public:
	// public functions
	virtual std::string		getType();			///< Get the type of the Gizmo
	virtual bool			processEvent(GizmoEvent * pEvent); ///< Process an event
	
	// construction / deconstruction	
	GizmoStandard(); 						///< Serialize Constructor
	GizmoStandard(const H::DeviceInfo & deviceInfo, int DeviceID, int DeviceClassID); ///< Default Constructor
	virtual ~GizmoStandard();					///< Destructor

protected:
	// private functions
	
	// private member variables
	
private: 
	// serialization
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Gizmo>(*this);
		ar & boost::serialization::base_object<GizmoLinuxInputDevice>(*this);
	}	
};

//////////////////////////////////////////////////////////////////////////////

} // Gizmod namespace

#endif // __GizmoStandard_h
