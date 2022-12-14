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
	void Constructor_Inventory_Boundary();// 인벤토리 창 제작 함수
	void Constructor_Item_List(); // 아이템 목록표 제작 함수
	void Print_Item_List(BoxUI&,	 vector<string>);
	//인벤토리 접근 시 선택된 아이템 표시용
	void Print_Item_List(BoxUI&,	 vector<string>,	 int,	 int);
	
	void Constructor_Explainer();
	void Constructor_Exit(bool flag);
};

