#pragma once
// 각 파트의 상수 상태를 여기에 기입해주세요 한번에 관리하기 위해서 입니다.
// 인벤토리 파트
#define INVENTORY_GAP_X 2
#define INVENTORY_GAP_Y 1

#define INVENTORY_ORIGIN_X 104
#define INVENTORY_ORIGIN_Y 2
#define INVENTORY_WIDTH 20
#define INVENTORY_HEIGTH 35

#define EXPLAINER_WIDTH (INVENTORY_WIDTH-INVENTORY_GAP_X)
#define EXPLAINER_HEIGHT 10
#define EXPLAINER_ORIGIN_X (INVENTORY_ORIGIN_X + INVENTORY_GAP_X)
#define EXPLAINER_ORIGIN_Y (INVENTORY_ORIGIN_Y + INVENTORY_GAP_Y + INVENTORY_GAP_Y + 22)

#define ITEM_LIST_WIDTH (INVENTORY_WIDTH-INVENTORY_GAP_X)
#define ITEM_LIST_HEIGHT (20)
#define ITEM_LIST_ORIGIN_X (INVENTORY_ORIGIN_X+INVENTORY_GAP_X)
#define ITEM_LIST_ORIGIN_Y (INVENTORY_ORIGIN_Y+INVENTORY_GAP_Y)
//인벤토리 파트

//맵 파트
#define MAP_ORIGIN_X 4
#define MAP_ORIGIN_Y 2

//대화창 파트
#define DIALOG_ORIGIN_X 2
#define DIALOG_ORIGIN_Y 25
#define DIALOG_WIDTH 46
#define DIALOG_HEIGHT 12