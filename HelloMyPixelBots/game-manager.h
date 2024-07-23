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
	int posFinishX; // Finish Point의 position X값.
	int posFinishY; // Finish Point의 position Y값.
	boolean isStageClear;
	int selectChapterName; // 선택한 Chapter 이름.
	int selectStageName; // 선택한 Stage 이름.
	char* condition; // PixelBot의 이동 방향 (Up, Down, Left, Right)
	boolean isPassAPI; // step의 값이 높아 Dialog가 중복으로 생성 되는 것을 방지하기 위함 (문장이 step만큼 반복되어 출력됨).

}GameManager;

extern GameManager gameManager;

void Setting_Color();
void SettingCursor(int x, int y);
void MovingPixelBot(int x, int y);
void Initializing_GameManager();