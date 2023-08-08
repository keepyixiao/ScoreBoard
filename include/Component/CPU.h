//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_CPU_H
#define SCOREBOARD_CPU_H

#include "ScoreBoard.h"
#include "Instruction/Instruction.h"
#include "FunctionUnit.h"
#include "PipelineRegister.h"
#include "Instruction/InstructionParser.h"
#include <deque>
#include <vector>
#include <memory>

class CPU {

private:
    int totalCycle;
    std::unique_ptr<ScoreBoard> scoreBoard;
    std::deque<std::shared_ptr<Instruction>> InstructionVec;
    std::deque<std::shared_ptr<Instruction>> onProcessingInstVec;
    std::vector<std::shared_ptr<Instruction>> finishedInstVec;


    std::unique_ptr<FunctionUnit> MulUnitOne;
    std::unique_ptr<FunctionUnit> MulUnitTwo;
    std::unique_ptr<FunctionUnit> DivUnit;
    std::unique_ptr<FunctionUnit> AddUnit;
    std::unique_ptr<FunctionUnit> IntegerUnit;

    std::unique_ptr<PipelineRegister> InstructionRegister;

    std::unique_ptr<InstructionParser> instructionParser;


public:
    void execute();

    void executeIssue();

    void executeRead();

    void executeExecute();

    void executeWrite();

    std::unique_ptr<InstructionParser> &getInstructionParser();


};

#endif //SCOREBOARD_CPU_H
