#include "pixelbot.h"

// pixelBot 구조체 전역 변수로 선언하기.
PixelBot pixelBot;

// pixelBot 초기화 함수.
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