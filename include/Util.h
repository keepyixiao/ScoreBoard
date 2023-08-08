//
// Created by yixiao on 2023/8/7.
//

#ifndef SCOREBOARD_UTIL_H
#define SCOREBOARD_UTIL_H

typedef enum RegisterIdx {
    NullRegister,
    F0,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15
} RegisterIdx;


typedef enum Stage {
    Issue,
    ReadOperand,
    ExecComp,
    WriteResult
} Stage;


typedef enum Operation {
    LOAD,
    MULD,
    SUBD,
    DIVD,
    ADDD
} Operation;

typedef enum Component {
    Integer,
    Mult1,
    Mult2,
    Add,
    Divide
} Component;

#endif //SCOREBOARD_UTIL_H
