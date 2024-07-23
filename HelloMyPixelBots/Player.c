#include "Player.h"

// Player 구조체 전역 변수로 선언하기.
Player player;

// Player 초기화 함수.
void InitializingPlayer() {

	player.sw.credit = 0;
	player.sw.level = 1;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			player.sw.chapters[i][j] = 0;
		}
	}
	player.sw.selectChapter = 0;
	player.sw.selectStage = 0;
	player.sw.posX = 0;
	player.sw.posY = 0;
}