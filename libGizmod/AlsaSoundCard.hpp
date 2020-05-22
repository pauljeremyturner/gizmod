    /**
  *********************************************************************
*************************************************************************
*** 
*** \file  AlsaSoundCard.hpp
*** \brief AlsaSoundCard header
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

#ifndef __AlsaSoundCard_h
#define __AlsaSoundCard_h

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "AlsaInterface.hpp"
#include "AlsaSoundCardInterface.hpp"
#include "AlsaMixer.hpp"
#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include <alsa/asoundlib.h>

//////////////////////////////////////////////////////////////////////////////
// Namespace
///////////////////////////////////////

namespace Gizmod {

//////////////////////////////////////////////////////////////////////////////
// AlsaSoundCard Class Definition
///////////////////////////////////////

/**
 * \class  AlsaSoundCard
 * \brief  Data structure that holds information about each Sound Card
**/
class AlsaSoundCard : public AlsaSoundCardInterface {
public:	
	// public member variables
	
	// public functions
	std::string			getCardHardwareID() const;	///< Get the card's hardware ID
	int				getCardID() const;		///< Get the card ID
	std::string			getCardName() const;		///< Get the name of the card
	std::string			getCardNameLong() const;	///< Get the long name of the card
	AlsaMixer const *		getMixer(std::string Name);	///< Get a mixer by name
	size_t				getNumMixers();			///< Get the number of mixers on the sound card
	void				setAllPlaybackSwitches(bool Enabled); ///< Set all playback switches to Enabled
	void				shutdown();			///< Shutdown the AlsaSoundCard connection

	// construction / deconstruction
	AlsaSoundCard(AlsaInterface * piAlsa, int CardID);
	virtual ~AlsaSoundCard();
	
	// public static functions
	static int 			MixerCallback(snd_mixer_t * Mixer, unsigned int EventMask, snd_mixer_elem_t * MixerElement); ///< Static mixer callback
	
private:
	// private functions
	void				init();				///< Initialize the AlsaSoundCard
	int 				mixerCallback(snd_mixer_t * Mixer, unsigned int EventMask, snd_mixer_elem_t * MixerElement); ///< Mixer callback
	void				threadProc();			///< The thread procedure loop
		
	// private member variables
	int				mCardID;			///< ID of the card
	std::string			mCardHWID;			///< Ascii HW ID of the card
	std::string			mCardName;			///< Name of the card
	std::string			mCardNameLong;			///< Long Name of the card
	snd_ctl_t *			mCTLHandle;			///< Alsa control interface handle
	snd_ctl_card_info_t * 		mHWInfo;			///< Alsa card hardware info
	snd_mixer_t *			mMixerHandle;			///< Mixer handle
	std::map< std::string, boost::shared_ptr<AlsaMixer> > mMixers;	///< Map of the mixers (by index)
	bool				mShutdown;			///< Shut down or not?
	bool				mWatching;			///< Keep watching mixers?

	/**
	 * Thread callback procedure struct
	**/
	struct AlsaSoundCardThreadProc {
		AlsaSoundCardThreadProc(AlsaSoundCard * pAlsaSoundCard) : mpAlsaSoundCard(pAlsaSoundCard) {
			mpAlsaSoundCard->mThreading = false;
		};
		
		/// Thread proc
		void operator()() {
			mpAlsaSoundCard->mThreading = true;
			mpAlsaSoundCard->threadProc();
			mpAlsaSoundCard->mThreading = false;
		}
		
		AlsaSoundCard * 	mpAlsaSoundCard;		///< The associated SoundCard
	};		
	bool				mThreading;			///< Variable to keep track if we're threading or not
	AlsaSoundCardThreadProc		mThreadProc;			///< The thread procedure instance	
	
private: 
	// serialization
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & mCardID;
		ar & mCardHWID;
		ar & mCardName;
		ar & mCardNameLong;
	}				
};

//////////////////////////////////////////////////////////////////////////////

} // Gizmod namespace

#endif // __AlsaSoundCard_h
