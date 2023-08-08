//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_ADDINST_H
#define SCOREBOARD_ADDINST_H

#include "Instruction/Instruction.h"

class AddInst : public Instruction {
public:
    AddInst(RegisterIdx dest, RegisterIdx sourceOne, RegisterIdx sourceTwo) : Instruction(dest, sourceOne, sourceTwo) {
        this->operation = ADDD;
    }
};

#endif //SCOREBOARD_ADDINST_H
