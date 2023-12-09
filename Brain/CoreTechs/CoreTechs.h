//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_CORETECHS_H
#define ARBIE_CORETECHS_H

#include "../Senses/Console_Input/Console_Input.h"
#include "../Processes/Movement/Movement.h"
#include "../Processes/Base/Base_Process.h"
#include "thread"

using namespace std;
using namespace Brain::Processes;
using namespace Brain::Senses;

namespace Brain {

    class CoreTechs {

    private:

        thread processThread;

    public:

        CoreTechs();

        void process();

        void runProcess(  Base_Process &process  );

        void joinProcess();

        virtual ~CoreTechs();

    };

} // Brain

#endif //ARBIE_CORETECHS_H
