//
// Created by yixiao on 2023/8/7.
//

#include "Component/FunctionUnitStatus.h"


bool FunctionUnitStatus::isBusy() {
    return Busy;
}

void FunctionUnitStatus::setBusy(bool isBusy) {
    this->Busy = isBusy;
}

void FunctionUnitStatus::setOperation(Operation operation) {
    this->operation = operation;
}

RegisterIdx FunctionUnitStatus::getSourceOneReg() {
    return sourceOne;
}

RegisterIdx FunctionUnitStatus::getSourceTwoReg() {
    return sourceTwo;
}

RegisterIdx FunctionUnitStatus::getDestReg() {
    return dest;
}

bool FunctionUnitStatus::getSourceOneReady() {
    return sourceOneReady;
}

bool FunctionUnitStatus::getSourceTwoReady() {
    return sourceTwoReady;
}

void FunctionUnitStatus::setSourceOneReady(bool ready) {
    this->sourceOneReady = ready;
}

void FunctionUnitStatus::setSourceTwoReady(bool ready) {
    this->sourceTwoReady = ready;
}

void FunctionUnitStatus::setSourceOneReg(RegisterIdx sourceOneReg) {
    this->sourceOne = sourceOneReg;
}

void FunctionUnitStatus::setSourceTwoReg(RegisterIdx sourceTwoReg) {
    this->sourceTwo = sourceTwoReg;
}

void FunctionUnitStatus::setDestReg(RegisterIdx destReg) {
    this->dest = destReg;
}

void FunctionUnitStatus::setSourceOneUnit(std::shared_ptr<FunctionUnit> &sourceOneUnit) {
    this->sourceOneUnit = sourceOneUnit;
}

void FunctionUnitStatus::setSourceTwoUnit(std::shared_ptr<FunctionUnit> &sourceTwoUnit) {
    this->sourceTwoUnit = sourceTwoUnit;
}




