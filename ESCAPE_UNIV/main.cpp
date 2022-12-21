#include <iostream>
#include "GameManager.hpp"
#include "GameOver.h"
#include "InputManager.hpp"

using namespace std;
int main() {
    Console console;
    console.SetConsoleSize(150, 40);
    //InputManager main_input;
    
    //INTRO::INTROPrint();

        //if (INTRO::Iflag)
        //{
            //{
    /*
                while (true)
                {
                    main_input.Input();
                }
                */
                try {
                    GameManager::Instance().MainLoop();
                }
                catch (const char* str) {
                    cout << str;
                    getchar();
                }
            //}
        
        
        //}

   

    
        GameOver::GAMEOVERPrint();
    
    return 0;
}