#include "pixelbot.h"

// pixelBot ����ü ���� ������ �����ϱ�.
PixelBot pixelBot;

// pixelBot �ʱ�ȭ �Լ�.
void InitializingPixelBot() {

	pixelBot.sw.credit = 0;
	pixelBot.sw.level = 1;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			pixelBot.sw.clearChapters[i][j] = 0;
		}
	}
	pixelBot.sw.selectChapter = 0;
	pixelBot.sw.selectStage = 0;
	pixelBot.sw.posX = 0;
	pixelBot.sw.posY = 0;
	pixelBot.sw.expNow = 0;
	pixelBot.sw.expMax = 10;
}