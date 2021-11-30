/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Adafruit_GFX & Adafruit_PCD8544 Libraries are required.
    Sources: https://github.com/adafruit/Adafruit-GFX-Library
             https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library
*/

#ifndef _LCD5110_MENU_H_
#define _LCD5110_MENU_H_

#include <LCD5110_Screen.h>
class Menu: public Screen{
private:
    String *menu_items;
    int menu_len;
    int chosen_item;
    int row_limit;
    int start_iter;
    
public:
    /*
        Constructor method.
        Parameters:
            - Menu title. (It showns at top of the screen)
            - Pointer of the menu item titles array.
            - Length of the menu item titles array.
            - Optionel: Amount of menu items to be displayed on the screen withoud scrolling.
            If it is above the screen limit, the program does not runs correctly. Default value: 4
    */
    Menu(String, String*, int, int = 4);

    /*
        Prints menu on screen and shows selected menu item.
    */
    void showScreen();

    /*
        Sets the selected item of menu items. (Index of the item from the menu items array)
    */
    void setChosen(int);

    /*
        Returns selected item's index from the menu items array.
    */
    int getChosen();
};

#endif