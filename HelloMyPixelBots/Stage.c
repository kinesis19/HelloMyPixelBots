// 보안 경고 무시하기.
#define _CRT_SECURE_NO_WARNINGS

// 헤더파일 선언하기.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// 소스코드 참조하기.
#include "Player.h"

void SettingGUI_Stage();
static void SettingCursor(int x, int y);
static void SettingGUI_Stage_Layout_Base();
static void SettingGUI_Stage_Layout_Dialog();
static void SettingGUI_Stage_Layout_Playground(); // Playground Layout 생성하기.
static void SettingGUI_Stage_Layout_View(); // View Layout 생성하기(전투, 이벤트 상황 출력).
static void SettingGUI_Stage_Layout_Editor(); // Editor Layout 생성하기(스크립트 작성 출력).
static void DrawingGUI_Playground();

void EnterToStage() {
	system("cls");
	SettingGUI_Stage();
	/*printf("%d, %d", player.selectChapter, player.selectStage);*/
}


// Stage GUI Setting하기.
void SettingGUI_Stage() {
	// Base Layout 생성하기.
	SettingGUI_Stage_Layout_Base();

	// 2. Dialog Layout 생성하기.
	SettingGUI_Stage_Layout_Dialog();

	// 3. Playground Layout 생성하기.
	SettingGUI_Stage_Layout_Playground();

	// 4. View Layout 생성하기.
	SettingGUI_Stage_Layout_View();

	// 5. Editor Layout 생성하기.
	SettingGUI_Stage_Layout_Editor();

	_getch();
}

static void SettingCursor(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

static void SettingGUI_Stage_Layout_Base() {

	// 1. 큰 테두리 세팅하기.
	// 1-1. 상단 테두리 세팅하기.
	SettingCursor(0, 0);
	printf("┌");
	for (int i = 1; i < 198; i++) {
		SettingCursor(i, 0);
		printf("─");
	}
	SettingCursor(198, 0);
	printf("┐");

	// 1-2. 사이드 테두리 세팅하기.
	for (int i = 1; i < 40; i++) {
		SettingCursor(0, i);
		printf("│");
		SettingCursor(198, i);
		printf("│");
	}

	// 1-3. 하단 테두리 세팅하기.
	SettingCursor(0, 48);
	printf("└");
	for (int i = 1; i < 198; i++) {
		SettingCursor(i, 48);
		printf("─");
	}
	SettingCursor(198, 48);
	printf("┘");
}

static void SettingGUI_Stage_Layout_Dialog() {

	// 2. 대화 상자(Dialog) 레이아웃 생성하기.
	// 2-1. 상단 테두리 생성하기.
	SettingCursor(0, 40);
	printf("├");
	for (int i = 1; i < 198; i++) {
		SettingCursor(i, 40);
		printf("─");
	}
	SettingCursor(198, 40);
	printf("┤");

	// 2-2. 사이드 테두리 세팅하기.
	for (int i = 40; i < 48; i++) {
		SettingCursor(0, i);
		printf("│");
		SettingCursor(198, i);
		printf("│");
	}

	// 2-3. 세부 텍스트 세팅하기.
	SettingCursor(2, 39);
	printf("Command");

	// 2-4. 세부 텍스트 테두리 세팅하기.
	SettingCursor(0, 38);
	printf("├");
	for (int i = 1; i < 10; i++) {
		SettingCursor(i, 38);
		printf("─");
	}
	SettingCursor(10, 38);
	printf("┬");

	SettingCursor(10, 39);
	printf("│");

	SettingCursor(10, 40);
	printf("┴");

}

static void SettingGUI_Stage_Layout_Playground() {
	for (int i = 11; i < 101; i++) {
		SettingCursor(i, 38);
		printf("─");
	}

	SettingCursor(101, 0);
	printf("┬");

	for (int i = 1; i < 40; i++) {
		SettingCursor(101, i);
		printf("│");
	}
	SettingCursor(0, 2);
	printf("├");
	SettingCursor(101, 40);
	printf("┴");
	SettingCursor(101, 38);
	printf("┤");
	
	for (int i = 2; i < 197; i++) {
		SettingCursor(i, 2);
		printf("─");
	}

	// 세부 텍스트 작성하기.
	SettingCursor(44, 1);
	printf("[Playground]");
}

static void SettingGUI_Stage_Layout_View() {

	SettingCursor(150, 0);
	printf("┬");

	for (int i = 1; i < 40; i++) {
		SettingCursor(150, i);
		printf("│");
	}
	SettingCursor(150, 40);
	printf("┴");

	// Top Line 세팅하기.
	SettingCursor(101, 2);
	printf("├");

	SettingCursor(198, 2);
	printf("┤");

	SettingCursor(150, 2);
	printf("┼");

	// 세부 텍스트 작성하기.
	SettingCursor(123, 1);
	printf("[View]");

}

static void SettingGUI_Stage_Layout_Editor() {
	// 세부 텍스트 작성하기.
	SettingCursor(172, 1);
	printf("[Editor]");

}