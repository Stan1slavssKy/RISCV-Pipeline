#ifndef PIPELINE_DECODE_STAGE_INSTRUCTION_H
#define PIPELINE_DECODE_STAGE_INSTRUCTION_H

#include "utils/macros.h"
#include "components/regfile.h"
#include "registers.h"

#include <cassert>
#include <optional>

class DecodeStage {
public:
    NO_COPY_SEMANTIC(DecodeStage);
    NO_MOVE_SEMANTIC(DecodeStage);

    DecodeStage() = default;
    ~DecodeStage() = default;

    void Run(FetchDecodeRegister *fetchDecodeReg, DecodeExecuteRegister *decodeExecuteReg)
    {
        auto &insn = fetchDecodeReg->insnD;
        insn.DecodeFormat();
        decodeExecuteReg->insnE = insn;
    }

private:
    Regfile regfile_;
};

#endif // PIPELINE_DECODE_STAGE_INSTRUCTION_H
