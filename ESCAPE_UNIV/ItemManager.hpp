#pragma once
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include "Item.hpp"
using namespace std;
//item ������
class ItemManager
{
private:
	friend class Inventory;
	//������ ����
	vector<Item> itemData;
	map<string, Item> itemDictionary;
	//������ ������ ����Ʈ
	map<int, pair<int, int>> combinedList;
public:
	//���� ���ϰ� �ִ� ������
	vector<Item> items;
	ItemManager();
	//������ ���� ��������(�����Ϳ���)
	Item GetItemData(int id);
	Item GetItemData(string name);

	//���� ���ϰ� �ִ� �����ۿ��� Ž��
	bool FindItem(int id);
	//���� ������ �ִ� �����ۿ��� ����
	bool DeleteItem(int id);
	//������ ������ �ʱ� ����
	void InitItemData();

	bool CombineItem(int id1,int id2);
	bool UseItem(int id);
	void GetItem(int id);
};