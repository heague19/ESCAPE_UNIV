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
	if (id >= itemData.size()) return false; // id 범위 벗어나는지 체크. 안하면 오류.
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
	itemData.push_back(Item(0,	 "논문",	 true));
	itemData.push_back(Item(1, "논문2", true));
	itemData.push_back(Item(2,	 "4층쪽지",	 false,	 []() {ChatDialog::PrintMessage("테스트 텍스트"); }));
	itemData.push_back(Item(3,	 "랜턴케이스",	 false,	 []() {ChatDialog::PrintMessage("랜턴의 케이스이다.\n내부는 비어있다."); }));
	itemData.push_back(Item(4, "5층열쇠", true, {14,15}, []() {ChatDialog::PrintMessage("녹슨 열쇠의 녹을 세제로 지웠다!"); }));
	itemData.push_back(Item(5,	 "망치",	 false));
	itemData.push_back(Item(6,	 "심지",	 false,	 []() {ChatDialog::PrintMessage("불을 붙일 수 있는 심지이다.\n그냥 사용하긴 위험할 것 같다."); }));
	itemData.push_back(Item(7,	 "라이터",	 false));
	itemData.push_back(Item(8,	 "3층열쇠",	 true));
	itemData.push_back(Item(9,	 "꺼진랜턴",	 false,	 {3,	6},	 []() {ChatDialog::PrintMessage("불이 꺼진 랜턴이다."); }));
	itemData.push_back(Item(10,	 "2층쪽지",	 false));
	itemData.push_back(Item(11,	 "2층열쇠",	 true));
	itemData.push_back(Item(12,	 "랜턴",	 false,	 {7,	9}));
	itemData.push_back(Item(13,	 "6층열쇠",	 true,	 
		[]() {ChatDialog::PrintMessage("6층에서 찾은 열쇠이다."); }));
	itemData.push_back(Item(14,	 "녹슨열쇠",	 true,	
		[]() {ChatDialog::PrintMessage("5층에서 찾은 녹슨 열쇠이다."); }));
	itemData.push_back(Item(15,	 "세제",	 true));
	itemData.push_back(Item(16,	 "쪽지",	 false,	 []() {ChatDialog::PrintMessage("테스틑 쪽지 내용"); }));
	itemData.push_back(Item(17, "2층 가짜 열쇠", true));
	itemData.push_back(Item(18,	"라이터 오일", true, []() {ChatDialog::PrintMessage("라이터 오일"); }));
	itemData.push_back(Item(19, "큐대", true, []() {ChatDialog::PrintMessage("길고 단단한 막대기이다."); }));
	itemData.push_back(Item(20, "5층 남자 화장실 열쇠", true, []() {ChatDialog::PrintMessage("숨겨진 열쇠였다."); }));

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
		ChatDialog::PrintMessage("이 둘은 합쳐지지 않을 것 같다.");
		return false;
	}	
	auto data = combinedList.find(id1);
	if (data != combinedList.end()&&data->second.first==id2) {
		DeleteItem(id1);
		DeleteItem(id2);
		GetItem(data->second.second);
		ChatDialog::PrintMessage("둘을 합쳐서 "+itemData[data->second.second].name+"를 획득했다.");
		return true;
	}
	ChatDialog::PrintMessage("이 둘은 합쳐지지 않을 것 같다.");
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