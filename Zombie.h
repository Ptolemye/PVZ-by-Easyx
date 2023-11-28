#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "conio.h"
#include<list>
#include"EasyXPng.h"
#include"Map.h"
class Zombie {
public:
	int x;
	int y;
	int path;
	int draw_step;
	int draw_step_eating;
	int HP = 270;
	bool if_eating;
	DWORD draw_t1;
	DWORD draw_t2;
	static IMAGE im_zombie1[6];
	static IMAGE im_zombie1_eating[8];
	Zombie(int x,int y,int path) {
		this->x = x;
		this->y = y;
		this->path = path;
		draw_t1 = GetTickCount();
		draw_step = 1;
		draw_step_eating = 1;
		if_eating = false;
	}
	static void Set_image() {
		TCHAR filename[100];
		for (int i = 1; i < 6; i++)
		{
			_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Zombie\\state1\\image%d.png"), i);
			loadimage(&im_zombie1[i], filename);
		}
		for (int i = 1; i < 8; i++)
		{
			_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Zombie\\state1_eating\\image%d.png"), i);
			loadimage(&im_zombie1_eating[i], filename);
		}
	}
	void draw() {
		draw_t2 = GetTickCount();
		if (!if_eating) {
			putimagePng(x, y-40, &im_zombie1[draw_step]);
		}
		else {
			putimagePng(x, y-40, &im_zombie1_eating[draw_step_eating]);
		}
		//¶¯»­ÑÓÊ±
		if (draw_t2 - draw_t1 > 200) {
			if (!if_eating) {
				x -= 4;
				draw_step++;
			}
			else draw_step_eating++;
			draw_t1 = draw_t2;
		}
		if (draw_step == 6&& !if_eating)draw_step = 1;
		if (draw_step_eating == 8 && if_eating)draw_step_eating = 1;
	}
};

#endif 