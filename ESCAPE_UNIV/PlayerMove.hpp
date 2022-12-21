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
    ItemManager& itemmanager;
    enum Trans { M_UP,M_DOWN,M_LEFT,M_RIGHT };
    int state = 0;// 플레이어 충돌 상태 변수 by 이해규 
    //vector<vector<int>>::iterator mapdata;

public:
    //이동 주기와 이동주기 체크용 타이머
    const double moveRate = 0.2;
    double moveTimer = 0.0;
    COORD* NPCPos;
    PlayerMove(MapManager&,ItemManager&);
    void down();
    void up();
    void left();
    void right();
    void ShowPlayer();
    void DeletePlayer();
    //int DetectCollision(int, int);
    //void getkey();
    //void Move();
    //플레이어 좌표상 위치 반환
    COORD GetPos();
    int ItemGetChecker(int, int);
    int MoveBox(int,int,Trans); //박스 밀기
    void Setpos(int, int);
};
