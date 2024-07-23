#pragma once

typedef struct _Player {

	int credit; // Player�� ��ȭ.
	int level; // Player�� ����.
	int chapters[5][5]; // Player�� Chapter �� Stage Ŭ���� ����. e.x) Chapters[0][0] : Chapter1�� Stage1�� ����Ŵ.
	int selectChapter;
	int selectStage;
	int posX; // ���� Player(=PixelBot)�� position X��.
	int posY; // ���� Player(=PixelBot)�� position Y��.
	int posFinishX; // Finish Point�� position X��.
	int posFinishY; // Finish Point�� position Y��.

}Player;

extern Player player;

void InitializingPlayer();