#ifndef COMPONENTS_INSN_MEMORY_H
#define COMPONENTS_INSN_MEMORY_H

#include "config.h"
#include "utils/macros.h"
#include "pipeline/instruction.h"

#include <vector>
#include <cassert>

class InsnMemory {
public:
    NO_COPY_SEMANTIC(InsnMemory);
    NO_MOVE_SEMANTIC(InsnMemory);

    InsnMemory(const std::vector<Instruction> insns) : instructions_(insns)
      {}
    ~InsnMemory() = default;

    Instruction Read(uint32_t pc)
    {
        assert(pc % Instruction::INSTRUCTION_LENGTH == 0);
        uint32_t pos = pc / Instruction::INSTRUCTION_LENGTH;

        assert(pos < instructions_.size());
        return instructions_[pos];
    }

private:
    std::vector<Instruction> instructions_;
};

#endif // COMPONENTS_INSN_MEMORY_H
