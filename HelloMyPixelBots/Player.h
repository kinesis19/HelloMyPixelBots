#pragma once

typedef struct _Player {

	int credit; // Player�� ��ȭ.
	int level; // Player�� ����.
	int chapters[5][5]; // Player�� Chapter �� Stage Ŭ���� ����. e.x) Chapters[0][0] : Chapter1�� Stage1�� ����Ŵ.
	int selectChapter;
	int selectStage;

}Player;

extern Player player;

void InitializingPlayer();