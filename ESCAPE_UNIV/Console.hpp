#pragma once
#include <Windows.h>
#include <string>
class Console {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	Console();
	Console(HANDLE console);
	COORD GetCurrentCursorPos();
	bool SetCurrentCursorPos(int x, int y);
	bool SetConsoleSize(int width, int height);
	bool RemoveCursor();
};