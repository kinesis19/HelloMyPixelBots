#include "Player.h"

// Player ����ü ���� ������ �����ϱ�.
Player player;

// Player �ʱ�ȭ �Լ�.
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

}