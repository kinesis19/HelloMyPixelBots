// ���� ��� �����ϱ�.
#define _CRT_SECURE_NO_WARNINGS

// ������� �����ϱ�.
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


// �ʿ��� ��� �����ϱ�.
#define UP 72
#define DOWN 80
#define ENTER 13

void SettingGUI_Stage();
static void SettingGUI_Stage_Layout_Base();
static void SettingGUI_Stage_Layout_Dialog();
static void SettingGUI_Stage_Layout_Playground(); // Playground Layout �����ϱ�.
static void SettingGUI_Stage_Layout_View(); // View Layout �����ϱ�(����, �̺�Ʈ ��Ȳ ���).
static void SettingGUI_Stage_Layout_Editor(); // Editor Layout �����ϱ�(��ũ��Ʈ �ۼ� ���).
static void SettingGUI_Stage_Layout_APIList(); // API List Layout �����ϱ�(Editor�� �ۼ��� API�� ���).
static void DrawingGUI_Playground();
static void Initializing_Command_Line();
void SettingGUI_Stage_Layout_PixelBotInfo(); // PixelBot�� ����(level, exp, hp ���� ������Ʈ��.)

void EnterToStage() {
	system("cls");
	SettingGUI_Stage();
	Initializing_Command_Line();
}


// Stage GUI Setting�ϱ�.
void SettingGUI_Stage() {
	// Base Layout �����ϱ�.
	SettingGUI_Stage_Layout_Base();

	// 2. Dialog Layout �����ϱ�.
	SettingGUI_Stage_Layout_Dialog();

	// 3. Playground Layout �����ϱ�.
	SettingGUI_Stage_Layout_Playground();

	// 4. View Layout �����ϱ�.
	SettingGUI_Stage_Layout_View();

	// 5. Editor Layout �����ϱ�.
	SettingGUI_Stage_Layout_Editor();

	// 6. API Layout �����ϱ�.
	SettingGUI_Stage_Layout_APIList();

	// 7. Playground �� �������ϱ�.
	DrawingGUI_Playground();
}

static void SettingGUI_Stage_Layout_Base() {

	// 1. ū �׵θ� �����ϱ�.
	// 1-1. ��� �׵θ� �����ϱ�.
	SettingCursor(0, 0);
	printf("��");
	for (int i = 1; i < 198; i++) {
		SettingCursor(i, 0);
		printf("��");
	}
	SettingCursor(198, 0);
	printf("��");

	// 1-2. ���̵� �׵θ� �����ϱ�.
	for (int i = 1; i < 40; i++) {
		SettingCursor(0, i);
		printf("��");
		SettingCursor(198, i);
		printf("��");
	}

	// 1-3. �ϴ� �׵θ� �����ϱ�.
	SettingCursor(0, 48);
	printf("��");
	for (int i = 1; i < 198; i++) {
		SettingCursor(i, 48);
		printf("��");
	}
	SettingCursor(198, 48);
	printf("��");
}

static void SettingGUI_Stage_Layout_Dialog() {

	// 2. ��ȭ ����(Dialog) ���̾ƿ� �����ϱ�.
	// 2-1. ��� �׵θ� �����ϱ�.
	SettingCursor(0, 40);
	printf("��");
	for (int i = 1; i < 198; i++) {
		SettingCursor(i, 40);
		printf("��");
	}
	SettingCursor(198, 40);
	printf("��");

	// 2-2. ���̵� �׵θ� �����ϱ�.
	for (int i = 40; i < 48; i++) {
		SettingCursor(0, i);
		printf("��");
		SettingCursor(198, i);
		printf("��");
	}

	// 2-3. ���� �ؽ�Ʈ �����ϱ�.
	SettingCursor(2, 39);
	printf("Command");

	// 2-4. ���� �ؽ�Ʈ �׵θ� �����ϱ�.
	SettingCursor(0, 38);
	printf("��");
	for (int i = 1; i < 10; i++) {
		SettingCursor(i, 38);
		printf("��");
	}
	SettingCursor(10, 38);
	printf("��");

	SettingCursor(10, 39);
	printf("��");

	SettingCursor(10, 40);
	printf("��");

}

static void SettingGUI_Stage_Layout_Playground() {
	for (int i = 11; i < 150; i++) {
		SettingCursor(i, 38);
		printf("��");
	}

	SettingCursor(101, 0);
	printf("��");

	for (int i = 1; i < 48; i++) {
		SettingCursor(101, i);
		printf("��");
	}

	SettingCursor(101, 48);
	printf("��");
	SettingCursor(0, 2);
	printf("��");
	SettingCursor(101, 40);
	printf("��");
	
	for (int i = 2; i < 197; i++) {
		SettingCursor(i, 2);
		printf("��");
	}

	// ���� �ؽ�Ʈ �ۼ��ϱ�.
	SettingCursor(44, 1);
	printf("[Playground]");
}

static void SettingGUI_Stage_Layout_View() {

	SettingCursor(150, 0);
	printf("��");

	for (int i = 1; i < 40; i++) {
		SettingCursor(150, i);
		printf("��");
	}
	SettingCursor(150, 40);
	printf("��");

	// Top Line �����ϱ�.
	SettingCursor(101, 2);
	printf("��");

	SettingCursor(198, 2);
	printf("��");

	SettingCursor(150, 2);
	printf("��");

	// Mid Line �����ϱ�.
	SettingCursor(101, 20);
	printf("��");

	for (int i = 102; i < 149; i++) {
		printf("��");
	}
	SettingCursor(150, 20);
	printf("��");


	// ���� �ؽ�Ʈ �ۼ��ϱ�.
	SettingCursor(123, 1);
	printf("[View]");

	SettingGUI_Stage_Layout_PixelBotInfo();
}

void SettingGUI_Stage_Layout_PixelBotInfo() {
	// PixelBot ���� �ۼ��ϱ�.

	SettingCursor(118, 3);
	printf("[PixelBot] Lv.%d", pixelBot.sw.level);

	SettingCursor(120, 5);
	printf("Exp : %d/%d", pixelBot.sw.expNow, pixelBot.sw.expMax);

	// PixelBot �׸���
	Setting_Color(SKYBLUE);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SettingCursor(118 + (i * 2), 7 + (j * 1));
			printf("��");
		}
	}

	Setting_Color(WHITE);
}


static void SettingGUI_Stage_Layout_Editor() {
	// ���� �ؽ�Ʈ �ۼ��ϱ�.
	SettingCursor(172, 1);
	printf("[Editor]");

}

static void SettingGUI_Stage_Layout_APIList() {

	// ���� �ؽ�Ʈ �����ϱ�.
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
	// Chapter1�� ��,
	if (pixelBot.sw.selectChapter == 1) {
		// Stage1�� ��,
		if (pixelBot.sw.selectStage == 1) {
			Drawing_Playground_Chapter1_Stage1();
		}
	}

}


// Ŀ�ǵ� ���� �ʱ�ȭ �ϴ� �Լ�.
static void Initializing_Command_Line() {

	// API �Է� �ޱ�.
	Typing_API_To_Editor();

	// Ŀ�ǵ� ���ο� �ִ� ��� �ؽ�Ʈ �ʱ�ȭ �ϱ�
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

	// �������� Ŭ�����,
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


	// ���� �����ϱ�.
	int curCnt = 1;


	SettingCursor(4, 44);
	// Ű���� �Է� �ޱ�.
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
		// ȭ��ǥ ��� �ʱ�ȭ �ϱ�.
		for (int i = 0; i < 2; i++) {
			SettingCursor(4, 44 + i * 2);
			printf(" ");
		}
		// ���� ���õ� ���� ȭ��ǥ ����ϱ�.
		SettingCursor(4, 42 + curCnt * 2);
		printf(">");
	}

}