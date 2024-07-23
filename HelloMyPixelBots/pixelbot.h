#pragma once

typedef struct _Hardware {
	
	int levelHead;
	int levelArms;
	int levelBody;
	int levelLegs;
	int levelWeapon; // 무기 레벨

}Hardware;

typedef struct _Software {

	int credit; // Player의 재화.
	int level; // Player의 레벨.
	int expNow; // 현재 경험치.
	int expMax; // 최대 경험치.
	int chapters[5][5]; // Player의 Chapter 및 Stage 클리어 정보. e.x) Chapters[0][0] : Chapter1의 Stage1을 가리킴.
	int selectChapter;
	int selectStage;
	int posX; // 현재 Player(=PixelBot)의 position X값.
	int posY; // 현재 Player(=PixelBot)의 position Y값.

}Software;

typedef struct _PixelBot {
	Hardware hw;
	Software sw;

}PixelBot;

extern PixelBot pixelBot;

void InitializingPixelBot();