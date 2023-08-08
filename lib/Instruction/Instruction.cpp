//
// Created by yixiao on 2023/8/7.
//

#include "Instruction/Instruction.h"


Instruction::Instruction(RegisterIdx dest, RegisterIdx sourceOne, RegisterIdx sourceTwo) {
    this->dest = dest;
    this->sourceOne = sourceOne;
    this->sourceTwo = sourceTwo;
}

Instruction::Instruction(RegisterIdx dest, RegisterIdx sourceOne) {
    this->dest = dest;
    this->sourceOne = sourceOne;
}

Stage Instruction::getStage() {
    return this->stage;
}

void Instruction::setStage(Stage stage) {
    this->stage = stage;
}


Operation Instruction::getOperation() {
    return this->operation;
}

void Instruction::setOperation(Operation operation) {
    this->operation = operation;
}


RegisterIdx Instruction::getDest() {
    return this->dest;
}

void Instruction::setDest(RegisterIdx dest) {
    this->dest = dest;
}

RegisterIdx Instruction::getSourceOne() {
    return this->sourceOne;
}

void Instruction::setSourceOne(RegisterIdx sourceOne) {
    this->sourceOne = sourceOne;
}

RegisterIdx Instruction::getSourceTwo() {
    return this->sourceTwo;
}

void Instruction::setSourceTwo(RegisterIdx sourceTwo) {
    this->sourceTwo = sourceTwo;

}