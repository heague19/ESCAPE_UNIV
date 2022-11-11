#pragma once
#include<string>
using namespace std;
class Item
{
public:
	int id;
	string name;
	bool singleUse;
	bool combined;
	pair<int, int> material;
	//��� �� ������ �Լ�
	void (*func)();
	Item();
	Item(int id, string name, bool singleUse, void (*func)() = []() {return;});
	Item(int id, string name, bool singleUse, pair<int, int> material, void (*func)() = []() {return;});
};