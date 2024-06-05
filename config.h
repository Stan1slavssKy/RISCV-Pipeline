#ifndef CONFIG_H
#define CONFIG_H

#include <cstddef>
#include <cstdint>

constexpr const size_t MEMORY_SIZE = 1 << 12;
constexpr const size_t REG_NUM = 1 << 5;
constexpr const size_t BYTE = 1 << 3;

using byte_t = uint8_t;
static constexpr size_t BYTE_SIZE = sizeof(byte_t);

using hword_t = uint16_t;
static constexpr size_t HWORD_SIZE = sizeof(hword_t);

using word_t = uint32_t;
static constexpr size_t WORD_SIZE = sizeof(word_t);

using dword_t = uint64_t;
static constexpr size_t DWORD_SIZE = sizeof(dword_t);

static constexpr size_t BITS_PER_BYTE = 1 << 3;
static constexpr size_t KBYTE_SIZE    = 1 << 10;
static constexpr size_t MBYTE_SIZE    = 1 << 20;

using reg_t      = dword_t;
using addr_t     = reg_t;
using bit_size_t = reg_t;

#endif // CONFIG_H
