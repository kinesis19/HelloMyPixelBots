// 헤더파일 선언하기.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

void SettingGUI_Lobby();
static void SettingCursor(int x, int y);
static void SettingGUI_Lobby_Layout_Base();
static void SettingGUI_Lobby_Layout_Dialog();
static void SettingGUI_Lobby_Layout_Chapters();
static void SettingGUI_Lobby_Layout_Chapter_1();

void Lobby() {
	// 콘솔창 초기화하기.
	system("cls");
	// 콘솔창 GUI Setting하기.
	SettingGUI_Lobby();
	_getch();
}

// Lobby GUI Setting하기.
void SettingGUI_Lobby() {
	// Base Layout 생성하기.
	SettingGUI_Lobby_Layout_Base();

	// 2. Dialog Layout 생성하기.
	SettingGUI_Lobby_Layout_Dialog();

	// 3. Chapters Layout 생성하기.
	SettingGUI_Lobby_Layout_Chapters();

}

static void SettingCursor(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

static void SettingGUI_Lobby_Layout_Base() {

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

static void SettingGUI_Lobby_Layout_Dialog() {

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
	printf("┐");

	SettingCursor(10, 39);
	printf("│");

	SettingCursor(10, 40);
	printf("┴");

}

static void SettingGUI_Lobby_Layout_Chapters() {

	// 1. Chapter_1 GUI를 생성하기.
	SettingGUI_Lobby_Layout_Chapter_1();

}

static void SettingGUI_Lobby_Layout_Chapter_1() {

	// 1. 텍스트 생성하기.
	SettingCursor(20, 5);
	printf("[Chapter 1]");

	// (스테이지 클리어 현황 / 전체 스테이지)
	SettingCursor(22, 6);
	printf("(0/5)");

	// 2. 챕터 그래픽 생성하기

	for (int i = 10; i < 39; i+=2) { // ■ = 2칸 차지하므로, i+=2로 중복 생성을 방지함.
		for (int j = 8; j < 30; j++) {
			SettingCursor(i, j);
			printf("■");
		}

	}

}

