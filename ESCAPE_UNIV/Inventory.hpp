#pragma once
#include <iostream>
#include "GameTool.hpp"
#include "PartPos.hpp"
using namespace std; 

class Inventory
{
public:
	void Constructor_All_Init_Inventory();
	void Constructor_Inventory_Boundary();// �κ��丮 â ���� �Լ�
	void Constructor_Item_List(); // ������ ���ǥ ���� �Լ�
	void Constructor_Explainer();
};

