#pragma once
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include "Item.hpp"
using namespace std;
//item 관리용
class ItemManager
{
private:
	friend class Inventory;
	//아이템 정보
	vector<Item> itemData;
	map<string, Item> itemDictionary;
	//합쳐진 아이템 리스트
	map<int, pair<int, int>> combinedList;
public:
	//현재 지니고 있는 아이템
	vector<Item> items;
	ItemManager();
	//아이템 정보 가져오기(데이터에서)
	Item GetItemData(int id);
	Item GetItemData(string name);

	//현재 지니고 있는 아이템에서 탐색
	bool FindItem(int id);
	//현재 가지고 있는 아이템에서 제거
	bool DeleteItem(int id);
	//아이템 데이터 초기 설정
	void InitItemData();

	bool CombineItem(int id1,int id2);
	bool UseItem(int id);
	void GetItem(int id);
};