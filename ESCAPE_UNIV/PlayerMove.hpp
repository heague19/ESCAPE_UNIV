#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Console.hpp"
#include "MapManager.hpp"
#include "PartPos.hpp"
#include "ItemManager.hpp"

using namespace std;

class PlayerMove {
private:
    char model = { 9 };
    COORD pos,pox;   //콘솔좌표, 배열 좌표
    Console console;
    MapManager& Map;
    ItemManager itemmanager;
    enum Trans { M_UP,M_DOWN,M_LEFT,M_RIGHT };
    //vector<vector<int>>::iterator mapdata;
public:
    PlayerMove(MapManager&);
    void down();
    void up();
    void left();
    void right();
    void ShowPlayer();
    void DeletePlayer();
    int DetectCollision(int, int);
    void getkey();
    void Move();
    //플레이어 좌표상 위치 반환
    COORD GetPos();
    int MoveBox(int,int,Trans); //박스 밀기
    
};
