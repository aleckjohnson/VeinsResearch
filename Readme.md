# Notes
[Veins](#veins),[Reducing the Number of Vehicles](#reduce_veh)

## <a name="veins"></a>Veins
The directory for veins is:
```
~/src/veins/
```

----

## <a name="reduce_veh"></a>Reducing the Number of Vehicles

By default, the simulation runs with 194 vehicles. The amount of vehicles can be modifed by editing erlangen.rou.xml:
```
~/src/veins/examples/veins/erlangen.rou.xml
```

*<!> NOTE: There are two erlangen.rou.xml. The proper one to edit is the above. The incorrect one below is an auto-generated output file. <!>*
```
~/src/veins/src/examples/veins/erlangen.rou.xml
```

To change the number of vehicles we change the value at number="":
```
<flow . . . number="195"/>
```

----

## Msg files

The directory for message files in veins is:
```
~/src/veins/src/veins/base/messages/
```

OMnet++ automatically generages the .cc and .h files for msg files. The usefull information will always be found in the .msg files.

----

## TraCI

TraCI handles the communication within/between nodes. The directory for the TraCI folder is:
```
~/src/veins/src/modules/application/traci/
```

A template for TraCI source files is found in the traci folder named:

```
MyVeinsApp.cc
MyVeinsApp.h
MyVeinsApp.ned
```

----

## NED files

### RSUExampleScenario.ned
```
~/src/veins/examples/veins/RSUExampleScenario.ned
```
This appears to be the .ned file for the veins example.

It imports:
```
RSU.ned
Scenario.ned
```

This .ned creates one submodule:
```
RSU[1]
```
----

### RSU.ned
```
~/src/veins/src/veins/nodes/RSU.ned
```

This .ned appears to handle communication between the Network Interface Card (NIC) and the application layer. 

Part of package:
```
nodes
```

It imports:
```
~/src/veins/src/veins/base/modules
	BaseLayer.ned
	BaseMacLayer.ned
	BaseMobility.ned
	BaseWorldUtility.ned
	IBaseApplLayer.ned
	IMobility.ned
	IWirelessMac.ned
Nic80211p.ned
```

Creates three (3) submodules:
```
appl - ??? application layer 
nic - ??? a type of network interface card
mobility - BaseMobility
```
	
Has the following connections:
```
nic.upperLayer <--> appl.lowerLayer
nic.upperContro <--> appl.lowerControl
veinsradioIn --> nic.radioIn
```	

----

### Scenario.ned
```
~/src/veins/src/veins/nodes/Scenario.ned
```

This .ned handles the visual objects in the world and also acts as a manager for the TraCIScenario.

Part of package:
```
nodes
```

It imports:
```
ConnectionManager.ned
BaseWorldUtility.ned
TracCIScenarioManagerLanchd.ned
ObstacleControl.ned
AnnotationManager.ned
```	

Creates five (5) submodules:
```
obstacles
annotations
connectionManager
world - parameters for playgroundSize X,Y,Z
manager
```	

Has no connections.

----

### Car.ned
```
~/src/veins/src/veins/nodes/Car.ned
```

This .ned are the car nodes. The car nodes appear to be similiar to the RSU in that their connections are similiar and except for the mobility submodule is <veinsmobilityType> instead of BaseMobility.

Part of package:
```
nodes
```

It imports:
```
~/src/veins/src/veins/base/modules
	BaseLayer.ned
	BaseMacLayer.ned
	BaseMobility.ned
	BaseWorldUtility.ned
	IBaseApplLayer.ned
	IMobility.ned
	IWirelessMac.ned
Nic80211p.ned
```

Creates three (3) submodules:
```
appl - ??? application layer 
nic - ??? a type of network interface card
mobility - BaseMobility
```	

Has the following connections:
```
nic.upperLayer <--> appl.lowerLayer
nic.upperContro <--> appl.lowerControl
veinsradioIn --> nic.radioIn
```

----

### Nic80211p.ned
```
~/src/veins/src/veins/modules/nic/Nic80211p.ned
```

*TODO...*
