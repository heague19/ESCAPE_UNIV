#pragma once
#include <iostream>
#include <vector>
#include "GameTool.hpp"
#include "PartPos.hpp"
#include "ItemManager.hpp"
using namespace std; 

class Inventory
{
public:
	void Constructor_All_Init_Inventory();
	void Constructor_Inventory_Boundary();// �κ��丮 â ���� �Լ�
	void Constructor_Item_List(); // ������ ���ǥ ���� �Լ�
	void Print_Item_List(BoxUI&, vector<string>);
	//�κ��丮 ���� �� ���õ� ������ ǥ�ÿ�
	void Print_Item_List(BoxUI&, vector<string>, int, int);
	
	void Constructor_Explainer();
	void Constructor_Exit(bool flag);
};

