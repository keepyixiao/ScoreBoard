//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_FUNCTIONUNITSTATUS_H
#define SCOREBOARD_FUNCTIONUNITSTATUS_H

#include "Util.h"
#include <memory>

class FunctionUnit;

class FunctionUnitStatus {
private:
    bool Busy;
    Operation operation;
    RegisterIdx dest;
    RegisterIdx sourceOne, sourceTwo;
    std::shared_ptr<FunctionUnit> sourceOneUnit;
    std::shared_ptr<FunctionUnit> sourceTwoUnit;
    bool sourceOneReady;
    bool sourceTwoReady;

public:

    bool isBusy();

    void setBusy(bool isBusy);

    void setOperation(Operation operation);

    RegisterIdx getSourceOneReg();

    RegisterIdx  getSourceTwoReg();

    RegisterIdx  getDestReg();

    bool getSourceOneReady();

    bool getSourceTwoReady();


};

#endif //SCOREBOARD_FUNCTIONUNITSTATUS_H
