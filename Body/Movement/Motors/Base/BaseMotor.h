//
// Created by thom on 8/28/24.
//

#ifndef BASEMOTOR_H
#define BASEMOTOR_H

#include <cstring>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>


namespace Arbie {
namespace Body {
namespace Movement {
namespace Motors {

class BaseMotor {

private:

    int s ;
    struct sockaddr_can canSocket;
    struct ifreq   ifr;
    struct can_frame canFrame;

public:


    BaseMotor() = default;

    int initiateControllerConnection();
    int sendControllerInstructions(int speedPercentage, int destination);
    int closeControllerConnection();

    ~BaseMotor() = default;
};

} // Motors
} // Movement
} // Body
} // Arbie

#endif //BASEMOTOR_H
