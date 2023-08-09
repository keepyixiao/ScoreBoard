//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_INSTRUCTIONPARSE_H
#define SCOREBOARD_INSTRUCTIONPARSE_H

#include <deque>
#include <memory>
#include "Instruction/Instruction.h"

class InstructionParser {
public:
    void parseInstruction(std::deque<std::shared_ptr<Instruction>> &InstructionVec,char *instructionFilePath);

};

#endif //SCOREBOARD_INSTRUCTIONPARSE_H
