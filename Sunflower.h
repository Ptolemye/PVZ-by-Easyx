#pragma once
#include"Plant.h"
using namespace std;
class Sunflower:public Plant
{
private:
	IMAGE im_sunflower[9];
	IMAGE to_plant;
	DWORD produce_t1;
	DWORD produce_t2;
public:
	Sunflower(int row,int col) :Plant(row,col) {
		type = 1;
		HP = 100;
		cost = 50;
		cold_time = 5;
		cold_count = 5;
		ready_to_plant = true;
		draw_step = 1;
		draw_t1 = GetTickCount();
		produce_t1 = GetTickCount();
	}
	//设置图像
	void Set_image() {
		TCHAR filename[40];
		for (int i = 1; i < 9; i++)
		{
			_stprintf_s(filename, _T("image\\Sunflower\\SF%d.png"), i);
			loadimage(&im_sunflower[i], filename);
		}
		_stprintf_s(filename, _T("image\\Sunflower\\to_plant.png"));
		loadimage(&to_plant, filename);
	}
	//动画效果
	void draw() {
		draw_t2 = GetTickCount();
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH ,&im_sunflower[draw_step]);
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
	//生产阳光
	bool produce_sun() {
		produce_t2 = GetTickCount();
		if (produce_t2 - produce_t1 > 15000) {
			produce_t1 = produce_t2;
			return true;
		}
		else return false;
	}
};


