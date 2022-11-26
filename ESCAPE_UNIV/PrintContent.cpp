#include "PrintContent.h"

void Print(string msg, BoxUI Area)
{
	Console console;
	string msgBuffer;
	istringstream iss(msg);
	int c = 0;
	for (int i = 0; i < Area.height; i++) {
		console.SetCurrentCursorPos(Area.SInit_X + 2, Area.SInit_Y + i + 1);
		for (int j = 0; j < Area.width * 2; j++)cout << " ";
		if (getline(iss, msgBuffer, '\n')) {
			console.SetCurrentCursorPos(Area.SInit_X + 2, Area.SInit_Y + i + 1);
			cout << msgBuffer;
		}
	}
}