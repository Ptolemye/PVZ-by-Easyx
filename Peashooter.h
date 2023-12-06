#pragma once
#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include"Plant.h"
class Peashooter:public Plant {
private:
	IMAGE im_peashooter[12];
	IMAGE to_plant;
public:
	DWORD shoot_t1;
	DWORD shoot_t2;
	int shoot_step = 1;
	bool is_shooting = false;
	bool reload_over = false;
	Peashooter(int row, int col) :Plant(row, col) {
		type = 2;
		HP = 200;
		draw_step = 1;
		cold_count = 5;
		cold_time = 5;
		ready_to_plant = true;
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
		loadimage(&im_peashooter[9], _T("D:\\PVZ\\PVZ\\image\\Peashooter\\shoot1.png"));
		loadimage(&im_peashooter[10], _T("D:\\PVZ\\PVZ\\image\\Peashooter\\shoot2.png"));
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
		if (draw_step == 9&&!is_shooting)draw_step = 1;
		if (draw_step == 11) {
			draw_step = 1;
			reload_over = true;
		}
	}
	void to_plant_draw() {
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &to_plant);
	}
};
#endif
