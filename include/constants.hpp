#pragma once

/**
 * @file constants.cpp
 *
 * @brief
 */

#include <cstdint>
#include <cmath>


constexpr uint32_t SAMPLE_RATE = 44100;
constexpr uint16_t BIT_DEPTH = 16;
constexpr uint32_t MAX_SHORT = (1 << (BIT_DEPTH - 1)) - 1;
constexpr uint32_t MAX_AMPLITUDE = MAX_SHORT - (MAX_SHORT % 100);

constexpr uint32_t FORMAT_SUBCHUNK_SIZE = 16;
constexpr uint16_t COMPRESSION_CODE = 1;
constexpr uint16_t NUM_CHANNELS = 1;
constexpr uint32_t BIT_RATE = SAMPLE_RATE * BIT_DEPTH * NUM_CHANNELS;
constexpr uint32_t BYTE_RATE = BIT_RATE / 8;
constexpr uint16_t BLOCK_ALIGN = BIT_DEPTH * NUM_CHANNELS / 8;
constexpr uint16_t NUM_EXTRA_FORMAT_BYTES = 0;
