/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Rinky-Dink Electronics's Nokia 5110 GLCD Library is required.
    Source: http://www.rinkydinkelectronics.com/library.php?id=47
*/

#ifndef _LCD5110_MENU_H_
#define _LCD5110_MENU_H_

#include "Arduino.h"
#include <LCD5110_Graph.h> 

class Menu{
private:
    LCD5110 *lcd;
    String *menu_items;
    String title;
    int menu_len;
    int chosen_item;
    int row_limit;
    int start_iter;
    
public:
    /*
        Deconstructor method.
    */
    ~Menu();

    /*
        Constructor method.
        Parameters:
            - Pointer of the LCD5110 object.
            - Pointer of the menu item titles array.
            - Length of the menu item titles array.
            - Menu title. (It showns at top of the screen)
            - Optionel: Amount of menu items to be displayed on the screen withoud scrolling.
            If it is above the screen limit, the program does not runs correctly. Default value: 4
    */
    Menu(LCD5110*, String*, int, String, int = 4);

    /*
        Prints menu on screen and shows selected menu item.
    */
    void showMenu();

    /*
        Sets the title of menu. Does not updates screen. Changes will be visible when the menu reshowns.
    */
    void setTitle(String);

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