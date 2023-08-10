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

void FunctionUnit::setOperation(Operation operation) {
    functionUnitStatus->setOperation(operation);
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

void FunctionUnit::setSourceOneReg(RegisterIdx sourceOneReg) {
    functionUnitStatus->setSourceOneReg(sourceOneReg);
}

void FunctionUnit::setSourceTwoReg(RegisterIdx sourceTwoReg) {
    functionUnitStatus->setSourceTwoReg(sourceTwoReg);
}

void FunctionUnit::setDestReg(RegisterIdx destReg) {
    functionUnitStatus->setDestReg(destReg);
}

std::shared_ptr<Instruction> &FunctionUnit::getInstruction() {
    return instruction;
}

void FunctionUnit::acceptInstruction(std::shared_ptr<Instruction> instruction) {
    this->instruction = instruction;
}

void FunctionUnit::completedExecution() {
    instruction.reset();
}

bool FunctionUnit::isSourceOneRead() {
    return !functionUnitStatus->getSourceOneReady();
}

bool FunctionUnit::isSourceTwoRead() {
    return !functionUnitStatus->getSourceTwoReady();
}

void FunctionUnit::setSourceOneUnit(std::shared_ptr<FunctionUnit> &sourceOneUnit) {
    functionUnitStatus->setSourceOneUnit(sourceOneUnit);
}

void FunctionUnit::setSourceTwoUnit(std::shared_ptr<FunctionUnit> &sourceTwoUnit) {
    functionUnitStatus->setSourceTwoUnit(sourceTwoUnit);
}

void FunctionUnit::setSourceOneReady(bool ready) {
    functionUnitStatus->setSourceOneReady(ready);
}

void FunctionUnit::setSourceTwoReady(bool ready) {
    functionUnitStatus->setSourceTwoReady(ready);
}



