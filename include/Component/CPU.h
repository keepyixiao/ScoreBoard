//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_CPU_H
#define SCOREBOARD_CPU_H

#include "RegisterStatus.h"
#include "Instruction/Instruction.h"
#include "FunctionUnit.h"
#include "PipelineRegister.h"
#include "Instruction/InstructionParser.h"
#include <deque>
#include <vector>
#include <memory>

class CPU {

private:
    int totalCycle = 0;
    std::deque<std::shared_ptr<Instruction>> InstructionVec;
    std::deque<std::shared_ptr<Instruction>> onProcessingInstVec;
    std::vector<std::shared_ptr<Instruction>> finishedInstVec;


    std::shared_ptr<FunctionUnit> MulUnitOne;
    std::shared_ptr<FunctionUnit> MulUnitTwo;
    std::shared_ptr<FunctionUnit> DivUnit;
    std::shared_ptr<FunctionUnit> AddUnit;
    std::shared_ptr<FunctionUnit> IntegerUnit;

    std::vector<std::shared_ptr<FunctionUnit>> unitVec;

    std::unique_ptr<PipelineRegister> InstructionRegister;

    std::unique_ptr<InstructionParser> instructionParser;

    std::unique_ptr<RegisterStatus> registerStatus;


public:

    void initCPU();

    bool terminated();

    void execute();

    void executeIssue();

    void executeRead();

    void executeExecute();

    void executeWrite();

    void issueInstruction(std::shared_ptr<FunctionUnit> &functionUnit, std::shared_ptr<Instruction> &instruction);

    bool existWARDependence(std::shared_ptr<FunctionUnit> &functionUnit);

    bool existWAWDependence(RegisterIdx dest);

    std::unique_ptr<InstructionParser> &getInstructionParser();

    std::deque<std::shared_ptr<Instruction>> &getInstructionVec();

    std::unique_ptr<RegisterStatus> &getRegisterStatus();


};

#endif //SCOREBOARD_CPU_H
