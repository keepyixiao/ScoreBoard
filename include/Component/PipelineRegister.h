//
// Created by yixiao on 2023/8/8.
//

#ifndef SCOREBOARD_PIPELINEREGISTER_H
#define SCOREBOARD_PIPELINEREGISTER_H

#include <memory>

class Instruction;

class PipelineRegister {
public:
    void acceptInstruction(std::shared_ptr<Instruction> instruction);

    std::shared_ptr<Instruction> &getInstruction();

private:
    std::shared_ptr<Instruction> instruction;
};

#endif //SCOREBOARD_PIPELINEREGISTER_H
