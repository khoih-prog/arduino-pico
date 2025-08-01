#pragma once

// Waveshare RP2350 Zero
// https://www.waveshare.com/wiki/RP2350-Zero
// https://files.waveshare.com/wiki/RP2350-Zero/RP2350_Zero.pdf
// https://www.waveshare.com/img/devkit/RP2350-Zero/RP2350-Zero-details-7.jpg
//

/*
                Pin#              Pin#
                    ___(_____)___
              5v 1 |   *USB C*   | 23 GPIO0
             GND 2 |             | 22 GPIO1
            3.3v 3 |             | 21 GPIO2
          GPIO29 4 |             | 20 GPIO3
          GPIO28 5 |             | 19 GPIO4
          GPIO27 6 |             | 18 GPIO5
          GPIO26 7 |             | 17 GPIO6
          GPIO15 8 |             | 16 GPIO7
          GPIO14 9 |__|_|_|_|_|__| 15 GPIO8
                      1 1 1 1 1
                      0 1 2 3 4

                    Pin10 = GPIO13
                    Pin11 = GPIO12
                    Pin12 = GPIO11
                    Pin13 = GPIO10
                    Pin14 = GPIO9
*/

#define PICO_RP2350A 1

// NeoPixel
#define PIN_NEOPIXEL (16u)

// Serial1
#define PIN_SERIAL1_TX (0u)
#define PIN_SERIAL1_RX (1u)

#define PIN_SERIAL2_TX (8u)
#define PIN_SERIAL2_RX (9u)

// SPI
#define PIN_SPI0_MISO (4u)
#define PIN_SPI0_MOSI (3u)
#define PIN_SPI0_SCK (2u)
#define PIN_SPI0_SS (5u)

#define PIN_SPI1_MISO (12u)
#define PIN_SPI1_MOSI (15u)
#define PIN_SPI1_SCK (14u)
#define PIN_SPI1_SS (13u)

// Wire
#define PIN_WIRE0_SDA (4u)
#define PIN_WIRE0_SCL (5u)

#define PIN_WIRE1_SDA (26u)
#define PIN_WIRE1_SCL (27u)

#define SERIAL_HOWMANY (2u)
#define SPI_HOWMANY (2u)
#define WIRE_HOWMANY (2u)

#include "../generic/common.h"
