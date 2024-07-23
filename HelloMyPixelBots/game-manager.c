// 보안 경고 무시하기.
#define _CRT_SECURE_NO_WARNINGS

// 헤더파일 선언하기.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 헤더파일 참조하기
#include "game-manager.h"
#include "pixelbot.h"
#include "stage-list.h"

// GameManager 구조체 전역 변수로 선언하기.
GameManager gameManager;

void Initializing_GameManager();
void Setting_Color(enum ColorType color);
void SettingCursor(int x, int y);
void MovingPixelBot(int x, int y);

void Initializing_GameManager() {
    gameManager.posFinishX = 0;
    gameManager.posFinishY = 0;
    gameManager.isStageClear = false;
    gameManager.selectChapterName = 0;
    gameManager.selectStageName = 0;
    gameManager.condition = NULL;
    gameManager.isPassAPI = false;
}

void Setting_Color(enum ColorType color) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

void SettingCursor(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void MovingPixelBot(int x, int y) {
    Clearning_Dialog();
    if(Detecting_Objects(x, y, '■') == 1){ // 장애물이 있을 경우 이동을 종료함.
        Setting_Color(RED);
        SettingCursor(3, 41);
        printf("Pixelbot can't Moving %s", gameManager.condition);
        SettingCursor(3, 42);
        printf("Because there is an object in the direction it is trying to move!");
        Sleep(1000);
        gameManager.isPassAPI = true;
        return 0;
    }
    Setting_Color(WHITE);
    SettingCursor(3, 41);
    printf("Pixelbot is Moving %s", gameManager.condition);
    SettingCursor(pixelBot.sw.posX, pixelBot.sw.posY);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    COORD coord = { x, y };
    pixelBot.sw.posX = x, pixelBot.sw.posY = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("▣");
    Sleep(500);
    if (pixelBot.sw.posX == gameManager.posFinishX && pixelBot.sw.posY == gameManager.posFinishY) {
        gameManager.isStageClear = true;
        gameManager.isPassAPI = true;
        return 0;
    }
}
