#pragma once

typedef struct _Player {

	int credit; // Player의 재화.
	int level; // Player의 레벨.
	int chapters[5][5]; // Player의 Chapter 및 Stage 클리어 정보. e.x) Chapters[0][0] : Chapter1의 Stage1을 가리킴.
	int selectChapter;
	int selectStage;
	int posX; // 현재 Player(=PixelBot)의 position X값.
	int posY; // 현재 Player(=PixelBot)의 position Y값.
	int posFinishX; // Finish Point의 position X값.
	int posFinishY; // Finish Point의 position Y값.

}Player;

extern Player player;

void InitializingPlayer();