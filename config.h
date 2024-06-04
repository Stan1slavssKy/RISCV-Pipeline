#ifndef CONFIG_H
#define CONFIG_H

#include <stddef.h>

constexpr const size_t MEMORY_SIZE = 1 << 12;
constexpr const size_t BITNESS = 1 << 5;
constexpr const size_t REG_NUM = 1 << 5;
constexpr const size_t BYTE = 1 << 3;

#endif // CONFIG_H
