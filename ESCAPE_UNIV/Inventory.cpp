#include "Inventory.hpp"
using namespace std;
Console console;
vector<string> vector_s;
void Inventory::Constructor_All_Init_Inventory()
{
    Constructor_Inventory_Boundary();
    Constructor_Item_List();
    Constructor_Explainer();
}

void Inventory:: Constructor_Inventory_Boundary()
{
    BoxUI Main_Inventory(INVENTORY_WIDTH, INVENTORY_HEIGTH, INVENTORY_ORIGIN_X, INVENTORY_ORIGIN_Y);
    Main_Inventory.ConstructorBox();
}

void Inventory:: Constructor_Item_List()
{
    SelectCursorColor(DARK_GREEN);// ��Ʈ ���� �����Լ� 
    BoxUI Item_List(ITEM_LIST_WIDTH,ITEM_LIST_HEIGHT,ITEM_LIST_ORIGIN_X,ITEM_LIST_ORIGIN_Y); 
    Item_List.ConstructorBox();
    InitCursorColor();// ��Ʈ ���� �ʱ�ȭ �Լ�

    Print_Item_List(Item_List,vector_s); // ���� �Լ� ����Ʈ ��� �Լ�
    //vector_s�� �ʿ��� Vector<string> ���� ������ ��
    
}

void Inventory::Constructor_Explainer()
{
    BoxUI ExplainerBox(EXPLAINER_WIDTH,EXPLAINER_HEIGHT,EXPLAINER_ORIGIN_X,EXPLAINER_ORIGIN_Y);
    ExplainerBox.ConstructorBox();
    ExplainerBox.Print("W : �� A : �� S : �� D : ��");

    SelectCursorColor(DARK_BLUE);
    BoxUI EXIT(EXIT_WIDTH/2, EXIT_HEIGHT/2, EXIT_ORIGIN_X, EXIT_ORIGIN_Y+2);
    EXIT.ConstructorBox();
    EXIT.Print("EXIT");
    InitCursorColor();
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
            cout << i+1<<". " <<Item[i]<<"        ";// Info�� �˰� �ִٴ� �����Ͽ� �� �׸� �ڽ��� ����Ʈ ���
            y++;
        }
        console.SetCurrentCursorPos(List.SInit_X + x, List.SInit_Y + y);
        cout << "                   ";
    }
}
void Inventory::Print_Item_List(BoxUI& List, vector<string> Item, int select1, int select2)
{
    Console console;
    int x = 1, y = 1;
    if (Item.empty()) // ���� ���� Ȯ�� ���� �Լ�
        return;
    else
    {
        for (int i = 0; i < Item.size(); i++)
        {
            console.SetCurrentCursorPos(List.SInit_X + x, List.SInit_Y + y);
            if (select1 == i)SelectCursorColor(GREEN);
            if (select2 == i)SelectCursorColor(RED);
            cout << i + 1 << ". " << Item[i];// Info�� �˰� �ִٴ� �����Ͽ� �� �׸� �ڽ��� ����Ʈ ���
            y++;
            InitCursorColor();
        }
    }
}
