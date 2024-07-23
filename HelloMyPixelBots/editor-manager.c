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
#include "main.h"
#include "lobby.h"

// 필요한 상수 선언하기.
#define MAXIMUM_CMD 19
#define UP 72
#define DOWN 80
#define ENTER 13

void Typing_API_To_Editor();
static void Updating_Editor(int cntLine, char* textAPI); // 입력 받은 API를 Editor Layout에 표시하기.
static void Running_API(CommandList* commands , int cntCmd); // 입력된 API들을 실행합니다.
void Clearning_Dialog(); // Dialog를 초기화힙니다.

void Typing_API_To_Editor() {
	CommandList *commands = malloc(MAXIMUM_CMD * sizeof(CommandList));
	int cntCommand = 0; // 입력된 Command의 카운트를 나타냄 -> API의 입력 MAXIMUM 제어

	while (1) {

		// 변수 선언하기.
		char inputAPI[100];

		Clearning_Dialog();

		Setting_Color(WHITE);
		SettingCursor(3, 41);
		printf("Enter the API and move pixelBot to the 'Finish point'!");

		SettingCursor(3, 44);
		printf("> ");

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
			gameManager.condition = "Start";
		}else if (sscanf(commands[i].command, "bot.MoveUp(%d)\n", &temp) == 1) {
			gameManager.condition = "Up";
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.sw.posX, player.sw.posY - 1);
				if(gameManager.isPassAPI == true){ // Dialog가 중복 생성되어 오랫동안 게임이 지연되는 것을 방지하기 위함.
					break;
				}
			}
		}else if (sscanf(commands[i].command, "bot.MoveDown(%d)\n", &temp) == 1) {
			gameManager.condition = "Down";
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.sw.posX, player.sw.posY + 1);
				if (gameManager.isPassAPI == true) { // Dialog가 중복 생성되어 오랫동안 게임이 지연되는 것을 방지하기 위함.
					break;
				}
			}
		}else if (sscanf(commands[i].command, "bot.MoveLeft(%d)\n", &temp) == 1) {
			gameManager.condition = "Left";
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.sw.posX - 2, player.sw.posY); // ▣ : 2칸 이므로 2칸씨 이동함. (가로 한정)
				if (gameManager.isPassAPI == true) { // Dialog가 중복 생성되어 오랫동안 게임이 지연되는 것을 방지하기 위함.
					break;
				}
			}
		}else if (sscanf(commands[i].command, "bot.MoveRight(%d)\n", &temp) == 1) {
			gameManager.condition = "Right";
			for (int j = 0; j < commands[i].step; j++) {
				MovingPixelBot(player.sw.posX + 2, player.sw.posY); // ▣ : 2칸 이므로 2칸씨 이동함. (가로 한정)
				if (gameManager.isPassAPI == true) { // Dialog가 중복 생성되어 오랫동안 게임이 지연되는 것을 방지하기 위함.
					break;
				}
			}
		}
		gameManager.isPassAPI = false;

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
				}else if (curCnt == 2) {
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

void Clearning_Dialog() {

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
}