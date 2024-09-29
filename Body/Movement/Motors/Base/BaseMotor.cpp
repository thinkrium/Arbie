//
// Created by thom on 8/28/24.
//

#include "BaseMotor.h"

namespace Arbie {
namespace Body {
namespace Movement {
namespace Motors {

    BaseMotor::BaseMotor(int motor_id)
        : motorID(motor_id) {
    }

    int BaseMotor::initiate_controller_connection() {
        if((this->socketID = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
            return -1;
        }

        strcpy(this->ifr.ifr_name, "can0");
        ioctl(this->socketID, SIOCGIFINDEX, &ifr);

        this->canSocket.can_family = AF_CAN;
        this->canSocket.can_ifindex = ifr.ifr_ifindex;

        if (bind(this->socketID, (struct sockaddr *) &this->canSocket, sizeof(canSocket)) < 0) {
            return -1;
        }

        return 0;
    }

    int BaseMotor::send_controller_instructions(int speedPercentage, int destinationAngle, int rotationalDirection) {
        this->canFrame.can_id = this->get_motor_id();
        this->canFrame.can_dlc = 3;
        this->canFrame.data[0] = speedPercentage;
        this->canFrame.data[1] = destinationAngle;
        this->canFrame.data[2] = rotationalDirection;

        if(write(this->socketID, &this->canFrame, sizeof( this->canFrame)) != sizeof(  this->canFrame)) {

        }
        return 0;
    }

    int BaseMotor::close_controller_connection() {
        close(this->socketID);
        return 0;
    }


    int BaseMotor::get_motor_id()   {
        return this->motorID;
    }

    void BaseMotor::set_motor_id(int motor_id) {
        this->motorID = motor_id;
    }

    int BaseMotor::get_socket_id()   {
        return this->socketID;
    }

    void BaseMotor::set_socket_id(int socket_id) {
        this->socketID = socket_id;
    }

    struct sockaddr_can BaseMotor::get_can_socket()  {
        return this->canSocket;
    }

    void BaseMotor::set_can_socket(struct sockaddr_can can_socket) {
        this->canSocket = std::move(can_socket);
    }

    struct ifreq BaseMotor::get_ifr()  {
        return this->ifr;
    }

    void BaseMotor::set_ifr(struct ifreq ifr) {
        this->ifr = std::move(ifr);
    }

    struct can_frame BaseMotor::get_can_frame()  {
        return this->canFrame;
    }

    void BaseMotor::set_can_frame(struct can_frame can_frame) {
        this->canFrame = std::move(can_frame);
    }


} // Motors
} // Movement
} // Body
} // Arbie