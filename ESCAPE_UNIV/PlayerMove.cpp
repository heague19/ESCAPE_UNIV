#include "PlayerMove.hpp"
#include "Console.hpp"

PlayerMove::PlayerMove(MapManager& mapManager, ItemManager& itemManager)
    :Map(mapManager), itemmanager(itemManager)
{
    Setpos(6, 10);
}

int PlayerMove::ItemGetChecker(int dy, int dx) { // ���ڴ� ���� �����̷��� �ϴ� ����
    int objectid = Map.GetMapAt(pox);
    if ((objectid - 1) / 100 == 1) {
        itemmanager.GetItem(objectid - 100);
        Map.ClearPos(pox);
        ChatDialog::PrintMessage(itemmanager.GetItemData(objectid - 100).name + "��(��) �����.");
        if (objectid == 113) {
            movenpc = true;
        }
        return 1;
    }
    else if ((objectid - 1) / 100 >= 2) {
        // �� �浹 �˻� �κ�
        //���ι��� 200�̰� ���� ���� 300���̱� ������ 200�̸� �״�� ���� 300�̸� 100�� �߰��� �� ���ش�.
        int id = objectid - 200;
        id = id < 100 ? id : id - 100;
        
        int beforemapId = Map.mapid;
        int mapId = Map.GetMapIdByRoomNumber(objectid % 100); // ���� �� ���̵�
        if (mapId >= 0) {
            movenpc = false;
            Map.ChangeMap(mapId);
            pox = Map.CalculateStartLocation(beforemapId, mapId, dy, dx);
        }
        else {
            if (!itemmanager.FindItem(id)) {
                ChatDialog::PrintMessage("���� ���� �����ִ�.");
                return 0;
            }
        }
        ChatDialog::PrintMessage("���� ���ȴ�.");
        return 1;
        
        //item.DeleteItem(id);
    }
}

void PlayerMove::down() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    DeletePlayer();
    pox.Y++;
    if (Map.GetMapAt(pox) && !ItemGetChecker(1, 0)) {
        if (!MoveBox(pox.X, pox.Y, M_DOWN)) {
            pox.Y--;
            ShowPlayer();
            return;
        }
    }
    pos.Y++;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::up() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    DeletePlayer();
    pox.Y--;
    if (Map.GetMapAt(pox) && !ItemGetChecker(-1, 0)) {
        if (!MoveBox(pox.X, pox.Y, M_UP)) {
            pox.Y++;
            ShowPlayer();
            return;
        }
    }
    pos.Y--;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
}
void PlayerMove::left() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    DeletePlayer();
    pox.X--;
    if (Map.GetMapAt(pox) && !ItemGetChecker(0, -1)) {
        if (!MoveBox(pox.X, pox.Y, M_LEFT)) {
            pox.X++;
            ShowPlayer();
            return;
        }
    }
    pos.X -= 1;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::right() {
    bool reshowmap = false;
    if (Map.GetMapAt(pox) > 200) reshowmap = true;
    DeletePlayer();
    pox.X++;
    if (Map.GetMapAt(pox) && !ItemGetChecker(0, 1)) {
        if (!MoveBox(pox.X, pox.Y, M_RIGHT)) {
            pox.X--;
            ShowPlayer();
            return;
        }
    }
    pos.X += 1;
    if (reshowmap) Map.DisplayMap();
    console.SetCurrentCursorPos(pos.X, pos.Y);
    ShowPlayer();
};
void PlayerMove::ShowPlayer() {
    //ChatDialog::PrintMessage(to_string(pox.X) + ", " + to_string(pox.Y));
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(pox.X * 2 + MAP_ORIGIN_X, pox.Y + MAP_ORIGIN_Y);
    printf("��");
    console.SetCurrentCursorPos(pox.X * 2 + MAP_ORIGIN_X, pox.Y + MAP_ORIGIN_Y);
};

void PlayerMove::DeletePlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(pox.X * 2 + MAP_ORIGIN_X, pox.Y + MAP_ORIGIN_Y);
    cout << "  ";
    console.SetCurrentCursorPos(pox.X * 2 + MAP_ORIGIN_X, pox.Y + MAP_ORIGIN_Y);
}
/*
* inputManager�� ��� ����
void PlayerMove::getkey() {
    for (int i = 0; i < 20; i++) {
        if (_kbhit() != 0) {
            auto key = _getch();
            ChatDialog::PrintMessage("");
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
*/

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
        if (BOX_POS.Y == NPCPos->X&&BOX_POS.X==NPCPos->Y)return 0;
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

void PlayerMove::Setpos(int x, int y) {
    pos.X = x; pos.Y = y; //�ܼ� ��ǥ
    pox.X = pos.X - MAP_ORIGIN_X / 2;
    pox.Y = pos.Y - MAP_ORIGIN_Y;
    console.SetCurrentCursorPos(pox.X, pox.Y);
    ShowPlayer();
}