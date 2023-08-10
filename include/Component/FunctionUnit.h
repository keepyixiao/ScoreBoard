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

    void setOperation(Operation operation);

    RegisterIdx getDestReg();

    RegisterIdx getSourceOneReg();

    RegisterIdx getSourceTwoReg();

    void setSourceOneReg(RegisterIdx sourceOneReg);

    void setSourceTwoReg(RegisterIdx sourceTwoReg);

    void setDestReg(RegisterIdx destReg);

    void setSourceOneUnit(std::shared_ptr<FunctionUnit> &sourceOneUnit);

    void setSourceTwoUnit(std::shared_ptr<FunctionUnit> &sourceTwoUnit);

    void setSourceOneReady(bool ready);

    void setSourceTwoReady(bool ready);

    std::shared_ptr<Instruction> &getInstruction();

    void acceptInstruction(std::shared_ptr<Instruction> instruction);

    void completedExecution();

    bool isSourceOneRead();

    bool isSourceTwoRead();


private:
    std::shared_ptr<FunctionUnitStatus> functionUnitStatus;
    std::shared_ptr<Instruction> instruction;
};

#endif //SCOREBOARD_UNIT_H
