#include "Player.h"

// Player 구조체 전역 변수로 선언하기.
Player player;

// Player 초기화 함수.
void InitializingPlayer() {

	player.credit = 0;
	player.level = 1;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			player.chapters[i][j] = 0;
		}
	}
	player.selectChapter = 0;
	player.selectStage = 0;
	player.posX = 0;
	player.posY = 0;
	player.posFinishX = 0;
	player.posFinishY = 0;
}