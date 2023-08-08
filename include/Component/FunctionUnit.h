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

private:
    std::shared_ptr<FunctionUnitStatus> functionUnitStatus;
    std::shared_ptr<PipelineRegister> IssueToReadRegister;
    std::shared_ptr<PipelineRegister> ReadToExeRegister;
    std::shared_ptr<PipelineRegister> ExeToWbRegister;
};

#endif //SCOREBOARD_UNIT_H
