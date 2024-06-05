#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "utils/macros.h"

#include "pipeline/fetch.h"
#include "pipeline/decode.h"
#include "pipeline/execute.h"
#include "pipeline/memory.h"
#include "pipeline/writeback.h"

#include "registers.h"

class Simulator {
public:
    NO_COPY_SEMANTIC(Simulator);
    NO_MOVE_SEMANTIC(Simulator);

    Simulator() = default;
    ~Simulator() = default;

    void InitPipeline(const std::vector<uint32_t> &rawInstructions);
    void RunPipeline();

private:
    struct State {
        PCCountRegister pcCountReg;
        FetchDecodeRegister fetchDecodeReg;
        DecodeExecuteRegister decodeExecuteReg;
        ExecuteMemoryReg executeMemoryReg;
        MemoryWritebackReg memoryWritebackReg;
    };

    struct Stages {
        FetchStage fetchStage;
        DecodeStage decodeStage;
        // ExecuteStage executeStage;
        // MemoryStage memoryStage;
        // WritebackStage writebackStage;
    };

private:
    Stages stages_;
    State state_;
    Signals signals_;
};

#endif // SIMULATOR_H
