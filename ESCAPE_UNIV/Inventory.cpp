#include "Inventory.hpp"
#include "Console.hpp"
using namespace std;
void Inventory:: Constructor_Inventory_Boundary()
{
    Console console;
    for (int x = 0; x < WIDTH + 2; x++)
    {
        Inventory_Board[HEIGTH+ 1][WIDTH+2] = 1;
    }// ��, �Ʒ� �׵θ� ������ �迭 1 ����

    for (int y = 0; y < HEIGTH + 2; y++)
    {
        for (int x = 0; x < WIDTH + 2; x++)
        {
            if (x == 0 || x == (WIDTH + 1))
                Inventory_Board[y][x] = 1;
        }
    }// �翷 �׵θ� ������ �迭 1 ����

    for (int y = 0; y < HEIGTH + 2; y++)
    {
        for (int x = 0; x < WIDTH + 2; x++)
        {// �ش� �迭�� �°� �� ����Ʈ��� ���� ��� 
            console.SetCurrentCursorPos(INVENTORY_ORIGIN_X+ (x * 2), INVENTORY_ORIGIN_Y + y);
            if (y == 0 && x == 0)
                cout<<"��";
            else if (y == 0 && x == WIDTH + 1)
                cout<<"��";
            else if (y == HEIGTH + 1 && x == 0)
                cout<<"��";
            else if (y == HEIGTH + 1 && x == WIDTH + 1)
                cout<<"��";
            else if (Inventory_Board[y][x] == 1 && !(y == Inventory_Board[y][x] + 1 || y == 0))
                cout<<"��";
            else if (Inventory_Board[y][x] == 1 && (y == HEIGTH + 1 || y == 0))
                cout<<"��";
        }
    }

    console.SetCurrentCursorPos(0, 0);
}

void Constructor_Item_List()
{

}