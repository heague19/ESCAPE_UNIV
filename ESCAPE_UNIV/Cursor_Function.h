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
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // �ڵ� �ο� �Լ� 
}

COORD GetCurrentCursorPos(void)
{
    COORD curPoint;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); //�ڵ� �ο� �Լ� 
    curPoint.X = curInfo.dwCursorPosition.X;//���� ��ġ X ��ǥ ���� 
    curPoint.Y = curInfo.dwCursorPosition.Y;//���� ��ġ Y ��ǥ ���� 

    return curPoint;
}

void RemoveCursor(void)
{
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}