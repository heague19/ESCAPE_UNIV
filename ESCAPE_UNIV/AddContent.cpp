#include "AddContent.hpp"

void AddContentsString(BoxUI &box, string contents)// 단어 입력 함수
{
	box.content = contents;
}

void PrintText(BoxUI box) // 단어 출력 함수 
{
	Console console;
	int cnt = 0;
	char* address = &box.content[0];
	char empty_Point,* Space_Point=&empty_Point;
	int memory_x=1, memory_y=1;

	for (int y = 1; y < box.height+2; y++)
	{
		for (int x = 2; x < (box.width + 2)*2-2; x++)
		{
			console.SetCurrentCursorPos(box.SInit_X + x, box.SInit_Y + y);
			if (*address == ' ')
			{
				Space_Point = address;
				memory_x = x;
				memory_y = y;
			}
			cout << *address;
			address++;
		}
		if (*address != ' ' && *(--address) != ' ')
		{
			for (int _x = 0; _x < (box.width + 2) * 2-1 - memory_x; _x++)
			{
				console.SetCurrentCursorPos(box.SInit_X + memory_x+_x, box.SInit_Y + memory_y);
				cout << ' ';
			}
			address = Space_Point;
		}
	}
}
