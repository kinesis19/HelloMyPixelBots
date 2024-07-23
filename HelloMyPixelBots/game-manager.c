// ���� ��� �����ϱ�.
#define _CRT_SECURE_NO_WARNINGS

// ������� �����ϱ�.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// ������� �����ϱ�
#include "game-manager.h"
#include "Player.h"
#include "stage-list.h"

// GameManager ����ü ���� ������ �����ϱ�.
GameManager gameManager;

void Initializing_GameManager();
void Setting_Color();
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
    if(Detecting_Objects(x, y, '��') == 1){ // ��ֹ��� ���� ��� �̵��� ������.
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
    SettingCursor(player.posX, player.posY);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    COORD coord = { x, y };
    player.posX = x, player.posY = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("��");
    Sleep(500);
    if (player.posX == gameManager.posFinishX && player.posY == gameManager.posFinishY) {
        gameManager.isStageClear = true;
        gameManager.isPassAPI = true;
        return 0;
    }
}
