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

#define LEFT 0
#define CENTER_X 1
#define RIGHT 2
#define TOP 3
#define CENTER_Y 4
#define BOTTOM 5

class Screen{
protected:
    String title;

    int textAlign(int align, const String *txt, int offset = 0){
        if(align == LEFT || align == TOP) return offset;

        int return_val;
        int16_t x1, y1;
        uint16_t w, h;

        lcd.getTextBounds(*txt, 0, 0, &x1, &y1, &w, &h);

        switch (align)
        {
            case CENTER_X:
                return_val = (LCD_LenX - (w - offset)) / 2;
                break;
            case RIGHT:
                return_val = LCD_LenX - (w + offset);
                break;
            case CENTER_Y:
                return_val = (LCD_LenY - (h - offset)) / 2;
                break;
            case BOTTOM:
                return_val = LCD_LenY - (h + offset);
                break;
        }

        return return_val;
        }

public:
    static Adafruit_PCD8544 lcd;
    
    virtual void showScreen() = 0;

    void lcdReset(){
        lcd.clearDisplay();
        lcd.setTextSize(1);
        lcd.setTextColor(BLACK);
        lcd.setCursor(0,0);
    }

    /*
        Sets the title of menu. Does not updates screen. Changes will be visible when the menu reshowns.
    */
    void setTitle(String title){ Screen::title = title; }

};

#endif