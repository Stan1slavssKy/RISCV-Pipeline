#ifndef REGISTERS_H
#define REGISTERS_H

#include <cstdint>
#include "instruction/instruction.h"

struct PCCountRegister {
    uint64_t PC {0};
    uint64_t nextPC {0};
};

struct FetchDecodeRegister {
    Instruction insnD;
    uint64_t PC = 0;
};

struct DecodeExecuteRegister {
    Instruction insnE;
};

struct ExecuteMemoryReg {

};

struct MemoryWritebackReg {

};

#endif // REGISTERS_H
