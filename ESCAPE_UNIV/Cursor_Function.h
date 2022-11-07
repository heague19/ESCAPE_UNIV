#pragma once
#include <conio.h>
#include <Windows.h>
#include <stdio.h> 
#include <time.h>

void SetCurrentCursorPos(int, int);
COORD GetCurrentCursorPos(void);
void RemoveCursor(void);

void SetCurrentCursorPos(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 핸들 부여 함수 
}

COORD GetCurrentCursorPos(void)
{
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); //핸들 부여 함수 
    curPoint.X = curInfo.dwCursorPosition.X;//현재 위치 X 좌표 리턴 
    curPoint.Y = curInfo.dwCursorPosition.Y;//현재 위치 Y 좌표 리턴 

    return curPoint;
}

void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}