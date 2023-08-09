//
// Created by yixiao on 2023/8/7.
//
#include <iostream>

#include "Component/CPU.h"

void CPU::execute() {
    while (!terminated()) {
        executeIssue();
        executeRead();
        executeExecute();
        executeWrite();
    }
    std::cout << "total cycle is : " << totalCycle << '\n';
}

bool CPU::terminated() {
    if (InstructionVec.size() == 0 && onProcessingInstVec.size()) {
        return true;
    }
    return false;
}

void CPU::executeIssue() {

}

void CPU::executeRead() {

}

void CPU::executeExecute() {

}

void CPU::executeWrite() {
    for (auto &unit : unitVec) {
        if (unit->isBusy()) {
            if (unit->getInstruction()->getStage() == Stage::WriteResult) {
                if (!existWARDependence(unit)) {
                    unit->setBusy(false);
                    RegisterIdx dest = unit->getDestReg();
                    getRegisterStatus()->removeFunctionUnitFromRegisterResultMap(dest);
                }
            }
        }
    }
}

std::unique_ptr<InstructionParser> &CPU::getInstructionParser() {
    return instructionParser;
}

std::deque<std::shared_ptr<Instruction>> &CPU::getInstructionVec() {
    return InstructionVec;
}

std::unique_ptr<RegisterStatus> &CPU::getRegisterStatus() {
    return registerStatus;
}

void CPU::initCPU() {
    unitVec.push_back(AddUnit);
    unitVec.push_back(IntegerUnit);
    unitVec.push_back(DivUnit);
    unitVec.push_back(MulUnitOne);
    unitVec.push_back(MulUnitTwo);
}

bool CPU::existWARDependence(std::shared_ptr<FunctionUnit> &functionUnit) {
    for (auto &unit : unitVec) {
        if (unit != functionUnit) {
            if (unit->isBusy()) {
                if ((unit->getSourceOneReg() == functionUnit->getDestReg() && !unit->isSourceOneRead()) ||
                    (unit->getSourceTwoReg() == functionUnit->getDestReg() && !unit->isSourceTwoRead())) {
                    return true;
                }
            }
        }
    }
    return false;
}



