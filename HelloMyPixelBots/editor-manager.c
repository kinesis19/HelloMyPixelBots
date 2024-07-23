// ���� ��� �����ϱ�.
#define _CRT_SECURE_NO_WARNINGS

// ������� �����ϱ�.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "game-manager.h"
#include "editor-manager.h"

void Typing_API_To_Editor();
static void Updating_Editor(int cntLine, char* textAPI); // �Է� ���� API�� Editor Layout�� ǥ���ϱ�.

void Typing_API_To_Editor() {
	CommandList *commands = NULL; // ����ü �迭 �ʱ�ȭ�ϱ�.
	int cntCommand = 0; // �Էµ� Command�� ī��Ʈ�� ��Ÿ�� -> API�� �Է� MAXIMUM ����

	while (1) {

		// ���� �����ϱ�.
		char inputAPI[100];

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

		Setting_Color(WHITE);
		SettingCursor(3, 41);
		printf("Enter the API and move pixelBot to the 'Finish point'!");

		SettingCursor(3, 44);
		printf("> ");

		fgets(inputAPI, sizeof(inputAPI), stdin);

		// ������ API�� �Է��ϸ� Editor�� �Է� �����ϱ�.
		if (strcmp(inputAPI, "Stop()\n") == 0) {
			Updating_Editor(cntCommand, inputAPI);
			cntCommand++;
			break;
		}

		// �Է��� API���� step ���� �� Command ����ü�� �����ϱ�.
		int step;
		if (cntCommand == 0 && strcmp(inputAPI, "Start()\n") == 0) { // ù ��° �ٿ� Start()�� ������ �Է� �ޱ�.
			// �����Ҵ��ϱ�.
			commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
			strcpy(commands[cntCommand].command, inputAPI);
			commands[cntCommand].step = -1; // Start()������ step�� ���� �ʿ�X
			SettingCursor(30, 44);
			Updating_Editor(cntCommand, inputAPI);
			cntCommand++;
		}else if(0 < cntCommand && cntCommand < 19){ // ù ��° �ٰ� ������ �� ���ܿ� �ٸ� API��� �߰��ϱ�.
			if (sscanf(inputAPI, "bot.MoveUp(%d)\n", &step) == 1) { // bot.MoveUp(step) �Է½� ó��.
				SettingCursor(30, 44);
				// �����Ҵ��ϱ�.
				commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
				strcpy(commands[cntCommand].command, inputAPI);
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}else if (sscanf(inputAPI, "bot.MoveDown(%d)\n", &step) == 1) { // bot.MoveDown(step) �Է½� ó��.
				SettingCursor(30, 44);
				// �����Ҵ��ϱ�.
				commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
				strcpy(commands[cntCommand].command, inputAPI);
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}else if (sscanf(inputAPI, "bot.MoveLeft(%d)\n", &step) == 1) { // bot.MoveLeft(step) �Է½� ó��.
				SettingCursor(30, 44);
				// �����Ҵ��ϱ�.
				commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
				strcpy(commands[cntCommand].command, inputAPI);
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}else if (sscanf(inputAPI, "bot.MoveRight(%d)\n", &step) == 1) { // bot.MoveRight(step) �Է½� ó��.
				SettingCursor(30, 44);
				// �����Ҵ��ϱ�.
				commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
				strcpy(commands[cntCommand].command, inputAPI);
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}
		}

	}

	// ���� �޸� �Ҵ� �����ϱ�. 
	free(commands);

}

static void Updating_Editor(int cntLine, char* textAPI) {

	SettingCursor(156, 4 + cntLine);
	printf("%s", textAPI);

}