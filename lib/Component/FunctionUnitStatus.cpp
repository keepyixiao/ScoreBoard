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




