/**
 * Author: Quentin Goss
 * Last Modified: 6/19/18 4:58pm
 */

#include <iostream>
#include <string>
#include "veins/modules/application/traci/ChangeRouteTest/ChangeRouteTest.h"

Define_Module(ChangeRouteTest);

void ChangeRouteTest::initialize(int n_stage) {
    BaseWaveApplLayer::initialize(n_stage);
    if (n_stage == 0) {
        // Test print
        EV << "Initializing... ChangeRouteTest!" << std::endl;
        st_last_drove_at = simTime();

        //test_simTime();
    }
}

void ChangeRouteTest::onWSM(WaveShortMessage* wsm){
    // TODO
}

void ChangeRouteTest::handleSelfMsg(cMessage* msg){
    // Some print statements so we can locate the function call.
    test_simTime();
    EV << "ChangeRouteTest is handling a self-message!\n";

    // If msg is a WSM, we will handle it.
    if (WaveShortMessage* wsm = dynamic_cast<WaveShortMessage*>(msg)){
        EV << "Handling our own msg.\n";

        //Who sent the message? Doesn't Work
        //int n_sender_address = msg->getSenderAddress();
        //int n_recipient_address = msg->getRecipientAddress();
        //EV << "Message sent by " << dynamic_cast<std::string>(n_sender_address) << " to " << dynamic_cast<std::string>(n_recipient_address) << "\n.";

    } else { // Otherwise we'll pass msg to our parent.
        EV << "Letting BaseWaveApplLayer handle the msg.\n";
        BaseWaveApplLayer::handleSelfMsg(msg);
    }
}

/**
 * @brief
 * A simple function to checks if:
 *  1. A function is called.
 *  2. A simTime variable is properly updated.
 */
void ChangeRouteTest::test_simTime() {
    EV << "--> OwO <-- Notice me! --> OwO <--\n";
    simtime_t st_before = st_last_drove_at;
    st_last_drove_at = simTime();
    EV << "st_last_drove_at changing from " << SIMTIME_STR(st_before) << " to " << SIMTIME_STR(st_last_drove_at) << ".\n";
}

