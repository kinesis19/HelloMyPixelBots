#pragma once
enum ColorType {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_PURPLE,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	PURPLE,
	YELLOW,
	WHITE
};

typedef struct _GameManager {
	int posFinishX; // Finish Point�� position X��.
	int posFinishY; // Finish Point�� position Y��.
	boolean isStageClear;
	int selectChapterName; // ������ Chapter �̸�.
	int selectStageName; // ������ Stage �̸�.
	char* condition; // PixelBot�� �̵� ���� (Up, Down, Left, Right)
	boolean isPassAPI; // step�� ���� ���� Dialog�� �ߺ����� ���� �Ǵ� ���� �����ϱ� ���� (������ step��ŭ �ݺ��Ǿ� ��µ�).

}GameManager;

extern GameManager gameManager;

void Setting_Color();
void SettingCursor(int x, int y);
void MovingPixelBot(int x, int y);
void Initializing_GameManager();