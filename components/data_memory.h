#ifndef COMPONENTS_MEMORY_H
#define COMPONENTS_MEMORY_H

#include "config.h"
#include "utils/macros.h"

#include <array>
#include <cstring>
#include <cassert>
#include <type_traits>

class DataMemory {
public:
    NO_COPY_SEMANTIC(DataMemory);
    NO_MOVE_SEMANTIC(DataMemory);

    DataMemory() = default;
    ~DataMemory() = default;

    // T = [uint8_t, uint16_t, uint32_t]
    template<typename T>
    void Write(uint32_t address, uint32_t writeData, bool writeEnable)
    {
        if (!writeEnable) {
            return;
        }

        assert(address < memory_.size());
        assert((std::is_same<T, uint8_t>() == true) || (std::is_same<T, uint16_t>() == true) || (std::is_same<T, uint32_t>() == true));

        T data = static_cast<T>(writeData);
        std::memcpy(&memory_ + address, &data, sizeof(T));
    }

    // T = [uint8_t, uint16_t, uint32_t]
    template<typename T>
    uint32_t Read(uint32_t address)
    {
        assert(address < memory_.size());
        assert((std::is_same<T, uint8_t>() == true) || (std::is_same<T, uint16_t>() == true) || (std::is_same<T, uint32_t>() == true));

        uint32_t result = 0;        
        std::memcpy(&result, &memory_ + address, sizeof(T));
        
        return result;
    }

private:
    std::array<uint8_t, MEMORY_SIZE> memory_;
};

#endif // COMPONENTS_MEMORY_H
