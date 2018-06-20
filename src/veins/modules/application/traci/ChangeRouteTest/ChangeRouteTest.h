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
        virtual void initialize(int n_stage);
        //Testing
        virtual void test_simTime();
    protected:
        simtime_t st_last_drove_at;
    protected:
        virtual void onWSM(WaveShortMessage* wsm);

        virtual void handleSelfMsg(cMessage* msg);
};

#endif
