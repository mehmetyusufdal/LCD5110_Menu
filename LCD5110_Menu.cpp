/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Adafruit_GFX & Adafruit_PCD8544 Libraries are required.
    Sources: https://github.com/adafruit/Adafruit-GFX-Library
             https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library
*/

#ifndef _LCD5110_MENU_
#define _LCD5110_MENU_

#include <LCD5110_Menu.h>

Menu::Menu(String title, String *menu_items, int menu_len, int row_limit) {
    Menu::chosen_item = 0;
    Menu::row_limit = row_limit;
    Menu::menu_len = menu_len;
    Menu::menu_items = menu_items;
    Menu::start_iter = 0;
    Menu::title = title;

}

void Menu::showScreen(){
    if(Menu::chosen_item >= Menu::menu_len) Menu::chosen_item = Menu::menu_len - 1;
    else if(Menu::chosen_item < 0) Menu::chosen_item = 0;

    if(Menu::chosen_item >= Menu::row_limit + Menu::start_iter) Menu::start_iter++;
    else if(Menu::chosen_item < Menu::start_iter) Menu::start_iter--;

    Menu::lcd.clearDisplay();
    Menu::lcd.setCursor(Menu::textAlign(CENTER_X, &(Menu::title)), 0);
    Menu::lcd.print(Menu::title);
    Menu::lcd.drawLine(0, 8, 83, 8, BLACK);

    String item = "";
    for(int i=Menu::start_iter; i<=Menu::row_limit + Menu::start_iter; i++){
        if(i == Menu::chosen_item) item = ">" + Menu::menu_items[i] + "<";
        else item =Menu::menu_items[i];

        Menu::lcd.setCursor(Menu::textAlign(CENTER_X, &item), (i + 1 - Menu::start_iter) * 10);
        Menu::lcd.print(item);
    }

    Menu::lcd.display();
}

void Menu::setChosen(int chosen_item){ Menu::chosen_item = chosen_item; }

int Menu::getChosen(){ return Menu::chosen_item; }

#endif