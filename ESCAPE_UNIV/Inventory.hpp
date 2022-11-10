#pragma once
#include <iostream>

#define GAP_X 10
#define GAP_Y 2
#define INVENTORY_ORIGIN_X 104
#define INVENTORY_ORIGIN_Y 2

#define _HP 15
#define _STAMINA 15

#define WIDTH 20
#define HEIGTH 35


using namespace std; 

class Inventory
{
private:
	int Ragulate_x, Regulate_y;
	int Ragulate_Gap_X, Regulate_Gap_Y;
private:
	int Inventory_Board[HEIGTH + 2][WIDTH + 2];
	int List_Board[15][30];
	int HP[_HP];
	int Stamina[_STAMINA];

public://? ���� ������ ���
	void Constructor_All_Init_Inventory();
	void Constructor_Inventory_Boundary();// �κ��丮 â ���� �Լ�
	void Constructor_Item_List(); // ������ ���ǥ ���� �Լ�
	void Constructor_Player_State_HP_Bar(); //�÷��̾� HP Bar ���� �Լ�
	void Constructor_Player_State_Stamina_Bar(); // �÷��̾� Stamina Bar ���� �Լ�
};

