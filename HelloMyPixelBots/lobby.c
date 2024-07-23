// ���� ��� �����ϱ�.
#define _CRT_SECURE_NO_WARNINGS

// ������� �����ϱ�.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// �ҽ��ڵ� �����ϱ�.
#include "pixelbot.h"
#include "stage.h"
#include "game-manager.h"

// �ʿ��� ��� �����ϱ�.
#define UP 72
#define DOWN 80
#define ENTER 13

void SettingGUI_Lobby();
static void SettingGUI_Lobby_Layout_Base();
static void SettingGUI_Lobby_Layout_Dialog();
static void SettingGUI_Lobby_Layout_Chapters();
static void SettingGUI_Lobby_Layout_Chapter_1();
static void Initializing_Command_Line();
static void Initializing_Command_Line_Dialog();
static void Typing_Command_Line_Dialog(char* type, int curCnt);

void Lobby() {
	// �ܼ�â �ʱ�ȭ�ϱ�.
	system("cls");
	// �ܼ�â GUI Setting�ϱ�.
	SettingGUI_Lobby();
}

// Lobby GUI Setting�ϱ�.
void SettingGUI_Lobby() {
	// Base Layout �����ϱ�.
	SettingGUI_Lobby_Layout_Base();

	// 2. Dialog Layout �����ϱ�.
	SettingGUI_Lobby_Layout_Dialog();

	// 3. Chapters Layout �����ϱ�.
	SettingGUI_Lobby_Layout_Chapters();

	// 4. Ŀ�ǵ� ���� ȣ���ϱ�.
	Initializing_Command_Line();
}

static void SettingGUI_Lobby_Layout_Base() {

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

static void SettingGUI_Lobby_Layout_Dialog() {

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

static void SettingGUI_Lobby_Layout_Chapters() {

	// 1. Chapter_1 GUI�� �����ϱ�.
	SettingGUI_Lobby_Layout_Chapter_1();

}

static void SettingGUI_Lobby_Layout_Chapter_1() {

	// 1. �ؽ�Ʈ �����ϱ�.
	SettingCursor(20, 5);
	printf("[Chapter 1]");

	// (�������� Ŭ���� ��Ȳ / ��ü ��������)
	SettingCursor(22, 6);
	printf("(0/5)");

	// 2. é�� �׷��� �����ϱ�

	for (int i = 10; i < 39; i+=2) { // �� = 2ĭ �����ϹǷ�, i+=2�� �ߺ� ������ ������.
		for (int j = 8; j < 30; j++) {
			SettingCursor(i, j);
			printf("��");
		}

	}

}

// Ŀ�ǵ� ���� �ʱ�ȭ �ϴ� �Լ�.
static void Initializing_Command_Line() {
	
	// ���� �����ϱ�.
	int curCnt = 1;
	/*char* curMode = NULL;*/
	char* curMode = (char*)malloc(30);

	strcpy(curMode, "SelectMode");

	SettingCursor(3, 41);
	printf("What do you want to do?");
	
	SettingCursor(5, 44);
	printf("[1]Enter The Chapter");

	SettingCursor(5, 46);
	printf("[2]Using the Tools");


	// Ű���� �Է� �ޱ�.
	char inputKb;
	while (1) {
		if (_kbhit()) {
			inputKb = _getch(); // VS ������ ���� ������ ���� getch() ��� _getch() ���. 
			switch (inputKb) {
			case UP:
				if (strcmp(curMode, "SelectMode") == 0) {
					if (curCnt > 1) {
						curCnt--;
					}
				}else if (strcmp(curMode, "SelectChapters") == 0) {
					if (curCnt > 1) {
						curCnt--;
					}
				}else if (strcmp(curMode, "SelectStages") == 0) {
					if (curCnt > 1) {
						curCnt--;
					}
				}
				break;
			case DOWN:
				if (strcmp(curMode, "SelectMode") == 0) {
					if (curCnt < 2) {
						curCnt++;
					}
				}else if (strcmp(curMode, "SelectChapters") == 0) {
					if (curCnt < 2) {
						curCnt++;
					}
				}else if (strcmp(curMode, "SelectStages") == 0) {
					if (curCnt < 6) {
						curCnt++;
					}
				}
				break;
			case ENTER:
				if (strcmp(curMode, "SelectMode") == 0) {
					// [1]Enter The Chapter�� ��,
					if (curCnt == 1) {
						Initializing_Command_Line_Dialog();
						Typing_Command_Line_Dialog(curMode, curCnt);
						break;
					}
				}else if(strcmp(curMode, "SelectChapters") == 0){
					// Chapter1 ������ ��,
					if (curCnt == 1) {
						gameManager.selectChapterName = 1;
						Initializing_Command_Line_Dialog();
						Typing_Command_Line_Dialog(curMode, curCnt);
						break;
					}
				}else if(strcmp(curMode, "SelectStages") == 0){
					// Stage1 ������ ��,
					if (curCnt == 1) {
						// Stage1�� �̵��ϱ�.
						pixelBot.sw.selectChapter = 1;
						pixelBot.sw.selectStage = 1;
						gameManager.selectStageName = 1;
						free(curMode);
						EnterToStage();
						return 0;
						break;
					}else if(curCnt == 2){
						//Stage2�� �̵��ϱ�.
						pixelBot.sw.selectChapter = 1;
						pixelBot.sw.selectStage = 2;
						gameManager.selectStageName = 2;
						free(curMode);
						EnterToStage();
						return 0;
						break;
					}else if(curCnt == 3){
						//Stage3�� �̵��ϱ�.
						pixelBot.sw.selectChapter = 1;
						pixelBot.sw.selectStage = 3;
						gameManager.selectStageName = 3;
						free(curMode);
						EnterToStage();
						return 0;
						break;
					}else if(curCnt == 4){
						//Stage4�� �̵��ϱ�.
						pixelBot.sw.selectChapter = 1;
						pixelBot.sw.selectStage = 4;
						gameManager.selectStageName = 4;
						free(curMode);
						EnterToStage();
						return 0;
						break;
					}else if(curCnt == 5){
						//Stage5�� �̵��ϱ�.
						pixelBot.sw.selectChapter = 1;
						pixelBot.sw.selectStage = 5;
						gameManager.selectStageName = 5;
						free(curMode);
						EnterToStage();
						return 0;
						break;
					}else if(curCnt == 6){
						//Lobby�� �̵��ϱ�.
						pixelBot.sw.selectChapter = 0;
						pixelBot.sw.selectStage = 0;
						gameManager.selectChapterName = 0;
						gameManager.selectStageName = 0;
						Lobby();
						break;
					}
				}
			default:
				break;
			}
		}
		// ȭ��ǥ ��� �ʱ�ȭ �ϱ�.
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				SettingCursor(3 + (j * 30), 44 + (i * 2));
				printf(" ");
				/*printf("!");*/
			}
		}
		// ���� ���õ� ���� ȭ��ǥ ����ϱ�.
		if (strcmp(curMode, "SelectMode") == 0) {
			SettingCursor(3, 42 + curCnt * 2);
		}else if (strcmp(curMode, "SelectChapters") == 0) {
			SettingCursor(3, 42 + curCnt * 2);
		}else if (strcmp(curMode, "SelectStages") == 0) {
			if (curCnt <= 2) {
				SettingCursor(3, 42 + curCnt * 2);
			}else if(curCnt <= 4){
				SettingCursor(33, 42 + (curCnt - 2) * 2);
			}else if(curCnt <= 6){
				SettingCursor(63, 42 + (curCnt - 4) * 2);
			}
		}
		printf(">");

	}
}

// Command Line���� Select �ʱ�ȭ�ϱ�.
static void Initializing_Command_Line_Dialog() {
	
	// Dialog Line �ʱ�ȭ�ϱ�.
	for (int i = 0; i < 50; i++) {
		SettingCursor(3 + i, 41);
		printf(" ");
	}

	// Select Line �ʱ�ȭ�ϱ�.
	for (int i = 0; i < 2; i++) {
		for (int j = 5; j < 50; j++) {
			SettingCursor(j, 44 + i * 2);
			printf(" ");
		}
	}
}

static void Typing_Command_Line_Dialog(char* type, int curCnt) {
	if (strcmp(type, "SelectMode") == 0) {
		SettingCursor(3, 41);
		printf("What Chapter do you want to enter?");
		SettingCursor(5, 44);
		printf("[1]Chapter1");

		SettingCursor(5, 46);
		printf("[2]Chapter2");

		strcpy(type, "SelectChapters");
	}else if (strcmp(type, "SelectChapters") == 0) {
		// Chapter1�� ��,
		if (curCnt == 1) {
			SettingCursor(3, 41);
			printf("What Stage do you want to enter?");

			SettingCursor(5, 44);
			printf("[1]Stage1");

			SettingCursor(5, 46);
			printf("[2]Stage2");

			SettingCursor(35, 44);
			printf("[3]Stage3");

			SettingCursor(35, 46);
			printf("[4]Stage4");

			SettingCursor(65, 44);
			printf("[5]Stage5");

			SettingCursor(65, 46);
			printf("[6]Exit");

			strcpy(type, "SelectStages");
		}
	}
}