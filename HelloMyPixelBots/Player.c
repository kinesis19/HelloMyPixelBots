#include "Player.h"

// Player ����ü ���� ������ �����ϱ�.
Player player;

// Player �ʱ�ȭ �Լ�.
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