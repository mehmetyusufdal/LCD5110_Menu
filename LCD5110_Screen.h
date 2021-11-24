/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Rinky-Dink Electronics's Nokia 5110 GLCD Library is required.
    Source: http://www.rinkydinkelectronics.com/library.php?id=47
*/

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <Definitions.h>

class Screen{
protected:
    String title;

public:
    static LCD5110 lcd;

    Screen(String title) : title(title){ }
    
    virtual void showScreen() = 0;

    /*
        Sets the title of menu. Does not updates screen. Changes will be visible when the menu reshowns.
    */
    void setTitle(String title){ Screen::title = title; }

};

#endif