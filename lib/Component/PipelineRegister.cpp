//
// Created by yixiao on 2023/8/8.
//

#include "Component/PipelineRegister.h"

void PipelineRegister::acceptInstruction(std::shared_ptr<Instruction> instruction) {
    this->instruction = instruction;
}


std::shared_ptr<Instruction> &PipelineRegister::getInstruction() {
    return instruction;
}

