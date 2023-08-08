//
// Created by yixiao on 2023/8/8.
//

#ifndef SCOREBOARD_REGISTERSTATUS_H
#define SCOREBOARD_REGISTERSTATUS_H

#include <unordered_map>
#include "Util.h"

class RegisterStatus {

private:
    std::unordered_map<RegisterIdx, Component> RegisterResultMap;
};

#endif //SCOREBOARD_REGISTERSTATUS_H
