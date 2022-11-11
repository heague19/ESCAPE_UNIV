#include "Item.hpp"
Item::Item() {
	id = -1;
	name = "";
	singleUse = false;
	combined = false;
	material = { -1,-1 };
}
Item::Item(int id, string name, bool singleUse, void (*func)()) {
	this->id = id;
	this->name = name;
	this->singleUse = singleUse;
	combined = false;
	material = { -1,-1 };
	this->func = func;
}
Item::Item(int id, string name, bool singleUse, pair<int, int> material, void (*func)()) {
	this->id = id;
	this->name = name;
	this->singleUse = singleUse;
	this->combined = true;
	this->material = material;
	this->func = func;
}