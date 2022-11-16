#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Console.hpp"
#include "MapManager.hpp"
using namespace std;

class PlayerMove {
private:
    char model = { 9 };
    int term_pos_x =10;
    int term_pos_y =10;
    Console console;
public:
    PlayerMove();
    void down();
    void up();
    void left();
    void right();
    void ShowPlayer();
    void DeletePlayer();
    bool DetectCollision(int, int);
    void getkey();
    void Move();
};
