#include <iostream>
#include "GameManager.hpp"
using namespace std;
int main() {
    try {
        GameManager::Instance().MainLoop();
    } catch (const char* str) {
        cout << str;
        getchar();
    }
    return 0;
}