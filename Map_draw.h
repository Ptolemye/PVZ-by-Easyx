#pragma once
#ifndef MAP_DRAW_H
#define MAP_DRAW_H
#include"variable_setup.h"
using namespace std;
// 这里放置头文件的内容
void Map_draw() {
	map.draw();
	TCHAR score[5];
	_stprintf_s(score, _T("%d"), player.money);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(28, 65, score);
}
#endif