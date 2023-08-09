//
// Created by yixiao on 2023/8/7.
//

#include  "Component/CPU.h"


int main(int argc, char **argv) {
    std::unique_ptr<CPU> executor = std::make_unique<CPU>();
    executor->getInstructionParser()->parseInstruction(executor->getInstructionVec(), argv[0]);
    executor->initCPU();
    executor->execute();
    return 0;
}

