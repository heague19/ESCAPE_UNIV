#pragma once
#include "Cursor_Function.h"
#define WIDHT 25
#define HEIGTH 40
class Item
{

public:
	int width = 25, height = 40;
	int Item_Board[HEIGTH + 2][WIDHT + 2];//? ���� ������ ���
	void Constructor_Item_Boundary();
	void Constructor_Item_Boundary(int Item_board[]);
};

