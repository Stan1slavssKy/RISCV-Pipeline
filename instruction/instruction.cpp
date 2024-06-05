#include "instruction/instruction.h"
#include "utils/bit_ops.h"

void Instruction::DecodeFormat()
{
    uint64_t opcode = bitops::GetBits<6, 0>(rawInsn_);
    switch (opcode) {
        case 0b0110111:
            format_ = InsnFormat::U;
            break;
        case 0b0010111:
            format_ = InsnFormat::U;
            break;
        case 0b1100011: 
            format_ = InsnFormat::B;
            break;
        case 0b0000011:
            format_ = InsnFormat::I;
            break;
        case 0b0100011:
            format_ = InsnFormat::S;
            break;
        case 0b1100111:
            format_ = InsnFormat::I;
            break;
        case 0b0010011:
            format_ = InsnFormat::I;
            break;
        case 0b0110011:
            format_ = InsnFormat::R;
            break;
        case 0b1110011:
            format_ = InsnFormat::I;
            break;
        case 0b1101111:
            format_ = InsnFormat::J;
            break;
        default:
            format_ = InsnFormat::INVALID;
            break;
    }
}

std::optional<uint64_t> Instruction::GetRS1() const
{
    switch (format_) {
        case InsnFormat::R:
        case InsnFormat::I:
        case InsnFormat::S:
        case InsnFormat::B:
            return bitops::GetBits<19, 15>(rawInsn_);
        default:
            return std::nullopt;
    }
}

std::optional<uint64_t> Instruction::GetRS2() const
{
    switch (format_) {
        case InsnFormat::R:
        case InsnFormat::S:
        case InsnFormat::B:
            return bitops::GetBits<24, 20>(rawInsn_);
        default:
            return std::nullopt;
    }
}

std::optional<uint64_t> Instruction::GetRD() const
{
    switch (format_) {
        case InsnFormat::R:
        case InsnFormat::I:
        case InsnFormat::U:
        case InsnFormat::J:
            return bitops::GetBits<11, 7>(rawInsn_);
        default:
            return std::nullopt;
    }
}

std::optional<int32_t> Instruction::GetIMM() const
{
    switch (format_) {
        case InsnFormat::R:
            return std::nullopt;

        case InsnFormat::I: {
            return bitops::SignExtend<12, bitops::BitSizeof<word_t>()>(bitops::GetBits<31, 20>(rawInsn_));
        }
        case InsnFormat::S: {
            int32_t imm = (bitops::GetBits<31, 25>(rawInsn_) << 5) | bitops::GetBits<11, 7>(rawInsn_);
            return bitops::SignExtend<12, bitops::BitSizeof<word_t>()>(imm);
        }
        case InsnFormat::B: {
            int32_t imm = 0;
            imm |= (bitops::GetBits<11, 8>(rawInsn_)) << 1;
            imm |= (bitops::GetBits<30, 25>(rawInsn_)) << 5;
            imm |= (bitops::GetBits<7, 7>(rawInsn_)) << 11;
            imm |= bitops::SignExtend<1, bitops::BitSizeof<word_t>()>(bitops::GetBits<31, 31>(rawInsn_)) << 12;
            return imm;
        }

        case InsnFormat::U: {
            return bitops::SignExtend<20, bitops::BitSizeof<word_t>()>(bitops::GetBits<31, 12>(rawInsn_)) << 12;
        }
        case InsnFormat::J: {
            int32_t imm = 0;
            imm |= (bitops::GetBits<30, 21>(rawInsn_)) << 1;
            imm |= (bitops::GetBits<20, 20>(rawInsn_)) << 11;
            imm |= (bitops::GetBits<19, 12>(rawInsn_)) << 12;
            imm |= bitops::SignExtend<1, bitops::BitSizeof<word_t>()>(bitops::GetBits<31, 31>(rawInsn_)) << 20;
            return imm;
        }
    default:
        return std::nullopt;
    }
}
