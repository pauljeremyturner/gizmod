    #***
  #*********************************************************************
#*************************************************************************
#*** 
#*** GizmoDaemon Config Script
#*** 	Powermate Default config
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
import time

ENABLED = True
VERSION_NEEDED = 3.2
INTERESTED_CLASSES = [GizmoEventClass.Powermate]

############################
# PowermateDefault Class definition
##########################

class PowermateDefault(GizmoScriptDefault):
	"""
	Default Powermate Event Mapping
	"""
	
	############################
	# Public Functions
	##########################
			
	def onDeviceEvent(self, Event, Gizmo = None):
		"""
		Called from Base Class' onEvent method.
		See GizmodDispatcher.onEvent documention for an explanation of this function
		"""

	   	# Check for rotations
		if Event.Type == GizmoEventType.EV_REL:
			if not Gizmo.getKeyState(GizmoKey.BTN_0):
		   		if Gizmod.DefaultMixerVolume:
		   			Gizmod.DefaultMixerVolume.VolumePlayback = Gizmod.DefaultMixerVolume.VolumePlayback + Event.Value
			else:
				# scroll quickly (by pages using the page up / page down keys)
				if Event.Value < 0:
					for repeat in range(abs(Event.Value)):
						Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_LEFT, [GizmoKey.KEY_LEFTCTRL, GizmoKey.KEY_LEFTALT])
				else:
					for repeat in range(abs(Event.Value)):
						Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_RIGHT, [GizmoKey.KEY_LEFTCTRL, GizmoKey.KEY_LEFTALT])
			return True
		elif Event.Type == GizmoEventType.EV_KEY:
			if Event.Value == 0 and not Gizmo.Rotated:
				Gizmod.toggleMuteAllCards()
				return True
		return False
		
	############################
	# Private Functions
	##########################

	def __init__(self):
		""" 
		Default Constructor
		"""
		
		GizmoScriptDefault.__init__(self, ENABLED, VERSION_NEEDED, INTERESTED_CLASSES)

############################
# PowermateDefault class end
##########################

# register the user script
PowermateDefault()
