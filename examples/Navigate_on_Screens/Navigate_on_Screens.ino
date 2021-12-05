/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Adafruit_GFX & Adafruit_PCD8544 Libraries are required.
    Sources: https://github.com/adafruit/Adafruit-GFX-Library
             https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library

    ---------------------------------------------------------------------

    This example shows how to navigate on different pages by using rotary encoder.

    Arduino_Rotary_Encoder Library is required for this example.
    Source: https://github.com/mehmetyusufdal/Arduino_Rotary_Encoder
*/

#include <LCD5110_Menu.h>
#include <Encoder.h>
#include "Pages.h"

#define LCD_CLK 8  // sck |---------|
#define LCD_Din 9  // din |         |
#define LCD_DC 10  // dc  | LCD5110 |
#define LCD_RST 11 // rst | Piouts  |
#define LCD_CE 12  // cs  |         |
#define LCD_BL 13  // sw  |---------|

#define ENC_CLK 4 // A  |-----------------|
#define ENC_DT 3  // B  | Encoder Pinouts |
#define ENC_SW 2  // sw |-----------------|

Adafruit_PCD8544 Screen::lcd = Adafruit_PCD8544(LCD_CLK, LCD_Din, LCD_DC, LCD_CE, LCD_RST); // Initialize Screen's static Adafruit_PCD8544 object.
int Screen::active_page = -1; // -1 means menu page is displaying on the screen.

Encoder encoder(ENC_CLK, ENC_DT, 0, 1, 0, 3); // Encoder generates values between 0-3 (0 and 3 included). Because menu has 4 options.

String menu_items[4] = {"First", "Second", "Third", "About"}; // Menu item titles array.
Menu menu("MENU", menu_items, 4);

Pages pgs;

bool bg_light = true; // Backlight state of the lcd.

bool sw_last_state = false;
bool buttonHandler();

void setup(){
    pinMode(ENC_SW, INPUT_PULLUP);
    pinMode(LCD_BL, OUTPUT);
    digitalWrite(LCD_BL, bg_light);

    Screen::lcd.begin();
    Screen::lcdReset();

    menu.showScreen(); // Show menu on display.

}

void loop(){
    // If the encoder's state changes, update chosen menu item and refresh menu.
    if(Screen::active_page == -1 && encoder.stateControl()){
        menu.setChosen(encoder.getState());
        menu.showScreen();
    }

    if(buttonHandler()){
        if(Screen::active_page != -1){ // If active page is not menu, return to menu.
            Screen::active_page = -1;
            menu.showScreen();
        }
        else{ // Go to the selected page on menu.
            Screen::active_page = encoder.getState();
            pgs.showScreen();
        }
    }
    

}

bool buttonHandler(){
    bool sw_state = false;
    if(!digitalRead(ENC_SW) && !sw_last_state) sw_state = true;
    sw_last_state = !digitalRead(ENC_SW);

    return sw_state;
}