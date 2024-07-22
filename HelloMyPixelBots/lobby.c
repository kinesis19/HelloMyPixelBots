// ������� �����ϱ�.
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

void SettingGUI_Lobby();
static void SettingCursor(int x, int y);
static void SettingGUI_Lobby_Layout_Base();
static void SettingGUI_Lobby_Layout_Dialog();
static void SettingGUI_Lobby_Layout_Chapters();
static void SettingGUI_Lobby_Layout_Chapter_1();

void Lobby() {
	// �ܼ�â �ʱ�ȭ�ϱ�.
	system("cls");
	// �ܼ�â GUI Setting�ϱ�.
	SettingGUI_Lobby();
	_getch();
}

// Lobby GUI Setting�ϱ�.
void SettingGUI_Lobby() {
	// Base Layout �����ϱ�.
	SettingGUI_Lobby_Layout_Base();

	// 2. Dialog Layout �����ϱ�.
	SettingGUI_Lobby_Layout_Dialog();

	// 3. Chapters Layout �����ϱ�.
	SettingGUI_Lobby_Layout_Chapters();

}

static void SettingCursor(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

