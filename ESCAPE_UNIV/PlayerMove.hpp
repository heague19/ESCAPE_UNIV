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
    COORD pos,pox;   //�ܼ���ǥ, �迭 ��ǥ
    Console console;
    MapManager& Map;
    ItemManager& itemmanager;
    enum Trans { M_UP,M_DOWN,M_LEFT,M_RIGHT };
    int state = 0;// �÷��̾� �浹 ���� ���� by ���ر� 
    //vector<vector<int>>::iterator mapdata;

public:
    //�̵� �ֱ�� �̵��ֱ� üũ�� Ÿ�̸�
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
    //�÷��̾� ��ǥ�� ��ġ ��ȯ
    COORD GetPos();
    int ItemGetChecker(int, int);
    int MoveBox(int,int,Trans); //�ڽ� �б�
    void Setpos(int, int);
};
