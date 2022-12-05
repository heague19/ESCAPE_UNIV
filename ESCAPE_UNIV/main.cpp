#include <iostream>
#include "GameManager.hpp"
#include "GameOver.h"

using namespace std;
int main() {
    Console console;
    console.SetConsoleSize(150, 40);
    
    //INTROPrint();
    
    {

        try {
            GameManager::Instance().MainLoop();
        }
        catch (const char* str) {
            cout << str;
            getchar();
        }
    }

    GameOver::GAMEOVERPrint();
    
    return 0;
}