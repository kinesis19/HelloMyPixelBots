#pragma once

typedef struct _Hardware {
	
	int levelHead;
	int levelArms;
	int levelBody;
	int levelLegs;
	int levelWeapon; // ���� ����

}Hardware;

typedef struct _Software {

	int credit; // Player�� ��ȭ.
	int level; // Player�� ����.
	int expNow; // ���� ����ġ.
	int expMax; // �ִ� ����ġ.
	int chapters[5][5]; // Player�� Chapter �� Stage Ŭ���� ����. e.x) Chapters[0][0] : Chapter1�� Stage1�� ����Ŵ.
	int selectChapter;
	int selectStage;
	int posX; // ���� Player(=PixelBot)�� position X��.
	int posY; // ���� Player(=PixelBot)�� position Y��.

}Software;

typedef struct _PixelBot {
	Hardware hw;
	Software sw;

}PixelBot;

extern PixelBot pixelBot;

void InitializingPixelBot();