#pragma once
#include"Plant.h"
using namespace std;
class Wallnut :public Plant
{
private:
	IMAGE im_wallnut1[6];
	IMAGE im_wallnut2[6];
	IMAGE im_wallnut3[6];
	IMAGE to_plant;
public:
	Wallnut(int row, int col) :Plant(row, col) {
		type = 3;
		HP = 1500;
		cost = 50;
		draw_step = 1;
		ready_to_plant = true;
		cold_time = 30;
		cold_count = 30;
		draw_t1 = GetTickCount();
	}
	//设置图像
	void Set_image() {
		TCHAR filename[80];
		for (int i = 1; i < 6; i++)
		{
			_stprintf_s(filename, _T("image\\Wallnut\\state1\\image%d.png"), i);
			loadimage(&im_wallnut1[i], filename);
		}
		for (int i = 1; i < 6; i++)
		{
			_stprintf_s(filename, _T("image\\Wallnut\\state2\\image%d.png"), i);
			loadimage(&im_wallnut2[i], filename);
		}
		for (int i = 1; i < 6; i++)
		{
			_stprintf_s(filename, _T("image\\Wallnut\\state3\\image%d.png"), i);
			loadimage(&im_wallnut3[i], filename);
		}
		_stprintf_s(filename, _T("image\\Wallnut\\to_plant.png"));
		loadimage(&to_plant, filename);
	}
	//动画效果
	void draw() {
		draw_t2 = GetTickCount();
		if(HP>1000)putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &im_wallnut1[draw_step]);
		if (HP > 500&&HP<=1000)putimagePng(start_x + col * LENGTH+10, start_y + row * WIDTH+10, &im_wallnut2[draw_step]);
		if (HP <=500)putimagePng(start_x + col * LENGTH+10, start_y + row * WIDTH+15, &im_wallnut3[draw_step]);
		//动画延时
		if (draw_t2 - draw_t1 > 150) {
			draw_step++;
			draw_t1 = draw_t2;
		}
		if (draw_step == 6)draw_step = 1;
	}
	void to_plant_draw() {
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &to_plant);
	}
};


