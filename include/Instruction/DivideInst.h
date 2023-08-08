//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_DIVIDEINST_H
#define SCOREBOARD_DIVIDEINST_H

#include "Instruction/Instruction.h"

class DivideInst : public Instruction {
public:
    DivideInst(RegisterIdx dest, RegisterIdx sourceOne, RegisterIdx sourceTwo) : Instruction(dest, sourceOne,
                                                                                             sourceTwo) {
        this->operation = MULD;
    }
};

#endif //SCOREBOARD_DIVIDEINST_H
