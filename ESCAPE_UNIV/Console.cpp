#include "Console.hpp"
using namespace std;
Console::Console() {

}
Console::Console(HANDLE console) : Console() {
	this->console = console;
}
COORD Console::GetCurrentCursorPos() {
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(console, &curInfo);
	return { curInfo.dwCursorPosition.X , curInfo.dwCursorPosition.Y };
}
bool Console::SetCurrentCursorPos(int x, int y) {
	return SetConsoleCursorPosition(console, { (short)x, (short)y });
}
bool Console::SetConsoleSize(int width, int height) {
	string cmd;
	cmd += "mode con:cols=" + to_string(width) + " lines=" + to_string(height);
	return !system(cmd.c_str());
}
bool Console::RemoveCursor() {
	CONSOLE_CURSOR_INFO curInfo;
	if (!GetConsoleCursorInfo(console, &curInfo)) return false;
	curInfo.bVisible = 0;
	return SetConsoleCursorInfo(console, &curInfo);
}