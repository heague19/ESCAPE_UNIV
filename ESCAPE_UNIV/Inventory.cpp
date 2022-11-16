#include "Inventory.hpp"

using namespace std;
Console console;

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
    Box Main_Inventory(INVENTORY_WIDTH, INVENTORY_HEIGTH, INVENTORY_ORIGIN_X, INVENTORY_ORIGIN_Y);
    Main_Inventory.ConstructorBox();
}

void Inventory:: Constructor_Item_List()
{
    SelectCursorColor(2, 2, 2);
    Box Item_List(ITEM_LIST_WIDTH,ITEM_LIST_HEIGHT,ITEM_LIST_ORIGIN_X,ITEM_LIST_ORIGIN_Y); 
    Item_List.ConstructorBox();
    InitCursorColor();
    
}

void Inventory::Constructor_Explainer()
{
    Box Explainer(EXPLAINER_WIDTH, EXPLAINER_HEIGHT, EXPLAINER_ORIGIN_X, EXPLAINER_ORIGIN_Y);
    Explainer.ConstructorBox();
}
