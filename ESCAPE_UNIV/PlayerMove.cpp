#include "PlayerMove.hpp"
#include "Console.hpp"

PlayerMove::PlayerMove()
{
    term_pos_x = 10;
    term_pos_y = 10;
    console.SetCurrentCursorPos(term_pos_x, term_pos_y);
    ShowPlayer();
}
void PlayerMove::Move() {
    getkey();
}

void PlayerMove::down() {
    if (!DetectCollision(term_pos_x, term_pos_y + 1)) {
        return;
    }
    DeletePlayer();
    term_pos_y++;
    console.SetCurrentCursorPos(term_pos_x, term_pos_y);
    ShowPlayer();
}
void PlayerMove::up() {
    if (!DetectCollision(term_pos_x, term_pos_y - 1)) {
        return;
    }
    DeletePlayer();
    term_pos_y--;
    console.SetCurrentCursorPos(term_pos_x, term_pos_y);
    ShowPlayer();
}
void PlayerMove::left() {
    if (!DetectCollision(term_pos_x - 2, term_pos_y)) {
        return;
    }
    DeletePlayer();
    term_pos_x -= 2;
    console.SetCurrentCursorPos(term_pos_x, term_pos_y);
    ShowPlayer();
};
void PlayerMove::right() {
    if (!DetectCollision(term_pos_x + 2, term_pos_y)) {
        return;
    }
    DeletePlayer();
    term_pos_x += 2;
    console.SetCurrentCursorPos(term_pos_x, term_pos_y);
    ShowPlayer();
};
void PlayerMove::ShowPlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(curPos.X, curPos.Y);
    cout << "¨Ü";
    console.SetCurrentCursorPos(curPos.X, curPos.Y);
};

void PlayerMove::DeletePlayer() {
    COORD curPos = console.GetCurrentCursorPos();
    console.SetCurrentCursorPos(term_pos_x, term_pos_y);
    cout << "  ";
    console.SetCurrentCursorPos(term_pos_x, term_pos_y);
}

void PlayerMove::getkey() {
    for (int i = 0; i < 20; i++) {
        if (_kbhit() != 0) {
            auto key = _getch();
            switch (key) {
            case 'w': up(); break;
            case 's': down(); break;
            case 'a': left(); break;
            case 'd': right(); break;
            }
        }
    }
}


bool PlayerMove::DetectCollision(int x, int y) {
    /*
    int i, j;
    int arrx = (x - GBOARD_ORIGIN_X) / 2;
    int arry = (y - GBOARD_ORIGIN_Y);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (gameBoardInfo[arry + j][arrx + i] == 1) {
                return 0;
            }
        }
    }*/
    return 1;
}
COORD PlayerMove::GetPos() {
    COORD pos;
    pos.X = term_pos_x/2-MAP_ORIGIN_X/2;
    pos.Y = term_pos_y-MAP_ORIGIN_Y;
    return pos;
}