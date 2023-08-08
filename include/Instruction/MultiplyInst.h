//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_MULTIPLYINST_H
#define SCOREBOARD_MULTIPLYINST_H

#include "Instruction/Instruction.h"

class MultiplyInst : public Instruction {
public:
    MultiplyInst(RegisterIdx dest, RegisterIdx sourceOne, RegisterIdx sourceTwo) : Instruction(dest, sourceOne,
                                                                                               sourceTwo) {
        this->operation = MULD;
    }
};

#endif //SCOREBOARD_MULTIPLYINST_H
