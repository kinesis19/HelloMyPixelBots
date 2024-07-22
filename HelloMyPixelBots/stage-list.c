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

void Drawing_Playground_Chapter1_Stage1();

/* 메모
* 1. ■
* 흰색 : 벽
* 하늘색 : 플레이어

*/

// Chapter1_Stage1 맵 그리기
void Drawing_Playground_Chapter1_Stage1() {

	// 1. 벽 생성하기
	SettingCursor(2, 3);
	Setting_Color(DARK_GRAY);
	for (int i = 3; i < 38; i++) { // 세로
		for (int j = 2; j < 97; j++) { // 가로
			SettingCursor(j, i);
			printf("■");
		}
	}
	// 2. 플레이어 생성하기.
	SettingCursor(46, 17);
	Setting_Color(SKYBLUE);
	printf("▣");

	// 3. 길 생성하기.
	Setting_Color(DARK_GRAY);
	for (int i = 17; i < 18; i++) {
		for (int j = 47; j < 56; j++) { // ■ : 2칸을 차지함.
			SettingCursor(j, i);
			printf(" ");
		}
	}

	// 4. 도착 지점 생성하기.
	Setting_Color(YELLOW);
	SettingCursor(54, 17);
	printf("★");

}
