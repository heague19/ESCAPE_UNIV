#pragma once
#define WIDTH 25
#define HEIGTH 40
class Item
{
public:

	int Item_Board[HEIGTH + 2][WIDTH + 2];//? ���� ������ ���
	void Constructor_Item_Boundary();
	void Constructor_Item_Boundary(int Item_board[]);
};

