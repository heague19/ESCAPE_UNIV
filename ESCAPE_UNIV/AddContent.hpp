#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "GameTool.hpp"
using namespace std;

void AddContentsString(BoxUI &box, string contents);
// ���ڿ� �Է� �Դϴ�. �� box Ŭ���� ���� content ������ ��Ұ� �ű⿡ �ʿ���
// ������ ��� �Լ��Դϴ�. ���Ͻô� box�� �νð� ���ð� ���� ������ ���� �ۼ��Ͻø�
// �˴ϴ�. 
void PrintText(BoxUI box);
// �ۼ��Ͻ� ������ �ڽ� ���ο� �����Ͽ� ����ϴ� �Լ� �Դϴ�.
// ���װ� �߻��ϴµ� �̴� �ʰ� NPC ������ �־ ���� ��ġ�� �κ��� ���� 
// ��������� �� ���� �ʰ� �÷��̾� �̵� NPC���� �ϼ��Ǹ� �� ���� ���� 
// �ɰ� �����ϴ�. 