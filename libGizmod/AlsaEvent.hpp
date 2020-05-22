    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  AlsaEvent.hpp
*** \brief AlsaEventheader
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

#ifndef __AlsaEvent_h
#define __AlsaEvent_h

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <string>
#include <vector>
#include <alsa/asoundlib.h>
#include <boost/shared_ptr.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>

//////////////////////////////////////////////////////////////////////////////
// Namespace
///////////////////////////////////////

namespace Gizmod {

//////////////////////////////////////////////////////////////////////////////
// Typedefs
///////////////////////////////////////

/**
 * \enum   AlsaEventType
 * \brief  Type that indicates the type of AlsaEvent
**/
typedef enum {
	ALSAEVENT_ERROR,
	ALSAEVENT_SOUNDCARD_ATTACH,
	ALSAEVENT_SOUNDCARD_DETACH,
	ALSAEVENT_MIXERELEMENT_ATTACH,
	ALSAEVENT_MIXERELEMENT_CHANGE,
	ALSAEVENT_MIXERELEMENT_DETACH
} AlsaEventType;

//////////////////////////////////////////////////////////////////////////////
// AlsaEvent Class Definition
///////////////////////////////////////

/**
 * \class  AlsaEvent
 * \brief  Data structure that holds information about Alsa events
**/
class AlsaEvent {
public:	
	// public member variables
	AlsaEventType			Type;				///< The type of event
	unsigned int			Mask;				///< Alsa event mask
	
	// event variables
	bool				IsActiveChanged;		///< Has active changed
	bool				ElementsChanged;		///< Has Number of mixer elements changed
	bool				VolumePlaybackChanged;		///< Playback volume changed
	bool				VolumeCaptureChanged;		///< Capture volume changed
	bool				SwitchPlaybackChanged;		///< Playback switch changed
	bool				SwitchCaptureChanged;		///< Capture switch changed
		
	// public functions

	// construction / deconstruction
	AlsaEvent();
	AlsaEvent(AlsaEventType type, unsigned int mask = 0);
	AlsaEvent(AlsaEvent const & Event);
	virtual ~AlsaEvent();

private:
	// private functions
		
	// private member variables

private: 
	// serialization
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & Type;
		ar & Mask;
		ar & IsActiveChanged;
		ar & ElementsChanged;
		ar & VolumePlaybackChanged;
		ar & VolumeCaptureChanged;
		ar & SwitchPlaybackChanged;
		ar & SwitchCaptureChanged;			
	}			
};

//////////////////////////////////////////////////////////////////////////////

} // Gizmod namespace

#endif // __AlsaEvent_h
