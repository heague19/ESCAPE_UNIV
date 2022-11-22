#include "BoxUI.hpp"
#include "Inventory.hpp"

using namespace std;

BoxUI::BoxUI(int w, int h, int X, int Y) 
{
    width = w;
    height = h;
    SInit_X = X;
    SInit_Y = Y;
    content = " ";

    // Box Info �迭 ����
    Info = new int *[height+2];
    for (int j = 0; j < height+2; j++)
        Info[j] = new int[width+2];

    // Box Info �迭 Data ����
    for (int x = 0; x < width + 2; x++)
    {
    Info[height + 1][x] = 1;
    Info[0][x] = 1;
    }// ��, �Ʒ� �׵θ� ������ �迭 1 ����

    for (int y = 1; y < height + 1; y++)
    {
        for (int x = 0; x < width + 2; x++)
        {
            if (x == 0 || x == (width + 1))
                Info[y][x] = 1;
            else
                Info[y][x] = 0;
            
        }
    }// �翷 �׵θ� ������ �迭 1 ����
}

void BoxUI::ConstructorBox()
{
    console.SetCurrentCursorPos(SInit_X, SInit_Y);
    
    for (int y = 0; y < height + 2; y++)
    {
        for (int x = 0; x < width + 2; x++)
        {// �ش� �迭�� �°� �� ����Ʈ ���� ���� ��� 
            console.SetCurrentCursorPos(SInit_X + (x * 2), SInit_Y + y);
            if (y == 0 && x == 0)
                cout << "��";
            else if (y == 0 && x == width + 1)
                cout << "��";
            else if (y == height + 1 && x == 0)
                cout << "��";
            else if (y == height + 1 && x == width + 1)
                cout << "��";
            else if (Info[y][x] == 1 && !(y == height + 1 || y == 0))
                cout << "��";
            else if (Info[y][x] == 1 && (y == height + 1 || y == 0))
                cout << "��";
        }
    }

    console.SetCurrentCursorPos(0, 0);
}

