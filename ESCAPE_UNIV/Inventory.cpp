#include "Inventory.hpp"
using namespace std;
Console console;
vector<string> vector_s;
void Inventory::Constructor_All_Init_Inventory()
{
    Constructor_Inventory_Boundary();
    Constructor_Item_List();
    Constructor_Explainer();

    //Constructor_Player_State_HP_Bar();
    //Constructor_Player_State_Stamina_Bar();
}

void Inventory:: Constructor_Inventory_Boundary()
{
    BoxUI Main_Inventory(INVENTORY_WIDTH, INVENTORY_HEIGTH, INVENTORY_ORIGIN_X, INVENTORY_ORIGIN_Y);
    Main_Inventory.ConstructorBox();
}

void Inventory:: Constructor_Item_List()
{
    SelectCursorColor(2, 2, 2);// ��Ʈ ���� �����Լ� 
    BoxUI Item_List(ITEM_LIST_WIDTH,ITEM_LIST_HEIGHT,ITEM_LIST_ORIGIN_X,ITEM_LIST_ORIGIN_Y); 
    Item_List.ConstructorBox();
    InitCursorColor();// ��Ʈ ���� �ʱ�ȭ �Լ�

    Print_Item_List(Item_List,vector_s); // ���� �Լ� ����Ʈ ��� �Լ�
    //vector_s�� �ʿ��� Vector<string> ���� ������ ��
    
}

void Inventory::Constructor_Explainer()
{/*
    Box Explainer(EXPLAINER_WIDTH, EXPLAINER_HEIGHT, EXPLAINER_ORIGIN_X, EXPLAINER_ORIGIN_Y);
    Explainer.ConstructorBox();
    AddContentsString(Explainer,
        "W:������ �̵�  A:�������� �̵�  S:�ڷ� �̵�  D:���������� �̵�");
    PrintText(Explainer);
    */
}

void Inventory::Print_Item_List(BoxUI &List,vector<string> Item)
{
    Console console;
    int x=1, y=1;
    if (Item.empty()) // ���� ���� Ȯ�� ���� �Լ�
        return;
    else
    {
        for (int i = 0; i < Item.size(); i++)
        {
            console.SetCurrentCursorPos(List.SInit_X + x, List.SInit_Y + y);
            cout << i+1<<". " <<Item[i];// Info�� �˰� �ִٴ� �����Ͽ� �� �׸� �ڽ��� ����Ʈ ���
            y++;
        }
    }
}
