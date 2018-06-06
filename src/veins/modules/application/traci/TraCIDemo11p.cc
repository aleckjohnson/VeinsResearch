//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
#include <iostream>
#include <stdlib.h>     /* rand */
#include <thread>
#include <chrono>
#include "veins/modules/application/traci/TraCIDemo11p.h"

Define_Module(TraCIDemo11p);


void TraCIDemo11p::initialize(int stage) {
    BaseWaveApplLayer::initialize(stage);
    if (stage == 0) {
        sentMessage = false;
        lastDroveAt = simTime();
        currentSubscribedServiceId = -1;
        longitcoord = 0;
        Coord latCoord;
        testVar = 0;
        nodeVar = 0;
        simTimer = 50;
        baseTime;
        nodeHold = "";
        prevRoute;
        Coord currentPosition;

        //set destination Coordinates here
        latCoord = Coord(49.578099,11.022388);

        //new route set in doubly linked list below.
        routeNode.push_back("9643180");

    }
}

void TraCIDemo11p::funcCaller(){
    for(;;)
              {
               baseTime = simTime();
               if(baseTime >= simTimer){
                 moveToCoord();
               }
               std::this_thread::sleep_for(std::chrono::seconds(1));
              }
}

void TraCIDemo11p::onWSA(WaveServiceAdvertisment* wsa) {
    if (currentSubscribedServiceId == -1) {
        mac->changeServiceChannel(wsa->getTargetChannel());
        currentSubscribedServiceId = wsa->getPsid();
        if  (currentOfferedServiceId != wsa->getPsid()) {
            stopService();
            startService((Channels::ChannelNumber) wsa->getTargetChannel(), wsa->getPsid(), "Mirrored Traffic Service");
        }
    }
}

void TraCIDemo11p::onWSM(WaveShortMessage* wsm) {
    findHost()->getDisplayString().updateWith("r=16,green");

    if (mobility->getRoadId()[0] != ':') traciVehicle->changeRoute(wsm->getWsmData(), 9999);
    if (!sentMessage) {
        sentMessage = true;
        //repeat the received traffic update once in 2 seconds plus some random delay
        wsm->setSenderAddress(myId);
        wsm->setSerial(3);
        scheduleAt(simTime() + 2 + uniform(0.01,0.2), wsm->dup());
    }
}

void TraCIDemo11p::handleSelfMsg(cMessage* msg) {
    if (WaveShortMessage* wsm = dynamic_cast<WaveShortMessage*>(msg)) {
        //send this message on the service channel until the counter is 3 or higher.
        //this code only runs when channel switching is enabled
        sendDown(wsm->dup());
        wsm->setSerial(wsm->getSerial() +1);
        if (wsm->getSerial() >= 3) {
            //stop service advertisements
            stopService();
            delete(wsm);
        }
        else {
            scheduleAt(simTime()+1, wsm);
        }
    }
    else {
        BaseWaveApplLayer::handleSelfMsg(msg);
    }
}

void TraCIDemo11p::handlePositionUpdate(cObject* obj) {
    BaseWaveApplLayer::handlePositionUpdate(obj);

    // stopped for for at least 10s?
    if (mobility->getSpeed() < 1) {
        if (simTime() - lastDroveAt >= 10 && sentMessage == false) {
            findHost()->getDisplayString().updateWith("r=16,red");
            sentMessage = true;

            WaveShortMessage* wsm = new WaveShortMessage();
            populateWSM(wsm);
            wsm->setWsmData(mobility->getRoadId().c_str());

            //host is standing still due to crash
            if (dataOnSch) {
                startService(Channels::SCH2, 42, "Traffic Information Service");
                //started service and server advertising, schedule message to self to send later
                scheduleAt(computeAsynchronousSendingTime(1,type_SCH),wsm);
            }
            else {
                //send right away on CCH, because channel switching is disabled
                sendDown(wsm);
            }
        }
    }
    else {
        lastDroveAt = simTime();
    }
}

void TraCIDemo11p::determineVar(){
    //random number generator to create test case. goes from 1 to 10.
    testVar = rand() % 10 + 1;

}

void TraCIDemo11p::determineNode(){
    //random number generator to choose node. goes from 1 to 25. (have to confirm veh IDs)
    nodeVar = rand() % 25 + 1;
    nodeHold = std::to_string(nodeVar);
}

void TraCIDemo11p::moveToCoord(){

    //scheduleAt(simTime() + 1, moveToCoord()); //scheduling action to run again in 1 second
//in order to move forward with how we properly want to do this we need to determine how nodes are selected for task (for now will also be random?)
    determineNode();
    //put route change command here
    //simTimer = simTime(); //function to access the omnet simulation time counter
    //std::cout << simTimer << endl;
    //traciVehicle->nodeId="19";//this example spaces nodes by 6 apart on ID
    //get old route information and store before setting new route
    prevRoute = traciVehicle->getPlannedRoadIds();
    traciVehicle->setNodeID("19");
    traciVehicle->changeVehicleRoute(routeNode);//change the parameters to include coord that you want
    }

void TraCIDemo11p::confirmArrival(){
    //get current coordinates and compare them to our set point
    currentPosition = mobility->getCurrentPosition();
    //set destination (goal) coordinates up at initialization stage in latCoord variable
    if (currentPosition == latCoord){
        determineVar();//determining environmental variables externally
        std::cout<<"The Temperature is "<< testVar<< endl;
    }
    //reroute back to original route.
    traciVehicle->changeVehicleRoute(prevRoute);
}



