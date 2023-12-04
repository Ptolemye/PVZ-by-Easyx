#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include<list>
#include"EasyXPng.h"
class Melon {
public:
	double x;
	double y;
	double vx;
	double vy=-4;
	int path;
	int wide = 16;
	int draw_step;
	IMAGE im_melon[7];
	bool hit_enemy = false;
	bool draw_over = false;
	DWORD t1;
	DWORD t2;
	Melon(int x, int y, int vx,int path) {
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->path = path;
		draw_step = 1;
	}
	void Set_image() {
		TCHAR filename[40];
		for (int i = 1; i < 7; i++)
		{
			_stprintf_s(filename, _T("image\\Melon\\image%d.png"), i);
			loadimage(&im_melon[i], filename);
		}
	}
	void draw() {
		if (hit_enemy) {
			t2 = GetTickCount();
			if (t2 - t1 > 100 && draw_step <= 3) {
				draw_step++;
				t1 = t2;
			}
		}
		if (draw_step == 7)draw_over = true;
		if (!draw_over)putimagePng(x, y, &im_melon[draw_step]);
	}
	void update() {
		x += vx;
		y += vy;
		vy += 0.1;
	}
};