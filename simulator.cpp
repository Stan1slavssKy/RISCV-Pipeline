#include "simulator.h"

void Simulator::InitPipeline(const std::vector<uint32_t> &rawInstructions)
{
    stages_.fetchStage.InitInstructionMemory(InsnMemory{rawInstructions});
}

void Simulator::RunPipeline()
{
    while(true) {
        stages_.fetchStage.Run(state_.pcCountReg, &(state_.fetchDecodeReg));
        stages_.decodeStage.Run(&(state_.fetchDecodeReg), &(state_.decodeExecuteReg));
    }
}
