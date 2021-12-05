#ifndef _PAGES_H_
#define _PAGES_H_

#include <LCD5110_Screen.h>

class Pages : public Screen{
private:
    void firstScr(){
        String txt = "First Page";

        lcdReset();
        lcd.setCursor(textAlign(CENTER_X, &txt), textAlign(CENTER_Y, &txt));
        lcd.print(txt);
        lcd.display();
    }

    void secondScr(){
        String txt = "Second Page";

        lcdReset();
        lcd.setCursor(textAlign(CENTER_X, &txt), textAlign(CENTER_Y, &txt));
        lcd.print(txt);
        lcd.display();
    }

    void thirdScr(){
        String txt = "Third Page";

        lcdReset();
        lcd.setCursor(textAlign(CENTER_X, &txt), textAlign(CENTER_Y, &txt));
        lcd.print(txt);
        lcd.display();
    }

    void aboutScr(){
        String title = "About";
        String project = "LCD5110_Menu";
        String creator_name = "Mehmet Yusuf";
        String creator_surname = "Dal";

        lcdReset();
        lcd.setCursor(textAlign(CENTER_X, &title), 0);
        lcd.println(title);
        lcd.drawLine(0, lcd.getCursorY() + 1, 83, lcd.getCursorY() + 1, BLACK);

        lcd.setCursor(textAlign(CENTER_X, &project), lcd.getCursorY() + 9);
        lcd.println(project);

        lcd.setCursor(textAlign(CENTER_X, &creator_name), lcd.getCursorY() + 8);
        lcd.println(creator_name);

        lcd.setCursor(textAlign(CENTER_X, &creator_surname), lcd.getCursorY());
        lcd.println(creator_surname);

        lcd.display();
    }

public:
    void showScreen(){
        switch(active_page){
            case 0:
                firstScr();
                break;
            case 1:
                secondScr();
                break;
            case 2:
                thirdScr();
                break;
            case 3:
                aboutScr();
                break;
        }
    }

};

#endif
