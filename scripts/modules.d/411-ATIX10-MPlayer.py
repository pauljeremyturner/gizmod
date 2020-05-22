    #***
  #*********************************************************************
#*************************************************************************
#*** 
#*** GizmoDaemon Config Script
#*** 	ATIX10 MPlayer config
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
from GizmoScriptActiveApplication import *
import subprocess

ENABLED = True
VERSION_NEEDED = 3.2
INTERESTED_CLASSES = [GizmoEventClass.ATIX10]
INTERESTED_WINDOWS = ["mplayer"]

############################
# ATIX10MPlayer Class definition
##########################

class ATIX10MPlayer(GizmoScriptActiveApplication):
	"""
	MPlayer ATIX10 Event Mapping
	"""
	
	############################
	# Public Functions
	##########################
			
	def onDeviceEvent(self, Event, Gizmo = None):
		"""
		Called from Base Class' onEvent method.
		See GizmodDispatcher.onEvent documention for an explanation of this function
		"""

		# ensure only one event per button press		
		if Event.Value == 0:
			return False

		# process the key
	   	if Event.Code == GizmoKey.KEY_POWER:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_ESC)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_PAUSE:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_SPACE)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_PLAY:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_SPACE)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_STOP:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_SPACE)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_BOOKMARKS:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_V)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_EDIT:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_O)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_REWIND:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_PAGEDOWN)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_FORWARD:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_PAGEUP)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_COFFEE:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_Q)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_C:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_MINUS)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_D:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_EQUAL, [GizmoKey.KEY_RIGHTSHIFT])
	   		return True
	   	elif Event.Code == GizmoKey.KEY_E:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_E)
	   		return True
	   	elif Event.Code == GizmoKey.KEY_F:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_F)
	   		return True
		elif Event.Code == GizmoKey.KEY_VOLUMEUP:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_0)
			return True
		elif Event.Code == GizmoKey.KEY_VOLUMEDOWN:
			Gizmod.Keyboards[0].createEvent(GizmoEventType.EV_KEY, GizmoKey.KEY_9)
			return True		
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
		
		GizmoScriptActiveApplication.__init__(self, ENABLED, VERSION_NEEDED, INTERESTED_CLASSES, INTERESTED_WINDOWS)

############################
# ATIX10MPlayer class end
##########################

# register the user script
ATIX10MPlayer()
