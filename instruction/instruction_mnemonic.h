#ifndef INSTRUCTION_INSTRUCTION_MNEMONIC_H
#define INSTRUCTION_INSTRUCTION_MNEMONIC_H

#include <cstdint>

enum class InsnMnemonic {
    // R
    ADD,
    SUB,
    SLL,
    SLT,
    SLTU,
    XOR,
    SRL,
    SRA,
    OR,
    AND,
    // I
    // ARITHMETIC
    ADDI,
    SLTI,
    SLTUI,
    XORI,
    ORI,
    ANDI,
    SLLI,
    SRLI,
    SRAI,
    // LOAD
    LB,
    LH,
    LW,
    LBU,
    LHU,
    // JALR
    JALR,
    // S
    SB,
    SH,
    SW,
    // B
    BEQ,
    BNE,
    BLT,
    BGE,
    BLTU,
    BGEU,
    // U
    LUI,
    AUIPC,
    // J
    JAL,
    //
    NOP,
    //
    INVALID,
};

enum class InsnFormat {
    R,
    I,
    S,
    B,
    U,
    J,
    NOP,
    INVALID,
};

#endif // INSTRUCTION_INSTRUCTION_MNEMONIC_H
