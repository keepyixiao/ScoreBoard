//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_SUBTRACTINST_H
#define SCOREBOARD_SUBTRACTINST_H

#include "Instruction/Instruction.h"

class SubtractInst : public Instruction {
    SubtractInst(RegisterIdx dest, RegisterIdx sourceOne, RegisterIdx sourceTwo) : Instruction(dest, sourceOne,
                                                                                               sourceTwo) {
        this->operation = SUBD;
    }

};

#endif //SCOREBOARD_SUBTRACTINST_H
