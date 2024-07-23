﻿// 헤더파일 선언하기.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

// 소스코드 참조하기.
#include "lobby.h"
#include "pixelbot.h"
#include "game-manager.h"

// 필요한 상수 선언하기.
#define UP 72
#define DOWN 80
#define ENTER 13

// 사용자 지정 함수 프로토타입 선언하기.
void HidingCursor();

int main() {
    // 콘솔 창의 핸들을 가져오기.
    HWND consoleWindow = GetConsoleWindow();
    // 현재 창의 스타일을 가져오기.
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    // 크기 조절 박스와 최대화 박스 스타일을 제거하여 크기 조절을 비활성화하기.
    style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX);
    // 수정된 스타일을 설정하기.
    SetWindowLong(consoleWindow, GWL_STYLE, style);
    // 콘솔 창의 사이즈는 200 * 50 size로 지정하기.
    system("mode con:cols=200 lines=50");

    // Player Data 초기화하기.
    InitializingPixelBot();

    system("cls");
    // ■ 하나 : 2칸 확보.
    // Title Line_1
    printf("\n\n\n");
    printf("\t\t\t\t\t\t■■      ■■                ■■  ■■                      ■■        ■■\n"); // 10
    printf("\t\t\t\t\t\t■■      ■■                ■■  ■■                      ■■■    ■■■\n");
    printf("\t\t\t\t\t\t■■      ■■                ■■  ■■                      ■■■■■■■■\n");
    printf("\t\t\t\t\t\t■■      ■■      ■■      ■■  ■■      ■■            ■■  ■■  ■■\n"); // 7
    printf("\t\t\t\t\t\t■■■■■■■    ■■■■    ■■  ■■    ■■■■          ■■  ■■  ■■\n"); 
    printf("\t\t\t\t\t\t■■■■■■■  ■■    ■■  ■■  ■■  ■■    ■■        ■■        ■■    ■    ■\n"); 
    printf("\t\t\t\t\t\t■■      ■■  ■■■■■■  ■■  ■■  ■■    ■■        ■■        ■■  ■■    ■■\n");
    printf("\t\t\t\t\t\t■■      ■■  ■■          ■■  ■■  ■■    ■■        ■■        ■■  ■■    ■■\n");
    printf("\t\t\t\t\t\t■■      ■■    ■■■■    ■■  ■■    ■■■■          ■■        ■■  ■■■■■■\n");
    printf("\t\t\t\t\t\t■■      ■■      ■■        ■■  ■■    ■■            ■■        ■■    ■■■■■\n"); // 1
    printf("\t\t\t\t\t\t                                                                                        ■■\n"); // 0
    printf("\t\t\t\t\t\t                                                                                        ■■\n"); // 0
    printf("\t\t\t\t\t\t                                                                                      ■■■\n"); // 0
    printf("\t\t\t\t\t\t                                                                                    ■■■\n"); // 0
    printf("\t\t\t\t\t\t                                                                                ■■■■\n"); // 0
    
    // Title Line_2
    printf("\t\t\t\t\t\t■■■■      ■■                              ■■        ■■■■■■\n"); // 10
    printf("\t\t\t\t\t\t■■■■■    ■■                              ■■        ■■■■■■\n");
    printf("\t\t\t\t\t\t■■    ■■                                    ■■        ■■      ■■\n");
    printf("\t\t\t\t\t\t■■    ■■  ■■  ■■    ■■      ■■      ■■        ■■      ■■      ■■          ■■      ■■■■■■\n"); // 7
    printf("\t\t\t\t\t\t■■■■■    ■■  ■■    ■■    ■■■■    ■■        ■■■■■■      ■■■■        ■■      ■■    ■■\n");
    printf("\t\t\t\t\t\t■■■■      ■■  ■■■■■■  ■■    ■■  ■■        ■■■■■■    ■■    ■■  ■■■■■■  ■■  \n");
    printf("\t\t\t\t\t\t■■          ■■    ■■■■    ■■■■■■  ■■        ■■      ■■  ■■    ■■      ■■      ■■■■■■\n");
    printf("\t\t\t\t\t\t■■          ■■  ■■■■■■  ■■          ■■        ■■      ■■  ■■    ■■      ■■              ■■\n");
    printf("\t\t\t\t\t\t■■          ■■  ■■    ■■    ■■■■    ■■        ■■■■■■      ■■■■        ■■      ■■    ■■\n");
    printf("\t\t\t\t\t\t■■          ■■  ■■    ■■      ■■        ■■      ■■■■■■        ■■          ■■■■  ■■■■■■\n");

    // 버튼 출력하기.
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t[1]Game Start\n\n");
    /*printf("\t\t\t\t\t\t\t\t\t\t\t[2]Load Game(Next Update)\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t[3]Settings(Next Update)\n\n");*/
    printf("\t\t\t\t\t\t\t\t\t\t\t[2]Exit\n\n\n\n\n\n");

    printf("\t\t\t\t\t\t\t\t↑ : Choose Top | ↓ : Choose Down | Enter : Select |");

    // 변수 선언하기.
    int curCnt = 1;


    // 키보드 입력 받기.
    char inputKb;
    while (1) {
        HidingCursor();
        if (_kbhit()) {
            inputKb = _getch(); // VS 컴파일 에러 방지를 위해 getch() 대신 _getch() 사용. 
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
                }else if(curCnt == 2){
                    system("cls");
                    printf("\n\n게임을 종료하였습니다.\n\n");
                    return 0;
                    break;
                }
            default:
                break;
            }
        }
        // 화살표 출력 초기화 하기.
        for (int i = 0; i < 4; i++) {
            SettingCursor(85, 32 + i * 2);
            printf(" ");
        }
        // 현재 선택된 곳만 화살표 출력하기.
        SettingCursor(85, 30 + curCnt * 2);
        printf(">");
    }

    return 0;
}

void HidingCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &cursorInfo);
}
