#ifndef PIPELINE_INSTRUCTION_H
#define PIPELINE_INSTRUCTION_H

#include "config.h"
#include "utils/macros.h"

#include <cassert>

class Instruction {
public:
    static constexpr size_t INSTRUCTION_LENGTH = 4;

public:
    DEFAULT_COPY_SEMANTIC(Instruction);
    DEFAULT_MOVE_SEMANTIC(Instruction);

    Instruction();
    ~Instruction() = default;

private:
};

#endif // PIPELINE_INSTRUCTION_H
