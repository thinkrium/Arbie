//
// Created by thome on 12/1/2023.
//

#ifndef ARBIE_CORETECHS_H
#define ARBIE_CORETECHS_H

#include "../Processes/Movement/Movement.h"
#include "../Processes/Base/Base_Process.h"

using namespace Brain::Processes;

namespace Brain {

    class CoreTechs {

    private:

    public:

        CoreTechs();

        void process();

        void runProcess(  Base_Process &process  );

        virtual ~CoreTechs();

    };

} // Brain

#endif //ARBIE_CORETECHS_H
