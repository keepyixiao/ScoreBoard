//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_SCOREBOARD_H
#define SCOREBOARD_SCOREBOARD_H

#include <memory>
#include "FunctionUnitStatus.h"
#include "RegisterStatus.h"

class ScoreBoard {

public:


private:
    std::unique_ptr<FunctionUnitStatus> integerComponentStatus;
    std::unique_ptr<FunctionUnitStatus> multiOneComponentStatus;
    std::unique_ptr<FunctionUnitStatus> multiTwoComponentStatus;
    std::unique_ptr<FunctionUnitStatus> addComponentStatus;
    std::unique_ptr<FunctionUnitStatus> divideComponentStatus;
    std::unique_ptr<RegisterStatus> registerStatus;

};

#endif //SCOREBOARD_SCOREBOARD_H
