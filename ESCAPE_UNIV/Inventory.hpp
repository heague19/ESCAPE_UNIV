#pragma once
#include <iostream>


#define INVENTORY_ORIGIN_X 98
#define INVENTORY_ORIGIN_Y 2
#define WIDTH 25
#define HEIGTH 40

using namespace std; 

class Inventory
{
private:
	int Inventory_Board[HEIGTH + 2][WIDTH + 2];
	int List_Board[15][30];
	int HP_Bar[5];
	int Stamina_Bar[5];

public://? ���� ������ ���
	void Constructor_Inventory_Boundary();// ������â ���� �Լ�
	void Constructor_Item_List();
	void Constructor_Player_State_HP_Bar();
	void Constructor_Player_State_Stamina_Bar();
};

