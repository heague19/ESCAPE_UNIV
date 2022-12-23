#include "ChatDialog.hpp"
#include <stdio.h>
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

int ChatDialog::InputMessage()
{
	
	int password;
	Console console;
	console.SetCurrentCursorPos(DIALOG_ORIGIN_X + 2, DIALOG_ORIGIN_Y + 1);
	cin >> password;
	return password;
}