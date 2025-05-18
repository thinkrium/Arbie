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
#include <utility>
#include <sys/ioctl.h>


namespace Arbie {
namespace Body {
namespace Movement {
namespace Motors {

class BaseMotor {

private:
    struct sockaddr_can canSocket;
    struct ifreq ifr;
    struct can_frame canFrame;

    int motorID;
    int socketID ;

public:
    int get_motor_id();
    void set_motor_id(int motor_id);
    int get_socket_id();

    void set_socket_id(int socket_id);

    BaseMotor(int motor_id);

    struct sockaddr_can get_can_socket();

    void set_can_socket(struct sockaddr_can can_socket);

    struct ifreq get_ifr();
    void set_ifr(struct ifreq ifr);
    struct can_frame get_can_frame();
    void set_can_frame(struct can_frame can_frame);
    BaseMotor() = default;


    int initiate_controller_connection();
    int send_controller_instructions(int speedPercentage, int destinationAngle, int rotationalDirection);
    int close_controller_connection();

    ~BaseMotor() = default;
};

} // Motors
} // Movement
} // Body
} // Arbie

#endif //BASEMOTOR_H
