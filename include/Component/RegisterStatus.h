//
// Created by yixiao on 2023/8/8.
//

#ifndef SCOREBOARD_REGISTERSTATUS_H
#define SCOREBOARD_REGISTERSTATUS_H

#include <unordered_map>
#include "Util.h"

class RegisterStatus {
public:
    void recordFunctionUnitToRegisterResultMap(RegisterIdx registerIdx, Component component);

    void removeFunctionUnitFromRegisterResultMap(RegisterIdx registerIdx);

private:
    std::unordered_map<RegisterIdx, Component> RegisterResultMap;
};

#endif //SCOREBOARD_REGISTERSTATUS_H
