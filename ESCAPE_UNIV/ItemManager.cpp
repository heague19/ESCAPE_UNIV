#include "ItemManager.hpp"
ItemManager::ItemManager(Inventory& inventory):inventory(inventory) {
	InitItemData();
}
Item ItemManager::GetItemData(int id) {
	if(id<itemData.size())
		return itemData[id];
	return Item();
}
Item ItemManager::GetItemData(string name) {
	auto data = itemDictionary.find(name);
	if (data != itemDictionary.end())return data->second;
	return Item();
}
bool ItemManager::FindItem(int id) {
	if (id >= itemData.size()) return false; // id ���� ������� üũ. ���ϸ� ����.
	auto item = lower_bound(items.begin(),	 items.end(),	 itemData[id],	 [](const Item& a,	 const Item& b) {return a.id < b.id; });
	if (item == items.end())return false;
	if (item->id == id)return true;
	return false;
}
bool ItemManager::DeleteItem(int id) {
	if (id >= itemData.size()) return false;
	auto item = lower_bound(items.begin(),	 items.end(),	 itemData[id],	 [](const Item& a,	 const Item& b) {return a.id < b.id; });
	if (item == items.end())return false;
	if (item->id == id) {
		items.erase(item);
		return true;
	}
	return false;
}
void ItemManager::InitItemData() {
	itemData.push_back(Item(0,	 "��",	 true));
	itemData.push_back(Item(1, "��2", true));
	itemData.push_back(Item(2,	 "4������",	 false,	 []() {ChatDialog::PrintMessage("�׽�Ʈ �ؽ�Ʈ"); }));
	itemData.push_back(Item(3,	 "�������̽�",	 false,	 []() {ChatDialog::PrintMessage("������ ���̽��̴�.\n���δ� ����ִ�."); }));
	itemData.push_back(Item(4, "5������", true, {14,15}, []() {ChatDialog::PrintMessage("�콼 ������ ���� ������ ������!"); }));
	itemData.push_back(Item(5,	 "��ġ",	 false));
	itemData.push_back(Item(6,	 "����",	 false,	 []() {ChatDialog::PrintMessage("���� ���� �� �ִ� �����̴�.\n�׳� ����ϱ� ������ �� ����."); }));
	itemData.push_back(Item(7,	 "������",	 false));
	itemData.push_back(Item(8,	 "3������",	 true));
	itemData.push_back(Item(9,	 "��������",	 false,	 {3,	6},	 []() {ChatDialog::PrintMessage("���� ���� �����̴�."); }));
	itemData.push_back(Item(10,	 "2������",	 false));
	itemData.push_back(Item(11,	 "2������",	 true));
	itemData.push_back(Item(12,	 "����",	 false,	 {7,	9}));
	itemData.push_back(Item(13,	 "6������",	 true,	 
		[]() {ChatDialog::PrintMessage("6������ ã�� �����̴�."); }));
	itemData.push_back(Item(14,	 "�콼����",	 true,	
		[]() {ChatDialog::PrintMessage("5������ ã�� �콼 �����̴�."); }));
	itemData.push_back(Item(15,	 "����",	 true));
	itemData.push_back(Item(16,	 "����",	 false,	 []() {ChatDialog::PrintMessage("�׽��z ���� ����"); }));
	itemData.push_back(Item(17, "2�� ��¥ ����", true));
	itemData.push_back(Item(18,	"������ ����", true, []() {ChatDialog::PrintMessage("������ ����"); }));
	itemData.push_back(Item(19, "ť��", true, []() {ChatDialog::PrintMessage("��� �ܴ��� ������̴�."); }));
	itemData.push_back(Item(20, "5�� ���� ȭ��� ����", true, []() {ChatDialog::PrintMessage("������ ���迴��."); }));

	for (int i = 0; i < itemData.size(); i++) {
		Item item = itemData[i];
		itemDictionary.insert({item.name,	 item});
		if (item.combined) {
			combinedList.insert({ item.material.first,	{item.material.second,	item.id} });
			combinedList.insert({ item.material.second,	{item.material.first,	item.id} });
		}
	}
}


bool ItemManager::CombineItem(int id1,	 int id2) {
	if (!FindItem(id1) || !FindItem(id2) || id1 >= itemData.size() || id2 >= itemData.size()) {
		ChatDialog::PrintMessage("�� ���� �������� ���� �� ����.");
		return false;
	}	
	auto data = combinedList.find(id1);
	if (data != combinedList.end()&&data->second.first==id2) {
		DeleteItem(id1);
		DeleteItem(id2);
		GetItem(data->second.second);
		ChatDialog::PrintMessage("���� ���ļ� "+itemData[data->second.second].name+"�� ȹ���ߴ�.");
		return true;
	}
	ChatDialog::PrintMessage("�� ���� �������� ���� �� ����.");
	return false;
}
bool ItemManager::UseItem(int num) {
	if (items.size()<num)return false;
	items[num-1].func();
	return true;
}
void ItemManager::GetItem(int id) {
	if (FindItem(id))return;
	items.push_back(itemData[id]);

	BoxUI Item_List(ITEM_LIST_WIDTH,	 ITEM_LIST_HEIGHT,	 ITEM_LIST_ORIGIN_X+2,	 ITEM_LIST_ORIGIN_Y);
	vector<string> datas;
	for (int i = 0; i < items.size(); i++)datas.push_back(items[i].name);
	inventory.Print_Item_List(Item_List,	 datas);
}