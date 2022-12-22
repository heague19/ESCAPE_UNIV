#include <iostream>
#include "GameManager.hpp"
#include "GameOver.h"
#include "InputManager.hpp"
#include "INTRO.h"

using namespace std;
int main() {
    Console console;
    console.SetConsoleSize(150, 40);
    

    bool reflag = false;
    int selectflag = 0;

    while (true) {

    
                try {
                    GameManager::Instance().MainLoop();
                }
                catch (const char* str) {
                    cout << str;
                    getchar();
                }

   

        
        GameOver::GAMEOVERPrint();
        while (true)
        {
            if (GetAsyncKeyState(VK_DOWN) & 0x8000)
            {
                selectflag++;
                if (selectflag > 3)
                    selectflag = 0;
                reflag = true;
            }

            if (GetAsyncKeyState(VK_UP) & 0x8000)
            {
                selectflag--;
                if (selectflag < 0)
                    selectflag = 3;
                reflag = true;
            }

            if (reflag) {
                if (selectflag == 3)
                {
                    SelectCursorColor(GREEN);
                    BoxUI ENDING_EXIT(17, 5, 108, 29);
                    ENDING_EXIT.ConstructorBox();
                    ENDING_EXIT.Print("\n\n\             종료하기");
                    SelectCursorColor(WHITE);
                }

                else if (selectflag == 2)
                {
                    SelectCursorColor(GREEN);
                    BoxUI RE_MENU(17, 5, 108, 16);
                    RE_MENU.ConstructorBox();
                    RE_MENU.Print("\n\n\          메뉴로 돌아가기");
                    SelectCursorColor(WHITE);
                }

                
                else if (selectflag == 1)
                {
                    SelectCursorColor(GREEN);
                    BoxUI RE_START(17, 5, 108, 3);
                    RE_START.ConstructorBox();
                    RE_START.Print("\n\n\              재시작");
                    SelectCursorColor(WHITE);
                }
            }
            reflag = false;
            
        }
            
        
    }
    return 0;
}