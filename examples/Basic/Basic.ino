/*
    --LCD5110_MENU by Mehmet Yusuf Dal--
    This library is for generating a menu UI on Nokia 5110 GLCD display.

    Rinky-Dink Electronics's Nokia 5110 GLCD Library is required.
    Source: http://www.rinkydinkelectronics.com/library.php?id=47

    ---------------------------------------------------------------------

    Basic example for this library. This program creates a menu object, shows it on the screen
    and allows navigate over the menu items with the encoder.

    Arduino_Rotary_Encoder Library is required for this example.
    Source: https://github.com/mehmetyusufdal/Arduino_Rotary_Encoder
*/

#include <LCD5110_Menu.h>
#include <Encoder.h>

LCD5110 Screen::lcd = LCD5110(LCD_CLK, LCD_Din, LCD_DC, LCD_RST, LCD_CE); // Initialize Screen's static LCD5110 object.
Encoder encoder(ENC_CLK, ENC_DT, 0, 1, 0, 6); // Encoder generates values between 0-6 (0 and 6 included). Because menu has 7 options.

String menu_items[7] = {"Option1", "Option2", "Option3", "Option4", "Option5", "Option6", "Option7"}; // Menu item titles array.
Menu menu("MENU", menu_items, 7);

extern uint8_t SmallFont[]; // Font type for the lcd.
bool bg_light = true; // Backlight state of the lcd.

void setup(){
    menu.lcd.InitLCD(50);
    menu.lcd.setFont(SmallFont);
    pinMode(LCD_BL, OUTPUT);
    digitalWrite(LCD_BL, bg_light);

    menu.showScreen(); // Show menu on display.

}

void loop(){
    // If the encoder's state changes, update chosen menu item and refresh menu.
    if(encoder.stateControl()){
        menu.setChosen(encoder.getState());
        menu.showScreen();
    }

}