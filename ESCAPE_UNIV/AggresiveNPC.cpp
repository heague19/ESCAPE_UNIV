#include "AggresiveNPC.hpp"
AggresiveNPC::AggresiveNPC() {

}
void AggresiveNPC::ShowNPC() {
	console.SetCurrentCursorPos(pos.X, pos.Y);
	cout << "จั";
}
void AggresiveNPC::DeleteNPC() {
	console.SetCurrentCursorPos(pos.X, pos.Y);
	cout << " ";
}
void AggresiveNPC::NPCMove(){
	COORD nextPos = NPCPathFind();
	NPCDetectCollision(nextPos);
}
COORD AggresiveNPC::NPCPathFind() {

}
bool AggresiveNPC::NPCDetectCollision(COORD nextPos) {

}