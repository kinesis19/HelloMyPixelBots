// 보안 경고 무시하기.
#define _CRT_SECURE_NO_WARNINGS

// 헤더파일 선언하기.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "game-manager.h"
#include "editor-manager.h"

void Typing_API_To_Editor();
static void Updating_Editor(int cntLine, char* textAPI); // 입력 받은 API를 Editor Layout에 표시하기.

void Typing_API_To_Editor() {
	CommandList *commands = NULL; // 구조체 배열 초기화하기.
	int cntCommand = 0; // 입력된 Command의 카운트를 나타냄 -> API의 입력 MAXIMUM 제어

	while (1) {

		// 변수 선언하기.
		char inputAPI[100];

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

		Setting_Color(WHITE);
		SettingCursor(3, 41);
		printf("Enter the API and move pixelBot to the 'Finish point'!");

		SettingCursor(3, 44);
		printf("> ");

		fgets(inputAPI, sizeof(inputAPI), stdin);

		// 마지막 API를 입력하면 Editor에 입력 종료하기.
		if (strcmp(inputAPI, "Stop()\n") == 0) {
			Updating_Editor(cntCommand, inputAPI);
			cntCommand++;
			break;
		}

		// 입력한 API에서 step 추출 및 Command 구조체에 저장하기.
		int step;
		if (cntCommand == 0 && strcmp(inputAPI, "Start()\n") == 0) { // 첫 번째 줄에 Start()를 무조건 입력 받기.
			// 동적할당하기.
			commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
			strcpy(commands[cntCommand].command, inputAPI);
			commands[cntCommand].step = -1; // Start()에서는 step의 존재 필요X
			SettingCursor(30, 44);
			Updating_Editor(cntCommand, inputAPI);
			cntCommand++;
		}else if(0 < cntCommand && cntCommand < 19){ // 첫 번째 줄과 마지막 줄 제외에 다른 API기능 추가하기.
			if (sscanf(inputAPI, "bot.MoveUp(%d)\n", &step) == 1) { // bot.MoveUp(step) 입력시 처리.
				SettingCursor(30, 44);
				// 동적할당하기.
				commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
				strcpy(commands[cntCommand].command, inputAPI);
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}else if (sscanf(inputAPI, "bot.MoveDown(%d)\n", &step) == 1) { // bot.MoveDown(step) 입력시 처리.
				SettingCursor(30, 44);
				// 동적할당하기.
				commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
				strcpy(commands[cntCommand].command, inputAPI);
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}else if (sscanf(inputAPI, "bot.MoveLeft(%d)\n", &step) == 1) { // bot.MoveLeft(step) 입력시 처리.
				SettingCursor(30, 44);
				// 동적할당하기.
				commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
				strcpy(commands[cntCommand].command, inputAPI);
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}else if (sscanf(inputAPI, "bot.MoveRight(%d)\n", &step) == 1) { // bot.MoveRight(step) 입력시 처리.
				SettingCursor(30, 44);
				// 동적할당하기.
				commands = realloc(commands, (cntCommand + 1) * sizeof(CommandList));
				strcpy(commands[cntCommand].command, inputAPI);
				commands[cntCommand].step = step;
				Updating_Editor(cntCommand, inputAPI);
				cntCommand++;
			}
		}

	}

	// 동적 메모리 할당 해제하기. 
	free(commands);

}

static void Updating_Editor(int cntLine, char* textAPI) {

	SettingCursor(156, 4 + cntLine);
	printf("%s", textAPI);

}