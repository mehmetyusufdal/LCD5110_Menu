/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Adafruit_GFX & Adafruit_PCD8544 Libraries are required.
    Sources: https://github.com/adafruit/Adafruit-GFX-Library
             https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library

    ---------------------------------------------------------------------

    Basic example for this library. This program creates a menu object, shows it on the screen
    and allows navigate over the menu items with the encoder.

    Arduino_Rotary_Encoder Library is required for this example.
    Source: https://github.com/mehmetyusufdal/Arduino_Rotary_Encoder
*/

#include <LCD5110_Menu.h>
#include <Encoder.h>

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
Encoder encoder(ENC_CLK, ENC_DT, 0, 1, 0, 6); // Encoder generates values between 0-6 (0 and 6 included). Because menu has 7 options.

String menu_items[7] = {"Option1", "Option2", "Option3", "Option4", "Option5", "Option6", "Option7"}; // Menu item titles array.
Menu menu("MENU", menu_items, 7);

bool bg_light = true; // Backlight state of the lcd.

void setup(){
    pinMode(LCD_BL, OUTPUT);
    digitalWrite(LCD_BL, bg_light);
    
    Screen::lcd.begin();
    Screen::lcdReset();

    menu.showScreen(); // Show menu on display.

}

void loop(){
    // If the encoder's state changes, update chosen menu item and refresh menu.
    if(encoder.stateControl()){
        menu.setChosen(encoder.getState());
        menu.showScreen();
    }

}