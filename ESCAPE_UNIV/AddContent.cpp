#include "AddContent.hpp"

void AddContentsString(Box &box, string contents)
{
	box.content = contents;
}

void PrintContentsString(Box box)
{
	Console console;
	int cnt = 0;
	char* adrress = &box.content[0];
	char* Space_Point;

	for (int y = 1; y < box.height+2; y++)
	{
		for (int x = 1; x < (box.width + 2)*2; x++)
		{
			console.SetCurrentCursorPos(box.SInit_X + x, box.SInit_Y + y);
			if (*adrress == ' ')
				Space_Point = adrress;
			cout << *adrress;
			adrress++;
		}
	}
}
