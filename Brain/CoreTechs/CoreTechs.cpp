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

        Movement   movement;
        movement.Start();

        Console_Input consoleInput;
//        consoleInput.Start();
        thread cI = thread(&Base_Process::Start, consoleInput);
        cI.join();
    }

    void CoreTechs::joinProcess() {
//        this->processThread.joinable();
//        this->processThread.join();
    }

} // Brain