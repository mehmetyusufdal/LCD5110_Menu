/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Adafruit_GFX & Adafruit_PCD8544 Libraries are required.
    Sources: https://github.com/adafruit/Adafruit-GFX-Library
             https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library
*/

#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#include "Arduino.h"

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#define LCD_LenX 84
#define LCD_LenY 48

#define LCD_CLK 8  // sck |---------|
#define LCD_Din 9  // din |         |
#define LCD_DC 10  // dc  | LCD5110 |
#define LCD_RST 11 // rst | Piouts  |
#define LCD_CE 12  // cs  |         |
#define LCD_BL 13  // sw  |---------|

#define ENC_CLK 4 // A  |-----------------|
#define ENC_DT 3  // B  | Encoder Pinouts |
#define ENC_SW 2  // sw |-----------------|

#endif