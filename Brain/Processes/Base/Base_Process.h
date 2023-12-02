//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_BASE_PROCESS_H
#define ARBIE_BASE_PROCESS_H

namespace Brain {
    namespace Processes {

        class Base_Process {
        public:
            Base_Process();

            virtual void Start() = 0;
            virtual ~Base_Process();
        };

    } // Brain
} // Processes

#endif //ARBIE_BASE_PROCESS_H
