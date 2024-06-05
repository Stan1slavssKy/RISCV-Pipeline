#ifndef COMPONENTS_INSN_MEMORY_H
#define COMPONENTS_INSN_MEMORY_H

#include "config.h"
#include "utils/macros.h"
#include "instruction/instruction.h"

#include <vector>
#include <cassert>

class InsnMemory {
public:
    DEFAULT_COPY_SEMANTIC(InsnMemory);
    DEFAULT_MOVE_SEMANTIC(InsnMemory);

    explicit InsnMemory(const std::vector<uint32_t> &rawInstructions)
    {
        for (auto it : rawInstructions) {
            instructions_.push_back(Instruction{it});
        }
    }

    InsnMemory() = default;
    ~InsnMemory() = default;

    Instruction Read(uint64_t pc)
    {
        assert(pc % Instruction::INSTRUCTION_LENGTH == 0);
        uint64_t pos = pc / Instruction::INSTRUCTION_LENGTH;

        assert(pos < instructions_.size());
        return instructions_[pos];
    }

private:
    std::vector<Instruction> instructions_;
};

#endif // COMPONENTS_INSN_MEMORY_H
