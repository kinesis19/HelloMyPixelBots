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
#include "pixelbot.h"

#define MAX_WIDTH 100 // Playground ���� �ִ� ����.
#define MAX_HEIGHT 40 // Playground ���� �ִ� ����.
char screenBuffer[MAX_HEIGHT][MAX_WIDTH];

void Drawing_Playground_Chapter1_Stage1();
void InitializingScreenBuffer();
int Detecting_Objects(int x, int y, char ch);

// ���� �ʱ�ȭ�ϱ�.
void InitializingScreenBuffer() {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			screenBuffer[i][j] = ' '; // �������� �ʱ�ȭ�ϱ�.
		}
	}
}

int Detecting_Objects(int x, int y, char ch) {
	if (x < MAX_WIDTH && y < MAX_HEIGHT && screenBuffer[y][x] == ch) {
		return 1;
	}
}



// Chapter1_Stage1 �� �׸���
void Drawing_Playground_Chapter1_Stage1() {

	// 1. �� �����ϱ�
	SettingCursor(2, 3);
	Setting_Color(DARK_GRAY);
	for (int i = 3; i < 38; i++) { // ����
		for (int j = 2; j < 97; j+=2) { // ���� '��' ���ڰ� �� ĭ�� �����ϹǷ�, 2�� �����ؾ� ��.
			SettingCursor(j, i);
			printf("��");
			if (j < MAX_WIDTH && i < MAX_HEIGHT) {
				screenBuffer[i][j] = '��';  // ���ۿ� ���� ����
			}
		}
	}

	// 2. �� �����ϱ�.
	Setting_Color(DARK_GRAY);
	for (int i = 17; i < 18; i++) {
		for (int j = 46; j < 56; j++) { // �� : 2ĭ�� ������.
			SettingCursor(j, i);
			printf(" ");
			if (j < MAX_WIDTH && i < MAX_HEIGHT) {
				screenBuffer[i][j] = ' ';  // ���ۿ� ���� ����
			}
		}
	}

	// 3. �÷��̾� �����ϱ�.
	SettingCursor(46, 17);
	Setting_Color(SKYBLUE);
	printf("��");
	pixelBot.sw.posX = 46;
	pixelBot.sw.posY = 17;


	// 4. ���� ���� �����ϱ�.
	Setting_Color(YELLOW);
	SettingCursor(54, 17);
	printf("��");
	gameManager.posFinishX = 54;
	gameManager.posFinishY = 17;

}



