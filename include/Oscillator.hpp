#pragma once

/**
 * @file Oscillator.hpp
 *
 * @brief
 */

#include "Oscillator.hpp"

#include <cstdint>


class Oscillator
{
public:

  /**
   * @brief
   *
   * @param frequency
   * @param amplitude
   */
  Oscillator(float frequency, float amplitude);

  ~Oscillator();

  float nextSample();

private:

  float m_frequency;
  float m_amplitude;
  float m_currentAngle;
  float m_angleStep;
  uint32_t m_currentSampleIndex;
};
