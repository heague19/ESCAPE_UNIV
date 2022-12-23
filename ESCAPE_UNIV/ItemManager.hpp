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
//item ������
class ItemManager
{
private:
	//������ ����
	vector<Item> itemData;
	map<string, Item> itemDictionary;
	//������ ������ ����Ʈ
	map<int, pair<int, int>> combinedList;
	Inventory& inventory;
	
public:
	//���� ���ϰ� �ִ� ������
	vector<Item> items;
	ItemManager(Inventory& inventory);
	//������ ���� ��������(�����Ϳ���)
	Item GetItemData(int id);
	Item GetItemData(string name);

	//���� ���ϰ� �ִ� �����ۿ��� Ž��
	bool FindItem(int id);
	//���� ������ �ִ� �����ۿ��� ����
	bool DeleteItem(int id);
	//������ ������ �ʱ� ����
	void InitItemData();

	//������ ����
	bool CombineItem(int id1,int id2);
	//������ ���
	bool UseItem(int num);
	//������ ȹ��
	void GetItem(int id);
	bool usesit = false;
};