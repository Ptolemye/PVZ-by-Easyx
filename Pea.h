#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include<list>
#include"EasyXPng.h"
class Pea {
public:
	int x;
	int y;
	int path;
	int wide = 16;
	int draw_step;
	IMAGE im_pea[4];
	bool hit_enemy = false;
	bool draw_over = false;
	DWORD t1;
	DWORD t2;
	Pea(int x,int y,int path) {
		this->x = x;
		this->y = y;
		this->path = path;
		draw_step = 1;
	}
	void Set_image() {
		TCHAR filename[40];
		for (int i = 1; i < 4; i++)
		{
			_stprintf_s(filename, _T("image\\Pea\\pea%d.png"), i);
			loadimage(&im_pea[i], filename);
		}
	}
	void draw() {
		if (hit_enemy) {
			t2 = GetTickCount();
			if (t2 - t1 > 100&&draw_step<=3) {
				draw_step++;
				t1 = t2;
			}
		}
		if (draw_step == 4)draw_over = true;
		if(!draw_over)putimagePng(x, y, &im_pea[draw_step]);
	}
};