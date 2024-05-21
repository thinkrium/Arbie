//
// Created by thome on 12/1/2023.
//


#include "CoreTechs.h"

namespace Brain {

    Brain::CoreTechs::CoreTechs() {}

    CoreTechs::~CoreTechs() {
        this->joinProcess();
    }

    void CoreTechs::runProcess(Base_Process  &process) {

        this->processThread = thread( &Base_Process::Start, &process);


    }

    void CoreTechs::process() {


//        Brain::Senses::Console_Input consoleInput;
//        thread consoleInputThread = thread(&Base_Process::Start, std::ref(consoleInput));

#ifndef _WINDOWS

        Brain::Processes::Movement movement(consoleInput );


        movement.Start();
#endif
//        consoleInputThread.join();
    }

    void CoreTechs::joinProcess() {
//        this->processThread.joinable();
//        this->processThread.join();
    }

} // Brain