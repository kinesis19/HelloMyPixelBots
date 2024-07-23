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
#include "Player.h"

#define MAXIMUM_CMD 19

void Typing_API_To_Editor();
static void Updating_Editor(int cntLine, char* textAPI); // 입력 받은 API를 Editor Layout에 표시하기.
static void Running_API(CommandList* commands , int cntCmd); // 입력된 API들을 실행합니다.
static void Clearning_Dialog(); // Dialog를 초기화힙니다.

void Typing_API_To_Editor() {
	CommandList *commands = malloc(MAXIMUM_CMD * sizeof(CommandList));
	int cntCommand = 0; // 입력된 Command의 카운트를 나타냄 -> API의 입력 MAXIMUM 제어

	while (1) {

		// 변수 선언하기.
		char inputAPI[100];

		Clearning_Dialog();

		fgets(inputAPI, sizeof(inputAPI), stdin);

		// 마지막 API를 입력하면 Editor에 입력 종료하기.
		if (cntCommand != 0 && strcmp(inputAPI, "Stop()\n") == 0) {
			Updating_Editor(cntCommand, inputAPI);
			cntCommand++;
			break;
		}

		// 입력한 API에서 step 추출 및 Command 구조체에 저장하기.
		int step;
		if (cntCommand == 0 && strcmp(inputAPI, "Start()\n") == 0) { // 첫 번째 줄에 Start()를 무조건 입력 받기.
			strncpy(commands[cntCommand].command, inputAPI, sizeof(commands[cntCommand].command) - 1);
			commands[cntCommand].command[sizeof(commands[cntCommand].command) - 1] = '\0'; // 마지막 문자 NULL 지정하기.
			commands[cntCommand].step = -1; // Start()에서는 step의 존재 필요X
			Updating_Editor(cntCommand, inputAPI);
			cntCommand++;
		}else if(0 < cntCommand && cntCommand < MAXIMUM_CMD){ // 첫 번째 줄과 마지막 줄 제외에 다른 API기능 추가하기.
			if (sscanf(inputAPI, "bot.MoveUp(%d)\n", &step) == 1 ||
				sscanf(inputAPI, "bot.MoveDown(%d)\n", &step) == 1 ||
				sscanf(inputAPI, "bot.MoveLeft(%d)\n", &step) == 1 ||
				sscanf(inputAPI, "bot.MoveRight(%d)\n", &step) == 1) { // bot.MoveUp(step) 입력시 처리.
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

	// 동적 메모리 할당 해제하기. 
	free(commands);
}

static void Updating_Editor(int cntLine, char* textAPI) {

	SettingCursor(156, 4 + cntLine);
	printf("%s", textAPI);

}

// 저장된 API 실행하기.
static void Running_API(CommandList* commands, int cntCmd) {
	
	// 1. 입력된 API 확인하기.
	int temp;
	for (int i = 0; i < cntCmd; i++) {
		if (strcmp(commands[i].command, "Start()\n") == 0) {

		}else if (sscanf(commands[i].command, "bot.MoveUp(%d)\n", &temp) == 1) {
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.posX, player.posY - 1);
			}
		}
	}
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
	}else{
		Setting_Color(RED);
		printf("Stage Clear Failed!!");
	}
	_getch();

}

static void Clearning_Dialog() {

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
}