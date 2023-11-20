#pragma once
#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include"Plant.h"
class Peashooter:public Plant {
private:
	IMAGE im_peashooter[10];
	IMAGE to_plant;
	IMAGE shooting[5];
public:
	DWORD shoot_t1;
	DWORD shoot_t2;
	Peashooter(int row, int col) :Plant(row, col) {
		type = 2;
		HP = 10;
		draw_step = 1;
		cost = 100;
		draw_t1 = GetTickCount();
		shoot_t1 = GetTickCount();
	}
	//设置图像
	void Set_image() {
		TCHAR filename[80];
		for (int i = 1; i < 9; i++)
		{
			_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Peashooter\\image%d.png"), i);
			loadimage(&im_peashooter[i], filename);
		}
		_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Peashooter\\to_plant.png"));
		loadimage(&to_plant, filename);
	}
	//动画效果
	void draw() {
		draw_t2 = GetTickCount();
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &im_peashooter[draw_step]);
		//动画延时
		if (draw_t2 - draw_t1 > 150) {
			draw_step++;
			draw_t1 = draw_t2;
		}
		if (draw_step == 9)draw_step = 1;
	}
	void to_plant_draw() {
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &to_plant);
	}
};
#endif
