#include "Item.h"
void Item:: Constructor_Item_Boundary(int Item_board[])
{
    for (int x = 0; x < width + 2; x++)
    {
        GameBoard_Info[hegith+ 1][x] = 1;
    }

    for (int y = 0; y < height + 2; y++)
    {
        for (int x = 0; x < GBOARD_WIDTH + 2; x++)
        {
            if (x == 0 || x == (GBOARD_WIDTH + 1))
                GameBoard_Info[y][x] = 1;
        }
    }
    for (int y = 0; y < GBOARD_HEIGHT + 2; y++)
    {
        for (int x = 0; x < GBOARD_WIDTH + 2; x++)
        {
            SetCurrentCursorPos(GBOARD_ORIGIN_X + (x * 2), GBOARD_ORIGIN_Y + y);
            if (GameBoard_Info[y][x] == 1)
                printf("бс");
        }
    }

    SetCurrentCursorPos(0, 0);
}