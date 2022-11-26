#include "ChatDialog.hpp"
ChatDialog::ChatDialog() {
	

}
void ChatDialog::Init() {
	
	BoxUI box(DIALOG_WIDTH,DIALOG_HEIGHT,DIALOG_ORIGIN_X,DIALOG_ORIGIN_Y);
	box.ConstructorBox();
}
void ChatDialog::PrintMessage(string msg) {
	Console console;
	string msgBuffer;
	istringstream iss(msg);
	int c = 0;
	for (int i = 0; i < DIALOG_HEIGHT ; i++) {
		console.SetCurrentCursorPos(DIALOG_ORIGIN_X + 2, DIALOG_ORIGIN_Y + i + 1);
		for (int j = 0; j < DIALOG_WIDTH*2; j++)cout << " ";
		if (getline(iss, msgBuffer, '\n')) {
			console.SetCurrentCursorPos(DIALOG_ORIGIN_X + 2, DIALOG_ORIGIN_Y + i + 1);
			cout << msgBuffer;
		}
	}
}