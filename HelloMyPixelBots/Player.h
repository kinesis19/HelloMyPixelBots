#pragma once

typedef struct _Player {

	int credit; // Player의 재화.
	int level; // Player의 레벨.
	int chapters[5][5]; // Player의 Chapter 및 Stage 클리어 정보. e.x) Chapters[0][0] : Chapter1의 Stage1을 가리킴.
	int selectChapter;
	int selectStage;

}Player;

extern Player player;

void InitializingPlayer();