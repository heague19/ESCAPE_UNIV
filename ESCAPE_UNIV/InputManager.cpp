#include "InputManager.hpp"
InputManager::InputManager(PlayerMove& playerMove,Timer& timer,MapManager& mapManager,ItemManager& itemManager)
    :playerMove(playerMove),timer(timer), mapManager(mapManager), itemManager(itemManager) {

}
void InputManager::Input() {
    playerMove.moveTimer += timer.GetDeltaTime();
    if (playerMove.moveTimer >= playerMove.moveRate) {
        if (GetAsyncKeyState(VK_W) & 0x8000) {
            playerMove.up();
            playerMove.moveTimer = 0;
        }
        if (GetAsyncKeyState(VK_A) & 0x8000) {
            playerMove.left();
            playerMove.moveTimer = 0;
        }
        if (GetAsyncKeyState(VK_S) & 0x8000) {
            playerMove.down();
            playerMove.moveTimer = 0;
        }
        if (GetAsyncKeyState(VK_D) & 0x8000) {
            playerMove.right();
            playerMove.moveTimer = 0;
        }
        if (playerMove.GetPos().X == playerMove.NPCPos.X && playerMove.GetPos().Y == playerMove.NPCPos.Y)
            GameOver::GAMEOVERPrint();
    }

    for (int i = 0x31; i <= 0x39; i++)
        if (GetAsyncKeyState(i) & 0x8000)
            itemManager.UseItem(i - 0x30);

    if (GetAsyncKeyState(VK_P) & 0x8000) {
        if (!flag_p) {
            mapManager.ReBox();
            mapManager.remap();
            mapManager.DisplayMap();
        }
        flag_p = true;
    }
    else flag_p = false;
}