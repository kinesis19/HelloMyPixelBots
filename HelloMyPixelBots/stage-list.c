// 보안 경고 무시하기.
#define _CRT_SECURE_NO_WARNINGS

// 헤더파일 선언하기.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// 소스코드 참조하기.
#include "game-manager.h"
#include "game-manager.h"
#include "pixelbot.h"

#define MAX_WIDTH 100 // Playground 가로 최대 길이.
#define MAX_HEIGHT 40 // Playground 세로 최대 길이.
char screenBuffer[MAX_HEIGHT][MAX_WIDTH];

void Drawing_Playground_Chapter1_Stage1();
void InitializingScreenBuffer();
int Detecting_Objects(int x, int y, char ch);

// 버퍼 초기화하기.
void InitializingScreenBuffer() {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			screenBuffer[i][j] = ' '; // 공백으로 초기화하기.
		}
	}
}

int Detecting_Objects(int x, int y, char ch) {
	if (x < MAX_WIDTH && y < MAX_HEIGHT && screenBuffer[y][x] == ch) {
		return 1;
	}
}



// Chapter1_Stage1 맵 그리기
void Drawing_Playground_Chapter1_Stage1() {

	// 1. 벽 생성하기
	SettingCursor(2, 3);
	Setting_Color(DARK_GRAY);
	for (int i = 3; i < 38; i++) { // 세로
		for (int j = 2; j < 97; j+=2) { // 가로 '■' 문자가 두 칸을 차지하므로, 2씩 증가해야 함.
			SettingCursor(j, i);
			printf("■");
			if (j < MAX_WIDTH && i < MAX_HEIGHT) {
				screenBuffer[i][j] = '■';  // 버퍼에 문자 저장
			}
		}
	}

	// 2. 길 생성하기.
	Setting_Color(DARK_GRAY);
	for (int i = 17; i < 18; i++) {
		for (int j = 46; j < 56; j++) { // ■ : 2칸을 차지함.
			SettingCursor(j, i);
			printf(" ");
			if (j < MAX_WIDTH && i < MAX_HEIGHT) {
				screenBuffer[i][j] = ' ';  // 버퍼에 문자 저장
			}
		}
	}

	// 3. 플레이어 생성하기.
	SettingCursor(46, 17);
	Setting_Color(SKYBLUE);
	printf("▣");
	pixelBot.sw.posX = 46;
	pixelBot.sw.posY = 17;


	// 4. 도착 지점 생성하기.
	Setting_Color(YELLOW);
	SettingCursor(54, 17);
	printf("★");
	gameManager.posFinishX = 54;
	gameManager.posFinishY = 17;

}



