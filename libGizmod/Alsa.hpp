    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  Alsa.hpp
*** \brief Alsa header
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

#ifndef __Alsa_h
#define __Alsa_h

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "AlsaEvent.hpp"
#include "AlsaSoundCard.hpp"
#include "AlsaMixer.hpp"
#include <string>
#include <vector>
#include <list>
#include <alsa/asoundlib.h>
#include <boost/shared_ptr.hpp>

//////////////////////////////////////////////////////////////////////////////
// Namespace
///////////////////////////////////////

/**
 * \namespace Gizmod
 * \brief     Gizmod namespace
 *
 * Gizmo Daemon Name Space
**/
namespace Gizmod {

//////////////////////////////////////////////////////////////////////////////
// Typedefs
///////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Alsa Class Definition
///////////////////////////////////////

/**
 * \class  Alsa
 * \brief  OO Interface to ALSA
 *
 * Note this creates 1 thread per sound card, and watches for mixer events
 * on all sound cards and all sound card elements when initted
**/
class Alsa : public AlsaInterface { friend class AlsaMixer;
public:	
	// public functions
	void				init();			///< Initialize Alsa
	AlsaMixer const *		getDefaultMixerSwitch();///< Get the system's default mixer for muting
	AlsaMixer const *		getDefaultMixerVolume();///< Get the system's default mixer for volume
	size_t				getNumSoundCards();	///< Get the number of sound cards attached
	AlsaSoundCard const *		getSoundCard(int Index);///< Get a sound card by index 
	void				toggleMuteAllCards();	///< Toggle mute on all sound cards
	virtual void			onAlsaEventMixerElementAttach(AlsaEvent const & Event, AlsaSoundCard const & SoundCard, AlsaMixer const & Mixer); ///< Triggered when a mixer element is discovered
	virtual void			onAlsaEventMixerElementChange(AlsaEvent const & Event, AlsaSoundCard const & SoundCard, AlsaMixer const & Mixer); ///< Triggered when a mixer element is discovered
	virtual void			onAlsaEventMixerElementDetach(AlsaEvent const & Event, AlsaSoundCard const & SoundCard, AlsaMixer const & Mixer); ///< Triggered when a mixer element is detached
	virtual void			onAlsaEventSoundCardAttach(AlsaEvent const & Event, AlsaSoundCard const & SoundCard); ///< Triggered when a new sound card is detected
	virtual void			onAlsaEventSoundCardDetach(AlsaEvent const & Event, AlsaSoundCard const & SoundCard); ///< Triggered when a sound card is removed
	void				registerDefaultMixerPriority(std::string MixerName); ///< Register a default mixer priority
	void				shutdown();		///< Shutdown the Alsa connection

	// construction / deconstruction
	Alsa();
	virtual ~Alsa();
	
	// public static functions

private:
	// private functions
	void				_onAlsaEventMixerElementChange(AlsaEvent const & Event, AlsaSoundCard const & SoundCard, AlsaMixer & Mixer); ///< Triggered when a mixer element is discovered -- for internal use
		
	// private member variables
	std::list<std::string>		mDefaultMixerPriorities;///< Default mixer priority list
	int				mDefaultMixerVolumePriority; ///< Current priority of the default volume mixer
	int				mDefaultMixerSwitchPriority; ///< Current priority of the default volume mixer
	AlsaMixer *			mpDefaultMixerSwitch;	///< Default switch mixer
	AlsaMixer *			mpDefaultMixerVolume;	///< Default volume mixer
	bool				mMuted;			///< Global mute is on or off
	std::vector< boost::shared_ptr<AlsaSoundCard> >	mSoundCards; ///< Vector of sound card control interface handles
};

//////////////////////////////////////////////////////////////////////////////

} // Gizmod namespace

#endif // __Alsa_h
