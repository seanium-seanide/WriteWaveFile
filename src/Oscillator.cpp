/**
 * @file Oscillator.cpp
 *
 * @brief
 */

#include "Oscillator.hpp"

#include "constants.hpp"

#include <cmath>


Oscillator::Oscillator(float frequency, float amplitude)
: m_frequency(frequency)
, m_amplitude(amplitude)
, m_currentAngle(0.0)
, m_angleStep(0.0)
, m_currentSampleIndex(0)
{
  m_angleStep = 2 * M_PI * m_frequency / SAMPLE_RATE;
}

Oscillator::~Oscillator()
{
}

float Oscillator::nextSample()
{
  /*
  if (m_currentSampleIndex == SAMPLE_RATE)
  {
    m_currentSampleIndex = 0;
    m_currentAngle = 0.0;
  }
  */

  float sample = m_amplitude * std::sin(m_currentAngle);

  ++m_currentSampleIndex;
  m_currentAngle += m_angleStep;

  return sample;
}
