// ���� ��� �����ϱ�.
#define _CRT_SECURE_NO_WARNINGS

// ������� �����ϱ�.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// �ҽ��ڵ� �����ϱ�.
#include "game-manager.h"
#include "game-manager.h"

void Drawing_Playground_Chapter1_Stage1();

/* �޸�
* 1. ��
* ��� : ��
* �ϴû� : �÷��̾�

*/

// Chapter1_Stage1 �� �׸���
void Drawing_Playground_Chapter1_Stage1() {

	// 1. �� �����ϱ�
	SettingCursor(2, 3);
	Setting_Color(DARK_GRAY);
	for (int i = 3; i < 38; i++) { // ����
		for (int j = 2; j < 97; j++) { // ����
			SettingCursor(j, i);
			printf("��");
		}
	}
	// 2. �÷��̾� �����ϱ�.
	SettingCursor(46, 17);
	Setting_Color(SKYBLUE);
	printf("��");

	// 3. �� �����ϱ�.
	Setting_Color(DARK_GRAY);
	for (int i = 17; i < 18; i++) {
		for (int j = 47; j < 56; j++) { // �� : 2ĭ�� ������.
			SettingCursor(j, i);
			printf(" ");
		}
	}

	// 4. ���� ���� �����ϱ�.
	Setting_Color(YELLOW);
	SettingCursor(54, 17);
	printf("��");

}
