#ifndef PIPELINE_INSTRUCTION_H
#define PIPELINE_INSTRUCTION_H

#include "config.h"
#include "utils/macros.h"
#include "utils/bit_ops.h"
#include "instruction/instruction_mnemonic.h"

#include <cassert>
#include <optional>

class Instruction {
public:
    static constexpr size_t INSTRUCTION_LENGTH = 4;

public:
    DEFAULT_COPY_SEMANTIC(Instruction);
    DEFAULT_MOVE_SEMANTIC(Instruction);

    Instruction() = default;
    ~Instruction() = default;

    Instruction(uint32_t rawInsn):
        rawInsn_(rawInsn)
      {}

    void DecodeFormat();

    std::optional<uint64_t> GetRS1() const;
    std::optional<uint64_t> GetRS2() const;
    std::optional<uint64_t> GetRD() const;
    std::optional<int32_t> GetIMM() const;

private:
    InsnFormat format_ {InsnFormat::INVALID};
    uint32_t rawInsn_ {0};
};

#endif // PIPELINE_INSTRUCTION_H
