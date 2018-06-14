// Author: Quentin Goss
// Last Modified: June 12th, 2018 at 1:37pm
// Purpose: A point of interest.

package org.car2x.veins.modules.poi;

import org.car2x.veins.base.modules.BaseMobility;

module POI {
    parameters:
        //
    gates:
        //
    submodules:
        mobility : BaseMobility {
            parameters:
                @display("i=block/cogwheel");
        }
}
        