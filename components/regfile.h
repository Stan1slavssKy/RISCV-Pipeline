#ifndef COMPONENTS_REGFILE_H
#define COMPONENTS_REGFILE_H

#include "config.h"
#include "utils/macros.h"

#include <array>
#include <cassert>

class Regfile {
public:
    NO_COPY_SEMANTIC(Regfile);
    NO_MOVE_SEMANTIC(Regfile);

    Regfile() = default;
    ~Regfile() = default;

    void WriteReg(uint32_t address, uint32_t data, bool writeEnable)
    {
        if (writeEnable) {
            assert(address < registers_.size());
            registers_[address] = data;
        }
    }

    uint32_t ReadReg(uint32_t address)
    {
        assert(address < registers_.size());
        return registers_[address];
    }

private:
    std::array<uint32_t, REG_NUM> registers_;
};

#endif // COMPONENTS_REGFILE_H
