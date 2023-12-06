#pragma once
#ifndef MAP_DRAW_H
#define MAP_DRAW_H
#include"Second_count.h"
using namespace std;
// 这里放置头文件的内容
void Map_draw() {
	map.draw();
	TCHAR score[10];
	_stprintf_s(score, _T("%d"), player.money);
	settextstyle(20, 0, _T("黑体"));
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(20, 65, score);
	setlinecolor(RGB(87, 25, 25));
	setfillcolor(RGB(87, 25, 25));
	fillrectangle(760, 500, 950, 540);
	setlinecolor(RGB(139, 69, 19));
	setfillcolor(RGB(139, 69, 19));
	fillrectangle(770, 510, 940, 530);
	setlinecolor(GREEN);
	setfillcolor(GREEN);
	double unit = (940.0- 770.0) / 180.0;
	int longth = unit * second_count();
	fillrectangle(770, 510, 770 + longth, 530);
	putimagePng(765+longth, 505, &head);
}
#endif