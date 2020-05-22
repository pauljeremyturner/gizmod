    #***
  #*********************************************************************
#*************************************************************************
#*** 
#*** GizmoDaemon Config Script
#*** 	LIRCHauppauge Default config
#***
#*****************************************
  #*****************************************
    #***

"""

  Copyright (c) 2007, Gizmo Daemon Team
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at 

	http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and 
  limitations under the License. 
  
"""

############################
# Imports
##########################

from GizmoDaemon import *
from GizmoScriptDefault import *
from GizmoScriptAltTabber import *
import subprocess

ENABLED = True
VERSION_NEEDED = 3.2
INTERESTED_CLASSES = [GizmoEventClass.LIRC]
USES_LIRC_REMOTES = ["Hauppauge_350"]

############################
# LIRCHauppaugeDefault Class definition
##########################

class LIRCHauppaugeDefault(GizmoScriptDefault):
	"""
	Default LIRC Event Mapping for the Hauppauge remote
	"""
	
	############################
	# Public Functions
	##########################
			
	def onDeviceEvent(self, Event, Gizmo = None):
		"""
		Called from Base Class' onEvent method.
		See GizmodDispatcher.onEvent documention for an explanation of this function
		"""
		
		# if the event isn't from the remote we're interested in don't handle it
		if Event.Remote not in USES_LIRC_REMOTES:
			return False

		# process the key
	   	if   Event.Button == "Go":
	   		self.AltTabber.doAltTab()
	   		return True
	   	elif Event.Button == "Power":
	   		return False
	   	elif Event.Button == "TV":
	   		return False
	   	elif Event.Button == "Videos":
	   		return False
	   	elif Event.Button == "Music":
	   		return False
	   	elif Event.Button == "Pictures":
	   		subprocess.Popen(["xset", "dpms", "force", "off"])
	   		return True
	   	elif Event.Button == "Guide":
	   		return False
	   	elif Event.Button == "Up":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_UP)
	   		return True
	   	elif Event.Button == "Radio":
	   		return False
	   	elif Event.Button == "Left":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFT)
	   		return True
	   	elif Event.Button == "OK":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_ENTER)
	   		return True
	   	elif Event.Button == "Right":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_RIGHT)
	   		return True
	   	elif Event.Button == "Back/Exit":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_ESC)
	   		return True
	   	elif Event.Button == "Down":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_DOWN)
	   		return True
	   	elif Event.Button == "Menu/i":
	   		return False
	   	elif Event.Button == "Vol+":
	   		if Gizmod.DefaultMixerVolume:
	   			Gizmod.DefaultMixerVolume.VolumePlaybackPercent = Gizmod.DefaultMixerVolume.VolumePlaybackPercent + 2.5
	   		return True
	   	elif Event.Button == "Vol-":
	   		if Gizmod.DefaultMixerVolume:
	   			Gizmod.DefaultMixerVolume.VolumePlaybackPercent = Gizmod.DefaultMixerVolume.VolumePlaybackPercent - 2.5
	   		return True
	   	elif Event.Button == "Prev.Ch":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_BACKSPACE)
	   		return True
	   	elif Event.Button == "Mute":
   			Gizmod.toggleMuteAllCards()
	   		return True
	   	elif Event.Button == "Ch+":
	   		return False
	   	elif Event.Button == "Ch-":
	   		return False
	   	elif Event.Button == "Record":
	   		return False
	   	elif Event.Button == "Stop":
	   		return False
	   	elif Event.Button == "Rewind":
	   		return False
	   	elif Event.Button == "Play":
	   		return False
	   	elif Event.Button == "Forward":
	   		return False
	   	elif Event.Button == "Replay/SkipBackward":
	   		return False
	   	elif Event.Button == "Pause":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_P)
	   		return True
	   	elif Event.Button == "SkipForward":
	   		return False
	   	elif Event.Button == "1":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_1)
	   		return True
	   	elif Event.Button == "2":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_2)
	   		return True
	   	elif Event.Button == "3":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_3)
	   		return True
	   	elif Event.Button == "4":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_4)
	   		return True
	   	elif Event.Button == "5":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_5)
	   		return True
	   	elif Event.Button == "6":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_6)
	   		return True
	   	elif Event.Button == "7":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_7)
	   		return True
	   	elif Event.Button == "8":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_8)
	   		return True
	   	elif Event.Button == "9":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_9)
	   		return True
	   	elif Event.Button == "Asterix":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_F12, [GizmoKey.KEY_LEFTMETA])
	   		return True
	   	elif Event.Button == "0":
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_0)
	   		return True
	   	elif Event.Button == "#":
	   		return False
	   	elif Event.Button == "Red":
	   		return False
	   	elif Event.Button == "Green":
	   		return False
	   	elif Event.Button == "Yellow":
	   		return False
	   	elif Event.Button == "Blue":
	   		return False
	   	else:
	   		# unmatched event, keep processing
			return False				
	
	############################
	# Private Functions
	##########################

	def __init__(self):
		""" 
		Default Constructor
		"""
		
		GizmoScriptDefault.__init__(self, ENABLED, VERSION_NEEDED, INTERESTED_CLASSES)
		self.AltTabber = GizmoScriptAltTabber()

############################
# LIRCHauppaugeDefault class end
##########################

# register the user script
LIRCHauppaugeDefault()
