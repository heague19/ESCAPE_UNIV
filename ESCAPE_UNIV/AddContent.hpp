#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "GameTool.hpp"
using namespace std;

void AddContentsString(BoxUI &box, string contents);
// 문자열 입력 입니다. 각 box 클래스 내에 content 내용을 담았고 거기에 필요한
// 내용을 담는 함수입니다. 원하시는 box를 두시고 쓰시고 싶은 내용을 옆에 작성하시면
// 됩니다. 
void PrintText(BoxUI box);
// 작성하신 내용을 박스 내부에 정렬하여 출력하는 함수 입니다.
// 버그가 발생하는데 이는 맵과 NPC 추적에 있어서 무언가 겹치는 부분이 생겨 
// 만들어지는 것 같아 맵과 플레이어 이동 NPC등이 완성되면 한 번더 봐야 
// 될것 같습니다. 