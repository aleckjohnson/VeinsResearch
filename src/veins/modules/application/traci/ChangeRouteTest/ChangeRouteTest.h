/**
 * Author: Quentin Goss
 * Last Modified: 6/19/18 4:58pm
 */

#ifndef ChangeRouteTest_H
#define ChangeRouteTest_H

#include <string>
#include <list>
#include "veins/modules/application/ieee80211p/BaseWaveApplLayer.h"

/**
 * @brief
 * This is a test class for learning how to manipulate car node
 * movement.
 *
 * @author Quentin Goss
 */

class ChangeRouteTest : public BaseWaveApplLayer{
    public:
        virtual void initialize(int stage);
    protected:
        simtime_t lastDroveAt;
    protected:
        // Currently has no visible effect.
        //virtual void handlePositionUpdate(cObject* obj);
};

#endif
