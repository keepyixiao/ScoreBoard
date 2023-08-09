//
// Created by yixiao on 2023/8/8.
//

#include "Component/FunctionUnit.h"

bool FunctionUnit::isBusy() {
    return functionUnitStatus->isBusy();
}

void FunctionUnit::setBusy(bool busy) {
    functionUnitStatus->setBusy(busy);
}

RegisterIdx FunctionUnit::getDestReg() {
    return functionUnitStatus->getDestReg();
}

RegisterIdx FunctionUnit::getSourceOneReg() {
    return functionUnitStatus->getSourceOneReg();
}

RegisterIdx FunctionUnit::getSourceTwoReg() {
    return functionUnitStatus->getSourceTwoReg();
}

std::shared_ptr<Instruction> &FunctionUnit::getInstruction() {
    return instruction;
}

void FunctionUnit::acceptInstruction(std::shared_ptr<Instruction> instruction) {
    this->instruction = instruction;
}

bool FunctionUnit::isSourceOneRead() {
    return !functionUnitStatus->getSourceOneReady();
}

bool FunctionUnit::isSourceTwoRead() {
    return !functionUnitStatus->getSourceTwoReady();
}



