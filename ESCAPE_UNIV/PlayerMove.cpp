#include "PlayerMove.hpp"
#include "Console.hpp"

PlayerMove::PlayerMove(MapManager& mapManager,ItemManager& itemManager) 
    :Map(mapManager),itemmanager(itemManager)
{
    pos.X = 10; pos.Y = 10; //�ܼ� ��ǥ
    pox.X = pos.X - MAP_ORIGIN_X / 2;
    pox.Y = pos.Y - MAP_ORIGIN_Y;
    console.SetCurrentCursorPos(pox.X, pox.Y);
    ShowPlayer();
}
void PlayerMove::Move() {
    getkey();
}

int PlayerMove::ItemGetChecker() {
    int objectid = Map.GetMapAt(pox);
    if ((objectid - 1) / 100 == 1) {
        itemmanager.GetItem(objectid - 100);
        Map.ClearPos(pox);
        //Map.ChangeMap(1);
        return 1;
    }
    else if ((objectid - 1) / 100 >= 2) {
        int id = objectid - 200;
        id = id < 100 ? id : id - 100;
        switch (objectid) {
        case 313:
            Map.ChangeMap(1);
            pox.X--;
            pos.X--;
            break;
        case 351:
            Map.ChangeMap(0);
            pox.X--;
            pos.X--;
            break;
        default:
            if (!itemmanager.FindItem(id)) return 0;
        }
        return 1;
        
        //item.DeleteItem(id);
    }
}

void PlayerMove::down() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    pox.Y++;
    if (Map.GetMapAt(pox) && !ItemGetChecker()) {
        if (!MoveBox(pox.X, pox.Y, M_DOWN)) {
            pox.Y--;
            return;
        }
    }
    DeletePlayer();
    pos.Y++;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::up() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    pox.Y--;
    if (Map.GetMapAt(pox) && !ItemGetChecker()) {
        if (!MoveBox(pox.X, pox.Y, M_UP)) {
            pox.Y++;
            return;
        }
    }
    ItemGetChecker();
    DeletePlayer();
    pos.Y--;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::left() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    pox.X--;
    if (Map.GetMapAt(pox) && !ItemGetChecker()) {
        if (!MoveBox(pox.X, pox.Y, M_LEFT)) {
            pox.X++;
            return;
        }
    }
    ItemGetChecker();
    DeletePlayer();
    pos.X -= 1;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::right() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    pox.X++;
    if (Map.GetMapAt(pox) && !ItemGetChecker()) {
        if (!MoveBox(pox.X, pox.Y, M_RIGHT)) {
            pox.X--;
            return;
        }
    }
    ItemGetChecker();
    DeletePlayer();
    pos.X += 1;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::ShowPlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(curPos.X*2, curPos.Y);
    printf("��");
    console.SetCurrentCursorPos(curPos.X*2, curPos.Y);
};

void PlayerMove::DeletePlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(pos.X*2, pos.Y);
    cout << "  ";
    console.SetCurrentCursorPos(pos.X*2, pos.Y);
}

void PlayerMove::getkey() {
    for (int i = 0; i < 20; i++) {
        if (_kbhit() != 0) {
            auto key = _getch();
            //������ ��� �κ�
            //�ٸ� ������ �Է� ������ ���� ���ɼ� �־ ���� ����
            //���߿� inputManager ���� �Է� �ű⼭�� �޴°� ������
            if (key >= '1' && key <= '9')itemmanager.UseItem(key - '0');
            switch (key) {
            case 'w': up(); break;
            case 's': down(); break;
            case 'a': left(); break;
            case 'd': right(); break;
            case 'p': Map.ReBox(); Map.remap(); Map.DisplayMap(); break;
            //�ڽ� ����� �� �ٽ� �ҷ����� �ٽ� �׸�
            // �̷��� ���ϸ� �����Ÿ�����,,
            }
        }
    }
}


/*int PlayerMove::DetectCollision(int x, int y) {
    COORD pos_;
    pos_.X = x;
    pos_.Y = y;
    if (!Map.CheckMap(pos_))
        return 1;
    return 0;
}*/
COORD PlayerMove::GetPos() {
    return pox;
}

int PlayerMove::MoveBox(int y, int x, Trans m) {

    auto mapdata = Map.GetMap();
    COORD BOX_POS;
    BOX_POS.X = x; BOX_POS.Y = y;

    int width = mapdata[0].size();
    int height = mapdata.size();
    /*
    if (pox.X >= width || pox.X < 0 || pox.Y >= height || pox.Y < 0) {
        return 0;
    }*/
    if (mapdata[x][y] == 100) { //�ڽ� Ȯ��
        switch (m)
        {
        case M_DOWN:
            BOX_POS.X++; break;
        case M_UP:
            BOX_POS.X--; break;
        case M_LEFT: 
            BOX_POS.Y--; break;
        case M_RIGHT: 
            BOX_POS.Y++; break;
        }
        
        if (mapdata[BOX_POS.X][BOX_POS.Y]!=0  || BOX_POS.X >= height-1 || BOX_POS.X < 1 || BOX_POS.Y >= width-1|| BOX_POS.Y < 1 /* || (BOX_POS.X != npc.NPCPathFind().X && BOX_POS.Y != npc.NPCPathFind().Y)*/) {  //�ڽ��� �̵� �������� �˻�
            return 0;
        }
        mapdata[BOX_POS.X][BOX_POS.Y] = 100; //�ڽ� ��ġ ����
        mapdata[x][y] = 0;
        Map.SetMap(mapdata);
        Map.DisplayMap();
        //cout << "X="+BOX_POS.X <<"Y="+ BOX_POS.Y;
        return 1;
    }
    else {
        return 0;
    }
}