//
// Created by yixiao on 2023/8/7.
//

#include "Component/CPU.h"

void CPU::execute() {
    executeIssue();
    executeRead();
    executeExecute();
    executeWrite();
}

void CPU::executeIssue() {

}

void CPU::executeRead() {

}

void CPU::executeExecute() {

}

void CPU::executeWrite() {

}

std::unique_ptr<InstructionParser> &CPU::getInstructionParser() {
    return instructionParser;
}



