//
// Created by thom on 5/27/24.
//

#ifndef NERVOUSSYSTEM_H
#define NERVOUSSYSTEM_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

namespace Arbie {
    namespace Brain {
        class NervousSystem {
        public:
            NervousSystem();
            ~NervousSystem();
        };
    } // Body
} // Arbie

#endif //NERVOUSSYSTEM_H
