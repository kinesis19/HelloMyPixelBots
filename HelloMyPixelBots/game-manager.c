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
#include "Player.h"

// GameManager 구조체 전역 변수로 선언하기.
GameManager gameManager;

void Initializing_GameManager();
void Setting_Color();
void SettingCursor(int x, int y);
void MovingPixelBot(int x, int y);

void Initializing_GameManager() {
    gameManager.posFinishX = 0;
    gameManager.posFinishY = 0;
    gameManager.isStageClear = false;
}

void Setting_Color(enum ColorType color) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

void SettingCursor(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void MovingPixelBot(int x, int y) {
    SettingCursor(player.posX, player.posY);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    COORD coord = { x, y };
    player.posX = x, player.posY = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("▣");
    Sleep(500);
    if (player.posX == gameManager.posFinishX && player.posY == gameManager.posFinishY) {
        gameManager.isStageClear = true;
        return 0;
    }
}
