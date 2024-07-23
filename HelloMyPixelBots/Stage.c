// ���� ��� �����ϱ�.
#define _CRT_SECURE_NO_WARNINGS

// ������� �����ϱ�.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// �ҽ��ڵ� �����ϱ�.
#include "Player.h"
#include "stage-list.h"
#include "game-manager.h"
#include "editor-manager.h"

void SettingGUI_Stage();
static void SettingGUI_Stage_Layout_Base();
static void SettingGUI_Stage_Layout_Dialog();
static void SettingGUI_Stage_Layout_Playground(); // Playground Layout �����ϱ�.
static void SettingGUI_Stage_Layout_View(); // View Layout �����ϱ�(����, �̺�Ʈ ��Ȳ ���).
static void SettingGUI_Stage_Layout_Editor(); // Editor Layout �����ϱ�(��ũ��Ʈ �ۼ� ���).
static void SettingGUI_Stage_Layout_APIList(); // API List Layout �����ϱ�(Editor�� �ۼ��� API�� ���).
static void DrawingGUI_Playground();
static void Initializing_Command_Line();

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

	// ���� �ؽ�Ʈ �ۼ��ϱ�.
	SettingCursor(123, 1);
	printf("[View]");

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

	if (player.selectChapter == 1) {
		if (player.selectStage == 1) {
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
	if (player.selectChapter == 1) {
		// Stage1�� ��,
		if (player.selectStage == 1) {
			Drawing_Playground_Chapter1_Stage1();
		}
	}

}


// Ŀ�ǵ� ���� �ʱ�ȭ �ϴ� �Լ�.
static void Initializing_Command_Line() {

	// API �Է� �ޱ�.
	Typing_API_To_Editor();

}