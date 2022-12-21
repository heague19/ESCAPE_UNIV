#include "MapFloorUI.hpp"

MapFloorUI::MapFloorUI() {

}
void MapFloorUI::Show(int mapid) {
	int floor;
	if (mapid <= 0)floor = 6;
	else if (mapid <= 5)floor = 5;
	else if (mapid <= 11)floor = 4;
	else floor = 3;
	Console console;
	console.SetCurrentCursorPos(EXPLAINER_ORIGIN_X+2,EXPLAINER_ORIGIN_Y+9);
	cout << "ÇöÀç Ãþ: " << floor;
}