#pragma once
#ifndef MAP_DRAW_H
#define MAP_DRAW_H
#include"variable_setup.h"
using namespace std;
// �������ͷ�ļ�������
void Map_draw() {
	map.draw();
	TCHAR score[5];
	_stprintf_s(score, _T("%d"), player.money);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(28, 65, score);
}
#endif