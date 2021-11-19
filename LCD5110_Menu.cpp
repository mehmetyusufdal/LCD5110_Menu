/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Rinky-Dink Electronics's Nokia 5110 GLCD Library is required.
    Source: http://www.rinkydinkelectronics.com/library.php?id=47
*/

#ifndef _LCD5110_MENU_
#define _LCD5110_MENU_
#include "LCD5110_Menu.h"

Menu::~Menu(){
    delete Menu::menu_items;
    delete Menu::lcd;

}

Menu::Menu(LCD5110 *lcd, String *menu_items, int menu_len, String title, int row_limit){
    Menu::lcd = lcd;
    Menu::chosen_item = 0;
    Menu::row_limit = row_limit;
    Menu::menu_len = menu_len;
    Menu::menu_items = menu_items;
    Menu::start_iter = 0;
    Menu::title = title;

}

void Menu::showMenu(){
    if(Menu::chosen_item >= Menu::menu_len) Menu::chosen_item = Menu::menu_len - 1;
    else if(Menu::chosen_item < 0) Menu::chosen_item = 0;

    if(Menu::chosen_item >= Menu::row_limit + Menu::start_iter) Menu::start_iter++;
    else if(Menu::chosen_item < Menu::start_iter) Menu::start_iter--;

    Menu::lcd->clrScr();
    Menu::lcd->print(title, CENTER, 0);
    for(int t=0;t<83;t++) if(t%2 == 0) Menu::lcd->setPixel(t, 8);

    String item = "";
    for(int i=Menu::start_iter; i<=Menu::row_limit + Menu::start_iter; i++){
        if(i == Menu::chosen_item) item = ">" + Menu::menu_items[i] + "<";
        else item =Menu::menu_items[i];

        Menu::lcd->print(item, CENTER, (i + 1 - Menu::start_iter) * 10);
    }

    Menu::lcd->update();
}

void Menu::setTitle(String title){ Menu::title = title; }

void Menu::setChosen(int chosen_item){ Menu::chosen_item = chosen_item; }

int Menu::getChosen(){ return Menu::chosen_item; }

#endif