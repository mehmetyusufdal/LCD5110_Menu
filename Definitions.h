/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Rinky-Dink Electronics's Nokia 5110 GLCD Library is required.
    Source: http://www.rinkydinkelectronics.com/library.php?id=47
*/

#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#include "Arduino.h"
#include <LCD5110_Graph.h>

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