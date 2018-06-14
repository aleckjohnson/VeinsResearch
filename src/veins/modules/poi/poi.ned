// Author: Quentin Goss
// Last Modified: June 14th, 2018 at 3:25pm
// Purpose: A point of interest.
//
// If there is a <?> next to a line/segment of code it means that I do not
//  understand the purpose of it yet, but the other similiar nodes
//  (Car.ned and RSU.ned) share these common parts.

package org.car2x.veins.modules.poi;

import org.car2x.veins.base.modules.BaseMobility;	// Mobility
import org.car2x.veins.base.modules.IBaseApplLayer; // <?> Application Layer
import org.car2x.veins.modules.nic.Nic80211p;		// <?> Network Interface Card

module POI
{
    parameters:
        string applType; // <?> Type of the application layer.
        string nicType = default("Nic80211p"); // <?> Network Interface Card
    gates:
        input veinsradioIn; // <?> gate for sendDirect
    submodules:
        // <?> Application Layer
        appl: <applType> like org.car2x.veins.base.modules.IBaseApplLayer {
            parameters:
                @display("p=45,44");
        }

        // <?> Network Interface Card
        nic: <nicType> like org.car2x.veins.modules.nic.INic80211p {
			parameters:
            	@display("p=45,179");
        }

        // BaseMobility gives POI an x,y and z position in the world.
        mobility: BaseMobility {
            parameters:
                @display("i=block/cogwheel;p=116,179");
        }
    connections:
        nic.upperLayerOut --> appl.lowerLayerIn;
        nic.upperLayerIn <-- appl.lowerLayerOut;
        
        nic.upperControlOut --> appl.lowerControlIn;
        nic.upperControlIn <-- appl.lowerControlOut;
        
        veinsradioIn --> nic.radioIn;
}

