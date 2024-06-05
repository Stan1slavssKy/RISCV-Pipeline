#include "simulator.h"

#include <cstdint>
#include <vector>

int main() 
{
    std::vector<uint32_t> rawInstructions = {
        0x00000093,
        0x00000113,
        0x01200193,
        0x00310c63,
        0x00202823,
        0x002080b3,
        0x01002103,
        0x00110113,
        0xfe0006e3,
        0x00000013,
        0x00000013,
    };

    Simulator simulator;
    simulator.InitPipeline(rawInstructions);
    simulator.RunPipeline();
}
