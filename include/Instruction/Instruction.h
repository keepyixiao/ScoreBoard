//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_INSTRUCTION_H
#define SCOREBOARD_INSTRUCTION_H

#include "Util.h"

class Instruction {
private:
    RegisterIdx dest;
    RegisterIdx sourceOne, sourceTwo;
    Stage stage;

protected:
    Operation operation;

public:

    Instruction(RegisterIdx dest, RegisterIdx sourceOne, RegisterIdx sourceTwo);

    Instruction(RegisterIdx dest, RegisterIdx sourceOne);

    Stage getStage();

    void setStage(Stage stage);

    Operation getOperation();

    void setOperation(Operation operation);

    RegisterIdx getDest();

    void setDest(RegisterIdx dest);

    RegisterIdx getSourceOne();

    void setSourceOne(RegisterIdx sourceOne);

    RegisterIdx getSourceTwo();

    void setSourceTwo(RegisterIdx sourceTwo);

};

#endif //SCOREBOARD_INSTRUCTION_H
