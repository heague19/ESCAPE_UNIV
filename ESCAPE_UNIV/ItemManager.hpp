#pragma once
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include "Item.hpp"
#include "Inventory.hpp"
#include "BoxUI.hpp"
#include "ChatDialog.hpp"
using namespace std;
//item 관리용
class ItemManager
{
private:
	//아이템 정보
	vector<Item> itemData;
	map<string, Item> itemDictionary;
	//합쳐진 아이템 리스트
	map<int, pair<int, int>> combinedList;
	Inventory& inventory;
	
public:
	//현재 지니고 있는 아이템
	vector<Item> items;
	ItemManager(Inventory& inventory);
	//아이템 정보 가져오기(데이터에서)
	Item GetItemData(int id);
	Item GetItemData(string name);

	//현재 지니고 있는 아이템에서 탐색
	bool FindItem(int id);
	//현재 가지고 있는 아이템에서 제거
	bool DeleteItem(int id);
	//아이템 데이터 초기 설정
	void InitItemData();

	//아이템 조합
	bool CombineItem(int id1,int id2);
	//아이템 사용
	bool UseItem(int num);
	//아이템 획득
	void GetItem(int id);
	bool usesit = false;
};