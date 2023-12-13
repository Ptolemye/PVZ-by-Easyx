#pragma once
#ifndef DOUBLE_PEASHOOTER_H
#define DOUBLE_PEASHOOTER_H
#include"Plant.h"
class Double_Peashooter :public Plant {
private:
	IMAGE im_peashooter[9];
	IMAGE to_plant;
public:
	DWORD shoot_t1;
	DWORD shoot_t2;
	int shoot_step = 1;
	bool is_shooting = false;
	bool reload_over = false;
	Double_Peashooter(int row, int col) :Plant(row, col) {
		type = 4;
		HP = 200;
		draw_step = 1;
		cold_count = 10;
		cold_time = 10;
		ready_to_plant = true;
		cost = 200;
		draw_t1 = GetTickCount();
		shoot_t1 = GetTickCount();
	}
	//设置图像
	void Set_image() {
		TCHAR filename[80];
		for (int i = 1; i < 6; i++)
		{
			_stprintf_s(filename, _T("image\\Double_peashooter\\image%d.png"), i);
			loadimage(&im_peashooter[i], filename);
		}
		loadimage(&im_peashooter[6], _T("image\\Double_peashooter\\shoot1.png"));
		loadimage(&im_peashooter[7], _T("image\\Double_peashooter\\shoot2.png"));
		_stprintf_s(filename, _T("image\\Double_peashooter\\to_plant.png"));
		loadimage(&to_plant, filename);
	}
	//动画效果
	void draw() {
		draw_t2 = GetTickCount();
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &im_peashooter[draw_step]);
		//动画延时
		if (draw_t2 - draw_t1 > 200) {
			draw_step++;
			draw_t1 = draw_t2;
		}
		if (draw_step == 6 && !is_shooting)draw_step = 1;
		if (draw_step == 8) {
			draw_step = 1;
			reload_over = true;
		}
	}
	void to_plant_draw() {
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &to_plant);
	}
};
#endif
