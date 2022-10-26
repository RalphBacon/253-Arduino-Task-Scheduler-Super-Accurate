#include "Arduino.h"
#pragma once

  // Define which segments the 7-seg display needs to display each number 0 - 9 and A - F
  // Common anode units require 0 to be ON and 1 to be OFF
  // Common cathode digits require 1 to be ON and 0 to be OFF

  const uint8_t _digits[11] = {
    //abcdefgx
    0b00000011,  // 0 ie segments abcdef but not g nor the dp (x)
    0b10011111,  // 1
    0b00100101,  // 2
    0b00001101,  // 3
    0b10011001,  // 4
    0b01001001,  // 5
    0B01000001,  // 6
    0B00011111,  // 7
    0b00000001,  // 8
    0b00001001,  // 9
    0b11111111,  // Blank 10
  };