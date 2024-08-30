//
// Created by thom on 8/28/24.
//

#include "BaseMotor.h"

namespace Arbie {
namespace Body {
namespace Movement {
namespace Motors {
    int BaseMotor::initiateControllerConnection() {
        if((this->s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
            return -1;
        }

        strcpy(ifr.ifr_name, "can0");
        ioctl(this->s, SIOCGIFINDEX, &ifr);

        this->canSocket.can_family = AF_CAN;
        this->canSocket.can_ifindex = ifr.ifr_ifindex;

        if (bind(this->s, (struct sockaddr *) &canSocket, sizeof(canSocket)) < 0) {
            return -1;
        }
    }

    int BaseMotor::sendControllerInstructions(int speedPercentage, int destination) {
        this->canFrame.can_id = 0x123;
        this->canFrame.can_dlc = 3;
        this->canFrame.data[0] = speedPercentage;
        this->canFrame.data[1] = destination;

    }

    int BaseMotor::closeControllerConnection() {
        close(this->s);
    }
} // Motors
} // Movement
} // Body
} // Arbie