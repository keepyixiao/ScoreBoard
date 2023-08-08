//
// Created by yixiao on 2023/8/8.
//

#include "Component/PipelineRegister.h"

void PipelineRegister::acceptInstruction(Instruction *instruction) {
    this->instruction = instruction;
}

