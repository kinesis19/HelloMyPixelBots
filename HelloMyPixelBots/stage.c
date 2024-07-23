// 보안 경고 무시하기.
#define _CRT_SECURE_NO_WARNINGS

// 헤더파일 선언하기.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game-manager.h"
#include "editor-manager.h"
#include "pixelbot.h"
#include "main.h"
#include "lobby.h"
#include "stage-list.h"


// 필요한 상수 선언하기.
#define UP 72
#define DOWN 80
#define ENTER 13

void SettingGUI_Stage();
static void SettingGUI_Stage_Layout_Base();
static void SettingGUI_Stage_Layout_Dialog();
static void SettingGUI_Stage_Layout_Playground(); // Playground Layout 생성하기.
static void SettingGUI_Stage_Layout_View(); // View Layout 생성하기(전투, 이벤트 상황 출력).
static void SettingGUI_Stage_Layout_Editor(); // Editor Layout 생성하기(스크립트 작성 출력).
static void SettingGUI_Stage_Layout_APIList(); // API List Layout 생성하기(Editor에 작성할 API들 출력).
static void DrawingGUI_Playground();
static void Initializing_Command_Line();
void SettingGUI_Stage_Layout_PixelBotInfo(); // PixelBot의 정보(level, exp, hp 등을 업데이트함.)

void EnterToStage() {
	system("cls");
	SettingGUI_Stage();
	Initializing_Command_Line();
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

	// 6. API Layout 생성하기.
	SettingGUI_Stage_Layout_APIList();

	// 7. Playground 맵 디자인하기.
	DrawingGUI_Playground();
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
	for (int i = 11; i < 150; i++) {
		SettingCursor(i, 38);
		printf("─");
	}

	SettingCursor(101, 0);
	printf("┬");

	for (int i = 1; i < 48; i++) {
		SettingCursor(101, i);
		printf("│");
	}

	SettingCursor(101, 48);
	printf("┴");
	SettingCursor(0, 2);
	printf("├");
	SettingCursor(101, 40);
	printf("┼");
	
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

	// Mid Line 세팅하기.
	SettingCursor(101, 20);
	printf("├");

	for (int i = 102; i < 149; i++) {
		printf("─");
	}
	SettingCursor(150, 20);
	printf("┤");


	// 세부 텍스트 작성하기.
	SettingCursor(123, 1);
	printf("[View]");

	SettingGUI_Stage_Layout_PixelBotInfo();
}

void SettingGUI_Stage_Layout_PixelBotInfo() {
	// PixelBot 정보 작성하기.

	SettingCursor(118, 3);
	printf("[PixelBot] Lv.%d", pixelBot.sw.level);

	SettingCursor(120, 5);
	printf("Exp : %d/%d", pixelBot.sw.expNow, pixelBot.sw.expMax);

	// PixelBot 그리기
	Setting_Color(SKYBLUE);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SettingCursor(118 + (i * 2), 7 + (j * 1));
			printf("▣");
		}
	}

	Setting_Color(WHITE);
}


static void SettingGUI_Stage_Layout_Editor() {
	// 세부 텍스트 작성하기.
	SettingCursor(172, 1);
	printf("[Editor]");

}

static void SettingGUI_Stage_Layout_APIList() {

	// 세부 텍스트 세팅하기.
	SettingCursor(122, 39);
	printf("[API List]");

	int cntLine = 1;
	for (int i = 0; i < 20; i++) {
		SettingCursor(152, 3 + cntLine);
		printf("%2d", cntLine);
		cntLine++;
	}

	if (pixelBot.sw.selectChapter == 1) {
		if (pixelBot.sw.selectStage == 1) {
			SettingCursor(104, 41);
			printf("Start() : Start to pixelBot");
			SettingCursor(104, 42);
			printf("Stop() : Stop to pixelBot");
			SettingCursor(104, 43);
			printf("bot.MoveUp(step) : Move pixelBot up by step.");
			SettingCursor(104, 44);
			printf("bot.MoveDown(step) : Move pixelBot down by step.");
			SettingCursor(104, 45);
			printf("bot.MoveLeft(step) : Move pixelBot left by step.");
			SettingCursor(104, 46);
			printf("bot.MoveRight(step) : Move pixelBot right by step.");
		}
	}

}

static void DrawingGUI_Playground() {
	// Chapter1일 때,
	if (pixelBot.sw.selectChapter == 1) {
		// Stage1일 때,
		if (pixelBot.sw.selectStage == 1) {
			Drawing_Playground_Chapter1_Stage1();
		}
	}

}


// 커맨드 라인 초기화 하는 함수.
static void Initializing_Command_Line() {

	// API 입력 받기.
	Typing_API_To_Editor();

	// 커맨드 라인에 있는 모든 텍스트 초기화 하기
	for (int i = 41; i < 44; i++) {
		for (int j = 3; j < 100; j++) {
			// Dialog-Top Resetting
			SettingCursor(j, i);
			printf(" ");
			// Dialog-Command Resetting
			SettingCursor(j, 44);
			printf(" ");
		}
	}
	SettingCursor(3, 41);

	// 스테이지 클리어시,
	if (gameManager.isStageClear == true) {
		Setting_Color(YELLOW);
		printf("Stage Clear!!");
	}
	else {
		Setting_Color(RED);
		printf("Stage Clear Failed!!");
	}

	SettingCursor(3, 42);
	Setting_Color(WHITE);
	printf("What do you want to do?");

	SettingCursor(5, 44);
	printf("[1]Go to the Lobby Scene");

	SettingCursor(5, 46);
	printf("[2]Go to the Main Scene");


	// 변수 선언하기.
	int curCnt = 1;


	SettingCursor(4, 44);
	// 키보드 입력 받기.
	char inputKb;
	while (1) {
		HidingCursor();
		if (_kbhit()) {
			inputKb = _getch();
			switch (inputKb) {
			case UP:
				if (curCnt > 1) {
					curCnt--;
				}
				break;
			case DOWN:
				if (curCnt < 2) {
					curCnt++;
				}
				break;
			case ENTER:
				if (curCnt == 1) {
					Lobby();
					return 0;
					break;
				}
				else if (curCnt == 2) {
					main();
					return 0;
					break;
				}
			default:
				break;
			}
		}
		// 화살표 출력 초기화 하기.
		for (int i = 0; i < 2; i++) {
			SettingCursor(4, 44 + i * 2);
			printf(" ");
		}
		// 현재 선택된 곳만 화살표 출력하기.
		SettingCursor(4, 42 + curCnt * 2);
		printf(">");
	}

}