//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_LOADINST_H
#define SCOREBOARD_LOADINST_H

#include "Instruction/Instruction.h"

class LoadInst : public Instruction {
public:
    LoadInst(RegisterIdx dest, RegisterIdx sourceOne) : Instruction(dest, sourceOne) {
        this->operation = LOAD;
    }
};

#endif //SCOREBOARD_LOADINST_H
