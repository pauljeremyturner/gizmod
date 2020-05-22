    #***
  #*********************************************************************
#*************************************************************************
#*** 
#*** GizmoDaemon Config Script
#*** 	GizmodDispatcher.py
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
from GizmoDeviceClass import *
from GizmoRegistrar import *

############################
# GizmodDispatcher Class definition
##########################

class GizmodDispatcher(GizmodEventHandler):
	"""
	Main class that handles all of the incoming events
	
	The idea behind this class is to use it as nothing more than a dispatching
	mechanism.  All the events get channeled from GizmoDaemon through here
	and this class is intended merely to pass events off the appropriate
	module.
	"""
	
	############################
	# Public Functions
	##########################

	def getInitialized(self):
		""" Gets whether or not the object has been initialized """

		return self.initialized

	def initialize(self):
		"""
		This python function gets called by GizmoDeamon and is intended to allow for
		user specific initialization code to be executed during program startup.
		"""

		#print "GizmoDaemon Config Script v" + Gizmod.getVersion()  + " -- Initializing"
		self.initialized = True
		
	def onDeregisterDevice(self, Device):
		"""
		This method is triggered when a device has been deregistered (either at shutdown
		or when Gizmo Daemon detects a device has been disconnected from the computer)
		
		For information regarding the Device properties and methods see the API documention for
		Gizmo* (GizmoStandard, GizmoPowermate, etc)
		"""
		
		# GizmoRegistrar is defined in GizmoRegistrar.py for convenience and modularity sake
		GizmoRegistrar(Device).handleDeviceRemoval()

	def onEvent(self, Event, Gizmo = None):
		"""
		This method gets called whenever Gizmo Daemon detects an event from a device
		 
		The Event object passed in will be of the type associated with that event,
		so for example if it's a Powermate event the Event class will be "GizmoPowermate"
		
		Similarly the Gizmo object will of the class of the device that generated
		the event. Ie, if it's a Powermate event the class will also be "Powermate".  If
		there is no associated Gizmo (ie with WindowFocus events), this field will be
		set to None.
		
		All Event classes share the same base "GizmoEvent" class, and you can use the 
		GizmoEvent class method "getClass" to figure out what type of event it 
		is.  See the C++ API documention (http://gizmod.sourceforge.net/documentation/apidocs)
		on the specific GizmoEvent* type for more details

		All Gizmo classes share the same base "Gizmo" class, and you can use the Gizmo
		class method "getType" to figure out what type of event it is.  See the C++ API 
		documention on the specific Gizmo* type for more details
		"""
		
		# Pass on the event to the user scripts in order of their priority
		#
		# If a user script returns True (signalling that it has handled
		# an event, then it is not passed on to further scripts and the event
		# chain is stopped)
		for UserScript in self.userScripts:
			if UserScript.onEvent(Event, Gizmo):
				break
				
	def onQueryDeviceClass(self, DeviceInformation):
		"""
		This method is triggered when a new device is being registered (either at startup
		or when Gizmo Daemon detects a new device has been plugged in to the computer)
		
		For information regarding the DeviceInformation fields see the API documention for
		H::DeviceInfo
		
		This method should return the GizmoClass of the device
		"""
		
		# GizmoDeviceType is defined in GizmoDeviceType.py for convenience and modularity sake
		return GizmoDeviceClass(DeviceInformation).DeviceClass

	def onRegisterDevice(self, Device):
		"""
		This method is triggered when a new device (of the type returned in onQueryDeviceType) 
		has been registered (either at startup or when Gizmo Daemon detects a new device has 
		been plugged in to the computer)
		
		For information regarding the Device properties and methods see the API documention for
		Gizmo* (GizmoStandard, GizmoPowermate, etc)
		"""
		
		# GizmoRegistrar is defined in GizmoRegistrar.py for convenience and modularity sake
		GizmoRegistrar(Device).handleDeviceAddition()

	############################
	# Private Functions
	##########################
	
	def __init__(self):
		""" 
		Default Constructor
		"""

		# version check
		if not Gizmod.checkVersion(VERSION_REQUIRED, True):
			print "Script Version mismatch -- Gizmo Daemon v" + str(VERSION_REQUIRED) + " Required."
			Gizmod.signalShutdown()

		# Must explicitely call the base's constructor
		GizmodEventHandler.__init__(self)
		
		# Module specific initialization
		self.initialized = False
		self.userScripts = list()		# list of user scripts
		
		Gizmod.Keyboards = list()		# list of keyboards
		Gizmod.Mice = list()			# list of mice
		Gizmod.Powermates = list()		# list of Powermates
		Gizmod.ATIX10Remotes = list()		# list of ATI X10 Remotes

############################
# GizmodDispatcher class end
##########################

# To run user defined code post initializing, see User.py which is executed 
# after this file is parsed, and:
#
# - An interface to the main C++ program core is availabe via the 
#   object "Gizmod"
# - An instantiation of the GizmodDispatcher is available as "Dispatcher"
