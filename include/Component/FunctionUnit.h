//
// Created by yixiao on 2023/8/8.
//

#ifndef SCOREBOARD_UNIT_H
#define SCOREBOARD_UNIT_H

#include <memory>
#include "FunctionUnitStatus.h"
#include "Instruction/Instruction.h"
#include "PipelineRegister.h"

class FunctionUnit {
public:
    bool isBusy();

    void setBusy(bool busy);

    RegisterIdx getDestReg();

    RegisterIdx getSourceOneReg();

    RegisterIdx getSourceTwoReg();

    std::shared_ptr<Instruction> &getInstruction();

    void acceptInstruction(std::shared_ptr<Instruction> instruction);

    bool isSourceOneRead();

    bool isSourceTwoRead();


private:
    std::shared_ptr<FunctionUnitStatus> functionUnitStatus;
    std::shared_ptr<Instruction> instruction;
};

#endif //SCOREBOARD_UNIT_H
