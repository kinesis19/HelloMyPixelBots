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
#include "Player.h"
#include "main.h"
#include "lobby.h"

// �ʿ��� ��� �����ϱ�.
#define MAXIMUM_CMD 19
#define UP 72
#define DOWN 80
#define ENTER 13

void Typing_API_To_Editor();
static void Updating_Editor(int cntLine, char* textAPI); // �Է� ���� API�� Editor Layout�� ǥ���ϱ�.
static void Running_API(CommandList* commands , int cntCmd); // �Էµ� API���� �����մϴ�.
void Clearning_Dialog(); // Dialog�� �ʱ�ȭ���ϴ�.

void Typing_API_To_Editor() {
	CommandList *commands = malloc(MAXIMUM_CMD * sizeof(CommandList));
	int cntCommand = 0; // �Էµ� Command�� ī��Ʈ�� ��Ÿ�� -> API�� �Է� MAXIMUM ����

	while (1) {

		// ���� �����ϱ�.
		char inputAPI[100];

		Clearning_Dialog();

		Setting_Color(WHITE);
		SettingCursor(3, 41);
		printf("Enter the API and move pixelBot to the 'Finish point'!");

		SettingCursor(3, 44);
		printf("> ");

		fgets(inputAPI, sizeof(inputAPI), stdin);

		// ������ API�� �Է��ϸ� Editor�� �Է� �����ϱ�.
		if (cntCommand != 0 && strcmp(inputAPI, "Stop()\n") == 0) {
			Updating_Editor(cntCommand, inputAPI);
			cntCommand++;
			break;
		}

		// �Է��� API���� step ���� �� Command ����ü�� �����ϱ�.
		int step;
		if (cntCommand == 0 && strcmp(inputAPI, "Start()\n") == 0) { // ù ��° �ٿ� Start()�� ������ �Է� �ޱ�.
			strncpy(commands[cntCommand].command, inputAPI, sizeof(commands[cntCommand].command) - 1);
			commands[cntCommand].command[sizeof(commands[cntCommand].command) - 1] = '\0'; // ������ ���� NULL �����ϱ�.
			commands[cntCommand].step = -1; // Start()������ step�� ���� �ʿ�X
			Updating_Editor(cntCommand, inputAPI);
			cntCommand++;
		}else if(0 < cntCommand && cntCommand < MAXIMUM_CMD){ // ù ��° �ٰ� ������ �� ���ܿ� �ٸ� API��� �߰��ϱ�.
			if (sscanf(inputAPI, "bot.MoveUp(%d)\n", &step) == 1 ||
				sscanf(inputAPI, "bot.MoveDown(%d)\n", &step) == 1 ||
				sscanf(inputAPI, "bot.MoveLeft(%d)\n", &step) == 1 ||
				sscanf(inputAPI, "bot.MoveRight(%d)\n", &step) == 1) { // bot.MoveUp(step) �Է½� ó��.
				strcpy(commands[cntCommand].command, inputAPI);

				strncpy(commands[cntCommand].command, inputAPI, sizeof(commands[cntCommand].command) - 1);
				commands[cntCommand].command[sizeof(commands[cntCommand].command) - 1] = '\0';
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}

		}

	}

	
	Running_API(commands, cntCommand);

	// ���� �޸� �Ҵ� �����ϱ�. 
	free(commands);
}

static void Updating_Editor(int cntLine, char* textAPI) {

	SettingCursor(156, 4 + cntLine);
	printf("%s", textAPI);

}

// ����� API �����ϱ�.
static void Running_API(CommandList* commands, int cntCmd) {
	
	// 1. �Էµ� API Ȯ���ϱ�.
	int temp;
	for (int i = 0; i < cntCmd; i++) {
		if (strcmp(commands[i].command, "Start()\n") == 0) {
			gameManager.condition = "Start";
		}else if (sscanf(commands[i].command, "bot.MoveUp(%d)\n", &temp) == 1) {
			gameManager.condition = "Up";
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.sw.posX, player.sw.posY - 1);
				if(gameManager.isPassAPI == true){ // Dialog�� �ߺ� �����Ǿ� �������� ������ �����Ǵ� ���� �����ϱ� ����.
					break;
				}
			}
		}else if (sscanf(commands[i].command, "bot.MoveDown(%d)\n", &temp) == 1) {
			gameManager.condition = "Down";
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.sw.posX, player.sw.posY + 1);
				if (gameManager.isPassAPI == true) { // Dialog�� �ߺ� �����Ǿ� �������� ������ �����Ǵ� ���� �����ϱ� ����.
					break;
				}
			}
		}else if (sscanf(commands[i].command, "bot.MoveLeft(%d)\n", &temp) == 1) {
			gameManager.condition = "Left";
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.sw.posX - 2, player.sw.posY); // �� : 2ĭ �̹Ƿ� 2ĭ�� �̵���. (���� ����)
				if (gameManager.isPassAPI == true) { // Dialog�� �ߺ� �����Ǿ� �������� ������ �����Ǵ� ���� �����ϱ� ����.
					break;
				}
			}
		}else if (sscanf(commands[i].command, "bot.MoveRight(%d)\n", &temp) == 1) {
			gameManager.condition = "Right";
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.sw.posX + 2, player.sw.posY); // �� : 2ĭ �̹Ƿ� 2ĭ�� �̵���. (���� ����)
				if (gameManager.isPassAPI == true) { // Dialog�� �ߺ� �����Ǿ� �������� ������ �����Ǵ� ���� �����ϱ� ����.
					break;
				}
			}
		}
		gameManager.isPassAPI = false;

	}
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
	}else{
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
				}else if (curCnt == 2) {
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

void Clearning_Dialog() {

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
}