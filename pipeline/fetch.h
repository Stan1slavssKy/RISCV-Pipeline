#ifndef PIPELINE_FETCH_STAGE_INSTRUCTION_H
#define PIPELINE_FETCH_STAGE_INSTRUCTION_H

#include "config.h"
#include "utils/macros.h"
#include "components/insn_memory.h"
#include "signals.h"
#include "registers.h"

#include <cassert>
#include <optional>

class FetchStage {
public:
    NO_COPY_SEMANTIC(FetchStage);
    NO_MOVE_SEMANTIC(FetchStage);

    FetchStage() = default;
    ~FetchStage() = default;

    void InitInstructionMemory(InsnMemory &&insnMemory)
    {
        insnMemory_ = std::move(insnMemory);
    }

    void Run(const PCCountRegister &pcCountReg, FetchDecodeRegister *fetchDecodeReg)
    {
        uint64_t pc = pcCountReg.PC;
        auto insn = insnMemory_.Read(pc);

        fetchDecodeReg->insnD = insn;
        fetchDecodeReg->PC = pc;
    }

private:
    InsnMemory insnMemory_;
};

#endif // PIPELINE_FETCH_STAGE_INSTRUCTION_H
