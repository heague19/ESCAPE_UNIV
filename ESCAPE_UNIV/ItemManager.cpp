#include "ItemManager.hpp"
ItemManager::ItemManager() {
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
	auto item = lower_bound(items.begin(), items.end(), itemData[id], [](const Item& a, const Item& b) {return a.id < b.id; });
	if (item == items.end())return false;
	if (item->id == id)return true;
	return false;
}
bool ItemManager::DeleteItem(int id) {
	auto item = lower_bound(items.begin(), items.end(), itemData[id], [](const Item& a, const Item& b) {return a.id < b.id; });
	if (item == items.end())return false;
	if (item->id == id) {
		items.erase(item);
		return true;
	}
	return false;
}
void ItemManager::InitItemData() {
	itemData.push_back(Item(0, "³í¹®", true));
	itemData.push_back(Item(1, "5Ãş¿­¼è", true));
	itemData.push_back(Item(2, "4ÃşÂÊÁö", false, []() {std::cout << "Å×½ºÆ® ÅØ½ºÆ®"; }));
	itemData.push_back(Item(3, "·£ÅÏÄÉÀÌ½º", false));
	itemData.push_back(Item(4, "4Ãş¿­¼è", true));
	itemData.push_back(Item(5, "¸ÁÄ¡", false));
	itemData.push_back(Item(6, "½ÉÁö", false));
	itemData.push_back(Item(7, "¶óÀÌÅÍ", false));
	itemData.push_back(Item(8, "3Ãş¿­¼è", true));
	itemData.push_back(Item(9, "²¨Áø·£ÅÏ", false, {3,6}));
	itemData.push_back(Item(10, "2ÃşÂÊÁö", false));
	itemData.push_back(Item(11, "2Ãş¿­¼è", true));
	itemData.push_back(Item(12, "·£ÅÏ", false, {7,9}));
	
	for (int i = 0; i < itemData.size(); i++) {
		Item item = itemData[i];
		itemDictionary.insert({item.name, item});
		if (item.combined) {
			combinedList.insert({ item.material.first,{item.material.second,item.id} });
			combinedList.insert({ item.material.second,{item.material.first,item.id} });
		}
	}
}

bool ItemManager::CombineItem(int id1, int id2) {
	if (!FindItem(id1) || !FindItem(id2)||id1>=itemData.size()||id2>=itemData.size())return false;
	auto data = combinedList.find(id1);
	if (data != combinedList.end()) {
		DeleteItem(id1);
		DeleteItem(id2);
		GetItem(data->second.second);
		return true;
	}
	return false;
}
bool ItemManager::UseItem(int id) {
	if (!FindItem(id)||id>=itemData.size())return false;
	itemData[id].func();
	return true;
}
void ItemManager::GetItem(int id) {
	if (FindItem(id))return;
	items.push_back(itemData[id]);
}