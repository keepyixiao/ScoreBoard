//
// Created by yixiao on 2023/8/9.
//

#include "Component/RegisterStatus.h"

void RegisterStatus::recordFunctionUnitToRegisterResultMap(RegisterIdx registerIdx, Component component) {
    RegisterResultMap[registerIdx] = component;
}

void RegisterStatus::removeFunctionUnitFromRegisterResultMap(RegisterIdx registerIdx) {
    RegisterResultMap.erase(registerIdx);
}

