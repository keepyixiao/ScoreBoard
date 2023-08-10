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
    auto &instruction = InstructionVec.front();
    if (instruction->getOperation() == Operation::ADDD ||
        instruction->getOperation() == Operation::SUBD) {
        if (!AddUnit->isBusy() && !existWAWDependence(instruction->getDest())) {
            issueInstruction(AddUnit, instruction);
            InstructionVec.pop_front();
            onProcessingInstVec.push_back(instruction);
        }
    } else if (instruction->getOperation() == Operation::MULD) {
        if (!MulUnitOne->isBusy() && !existWAWDependence(instruction->getDest())) {
            issueInstruction(MulUnitOne, instruction);
            InstructionVec.pop_front();
            onProcessingInstVec.push_back(instruction);
        } else if (!MulUnitTwo->isBusy() && !existWAWDependence(instruction->getDest())) {
            issueInstruction(MulUnitTwo, instruction);
            InstructionVec.pop_front();
            onProcessingInstVec.push_back(instruction);
        }
    } else if (instruction->getOperation() == Operation::LOAD) {
        if (!IntegerUnit->isBusy() && !existWAWDependence(instruction->getDest())) {
            issueInstruction(IntegerUnit, instruction);
            InstructionVec.pop_front();
            onProcessingInstVec.push_back(instruction);
        }
    } else if (instruction->getOperation() == Operation::DIVD) {
        if (!DivUnit->isBusy() && !existWAWDependence(instruction->getDest())) {
            issueInstruction(DivUnit, instruction);
            InstructionVec.pop_front();
            onProcessingInstVec.push_back(instruction);
        }
    }
}

void CPU::executeRead() {
    for (auto &unit :unitVec) {
        if (unit->isBusy() && unit->getInstruction()->getStage() == Stage::ReadOperand) {
            if (unit->getSourceOneReady() && unit->getSourceTwoReady()) {
                unit->getInstruction()->setStage(Stage::ExecComp);
            }
        }
    }
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
                    resolveRAWDependence(unit, dest);
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
                if ((unit->getSourceOneReg() == functionUnit->getDestReg() && unit->isSourceOneReady()) ||
                    (unit->getSourceTwoReg() == functionUnit->getDestReg() && unit->isSourceTwoReady())) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CPU::existWAWDependence(RegisterIdx dest) {
    for (auto &unit : unitVec) {
        if (unit->isBusy() && unit->getDestReg() == dest) {
            return true;
        }
    }
    return false;
}

void CPU::issueInstruction(std::shared_ptr<FunctionUnit> &functionUnit, std::shared_ptr<Instruction> &instruction) {
    functionUnit->acceptInstruction(instruction);
    functionUnit->getInstruction()->setStage(Stage::ReadOperand);
    functionUnit->setBusy(true);
    functionUnit->setSourceOneReg(instruction->getSourceOne());
    functionUnit->setSourceTwoReg(instruction->getSourceTwo());
    functionUnit->setDestReg(instruction->getDest());
    functionUnit->setOperation(instruction->getOperation());

    bool sourceOneRegSet = false, sourceTwoRegSet = false;
    for (auto &unit : unitVec) {
        if (unit != functionUnit && unit->isBusy()) {
            if (unit->getDestReg() == functionUnit->getSourceOneReg()) {
                functionUnit->setSourceOneUnit(unit);
                functionUnit->setSourceOneReady(false);
                sourceOneRegSet = true;
                break;
            }

            if (unit->getDestReg() == functionUnit->getSourceTwoReg()) {
                functionUnit->setSourceTwoUnit(unit);
                functionUnit->setSourceTwoReady(false);
                sourceTwoRegSet = true;
                break;
            }
        }
    }

    if (!sourceOneRegSet) {
        functionUnit->setSourceOneReady(true);
    }

    if (!sourceTwoRegSet) {
        functionUnit->setSourceTwoReady(true);
    }
}


void CPU::resolveRAWDependence(std::shared_ptr<FunctionUnit> &functionUnit, RegisterIdx dest) {
    for (auto &unit : unitVec) {
        if (unit != functionUnit && unit->getSourceOneReg() == dest && !unit->isSourceOneReady() &&
            unit->getInstruction()->getStage() == Stage::ReadOperand) {
            unit->setSourceOneReady(true);
        }
        if (unit != functionUnit && unit->getSourceTwoReady() == dest && !unit->isSourceTwoReady() &&
            unit->getInstruction()->getStage() == Stage::ReadOperand) {
            unit->setSourceTwoReady(true);
        }
    }
}





