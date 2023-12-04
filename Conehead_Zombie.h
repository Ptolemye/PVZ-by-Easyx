#pragma once
#pragma once
#ifndef CONEHEAD_ZOMBIE_H
#define CONEHEAD_ZOMBIE_H
#include "conio.h"
#include<list>
#include"EasyXPng.h"
#include"Map.h"
class Conehead_Zombie {
public:
	int x;
	int y;
	int path;
	int draw_step;
	int draw_step_eating;
	int HP = 630;
	bool if_eating;
	//bool draw_over = false;
	bool dead = false;
	DWORD draw_t1;
	DWORD draw_t2;
	static IMAGE im_zombie1[6];
	static IMAGE im_zombie1_eating[8];
	static IMAGE im_zombie2[6];
	static IMAGE im_zombie2_eating[8];
	static IMAGE im_zombie3[6];
	static IMAGE im_zombie3_eating[8];
	Conehead_Zombie(int x, int y, int path) {
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
			_stprintf_s(filename, _T("image\\Conehead_Zombie\\state1\\image%d.png"), i);
			loadimage(&im_zombie1[i], filename);
		}
		for (int i = 1; i < 8; i++)
		{
			_stprintf_s(filename, _T("image\\Conehead_Zombie\\state1_eating\\image%d.png"), i);
			loadimage(&im_zombie1_eating[i], filename);
		}
		for (int i = 1; i < 6; i++)
		{
			_stprintf_s(filename, _T("image\\Conehead_Zombie\\state2\\image%d.png"), i);
			loadimage(&im_zombie2[i], filename);
		}
		for (int i = 1; i < 8; i++)
		{
			_stprintf_s(filename, _T("image\\Conehead_Zombie\\state2_eating\\image%d.png"), i);
			loadimage(&im_zombie2_eating[i], filename);
		}
		for (int i = 1; i < 6; i++)
		{
			_stprintf_s(filename, _T("image\\Conehead_Zombie\\state3\\image%d.png"), i);
			loadimage(&im_zombie3[i], filename);
		}
		for (int i = 1; i < 8; i++)
		{
			_stprintf_s(filename, _T("image\\Conehead_Zombie\\state3_eating\\image%d.png"), i);
			loadimage(&im_zombie3_eating[i], filename);
		}
	}
	void draw() {
		draw_t2 = GetTickCount();
		if (!if_eating) {
			if (HP >= 510)putimagePng(x, y - 60, &im_zombie1[draw_step]);
			if (HP < 510 && HP>=390)putimagePng(x, y - 60, &im_zombie2[draw_step]);
			if (HP < 390 && HP>270)putimagePng(x, y - 60, &im_zombie3[draw_step]);
		}
		else {
			if (HP >= 510)putimagePng(x, y - 60, &im_zombie1_eating[draw_step_eating]);
			if (HP < 510 && HP>=390)putimagePng(x, y - 60, &im_zombie2_eating[draw_step_eating]);
			if (HP < 390 && HP>270)putimagePng(x, y - 60, &im_zombie3_eating[draw_step_eating]);
		}
		//if (HP <= 0)putimagePng(x, y - 40, &im_zombie3[draw_step]);
		//¶¯»­ÑÓÊ±
		if (draw_t2 - draw_t1 > 200) {
			if (!if_eating || HP <= 0) {
				x -= 4;
				draw_step++;
			}
			else draw_step_eating++;
			draw_t1 = draw_t2;
		}
		if (draw_step == 6 && !if_eating && HP > 0)draw_step = 1;
		if (draw_step_eating == 8 && if_eating && HP > 0)draw_step_eating = 1;
		/*if (HP <= 0) {
			if (draw_step == 14)draw_over = true;
		}*/
	}
};

#endif 