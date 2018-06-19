/**
 * Author: Quentin Goss
 * Last Modified: 6/19/18 4:58pm
 */

#include <iostream>
#include "veins/modules/application/traci/ChangeRouteTest/ChangeRouteTest.h"

Define_Module(ChangeRouteTest);

void ChangeRouteTest::initialize(int stage) {
    BaseWaveApplLayer::initialize(stage);
    if (stage == 0) {
        // Test print
        EV << "Initializing... ChangeRouteTest!" << std::endl;

        lastDroveAt = simTime();
    }
}

// Currently has no visible effect.
/**
void ChangeRouteTest::handlePositionUpdate(cObject* obj) {
    BaseWaveApplLayer::handlePositionUpdate(obj);

    simtime_t before = lastDroveAt;
    lastDroveAt = simTime();
    EV << "Var: lastDroveAt changing from " << SIMTIME_STR(before) << "to " << SIMTIME_STR(lastDroveAt) << ".\n";
}
*/
