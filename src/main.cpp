#include <iostream>
#include <fstream>

#include <cstdint>

#include "Oscillator.hpp"
#include "constants.hpp"


template<typename T>
std::ofstream &writeBytes(std::ofstream &file, T data)
{
  file.write(reinterpret_cast<char *>(&data), sizeof(T));

  return file;
}


int main(int argc, char **argv)
{
  uint32_t duration = 2;
  Oscillator sinusoid(440.0, 0.5);

  // Open wave file

  std::ofstream audioFile;
  audioFile.open("sound.wav", std::ios::binary);

  // Header chunk

  audioFile << "RIFF";
  int sizeLocation1 = audioFile.tellp();
  audioFile << "----"; // size
  audioFile << "WAVE";

  // Format subchunk

  audioFile << "fmt ";
  static_cast<void>(writeBytes(audioFile, static_cast<uint32_t>(FORMAT_SUBCHUNK_SIZE)));
  static_cast<void>(writeBytes(audioFile, static_cast<uint16_t>(COMPRESSION_CODE)));
  static_cast<void>(writeBytes(audioFile, static_cast<uint16_t>(NUM_CHANNELS)));
  static_cast<void>(writeBytes(audioFile, static_cast<uint32_t>(SAMPLE_RATE)));
  static_cast<void>(writeBytes(audioFile, static_cast<uint32_t>(BYTE_RATE)));
  uint32_t size1 = audioFile.tellp();
  static_cast<void>(writeBytes(audioFile, static_cast<uint16_t>(BLOCK_ALIGN)));
  static_cast<void>(writeBytes(audioFile, static_cast<uint16_t>(BIT_DEPTH)));
  //static_cast<void>(writeBytes(audioFile, static_cast<uint16_t>(NUM_EXTRA_FORMAT_BYTES)));

  // Data subchunk

  audioFile << "data";
  int sizeLocation2 = audioFile.tellp();
  audioFile << "----"; // Size

  int start = audioFile.tellp();

  for (int i = 0; i < SAMPLE_RATE * duration; ++i)
  {
    int16_t sample = MAX_AMPLITUDE * sinusoid.nextSample();
    audioFile.write(reinterpret_cast<char *>(&sample), sizeof(uint16_t));
  }

  int end = audioFile.tellp();

  uint32_t size2 = end - start;

  // Fill in sizes

  audioFile.seekp(sizeLocation1);
  writeBytes(audioFile, size1);

  audioFile.seekp(sizeLocation2);
  writeBytes(audioFile, size2);

  // Close wave file

  audioFile.close();

  return 0;
}
