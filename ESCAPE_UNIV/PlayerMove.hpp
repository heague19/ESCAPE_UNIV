#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Console.hpp"
#include "MapManager.hpp"
#include "PartPos.hpp"

using namespace std;

class PlayerMove {
private:
    char model = { 9 };
    COORD pos;
    Console console;
    MapManager Map;
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
    //플레이어 좌표상 위치 반환
    COORD GetPos();
};
