/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Adafruit_GFX & Adafruit_PCD8544 Libraries are required.
    Sources: https://github.com/adafruit/Adafruit-GFX-Library
             https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library
*/

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <Definitions.h>

class Screen{
protected:
    String title;

public:
    static Adafruit_PCD8544 lcd;

    Screen(String title) : title(title){ }
    
    virtual void showScreen() = 0;

    /*
        Sets the title of menu. Does not updates screen. Changes will be visible when the menu reshowns.
    */
    void setTitle(String title){ Screen::title = title; }

};

#endif