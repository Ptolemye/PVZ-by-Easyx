#pragma once
#include"Plant.h"
using namespace std;
class Watermelon :public Plant
{
private:
	IMAGE im_watermelon[14];
	IMAGE to_plant;
	
public:
	bool reload_over = false;
	bool is_shooting = false;
	bool reload_once = true;
	Watermelon(int row, int col) :Plant(row, col) {
		type = 1;
		HP = 300;
		cost = 300;
		cold_time = 10;
		cold_count = 10;
		ready_to_plant = true;
		draw_step = 1;
		draw_t1 = GetTickCount();
	}
	//设置图像
	void Set_image() {
		TCHAR filename[50];
		for (int i = 1; i < 14; i++)
		{
			_stprintf_s(filename, _T("image\\Watermelon\\image%d.png"), i);
			loadimage(&im_watermelon[i], filename);
		}
		_stprintf_s(filename, _T("image\\Watermelon\\to_plant.png"));
		loadimage(&to_plant, filename);
	}
	//动画效果
	void draw() {
		draw_t2 = GetTickCount();
		int img_wide = im_watermelon[draw_step].getwidth();
		int img_height = im_watermelon[draw_step].getheight();
		putimagePng(start_x + (col + 1) * LENGTH - img_wide, start_y + (row + 1) * WIDTH - img_height, &im_watermelon[draw_step]);
		//动画延时
		if (draw_t2 - draw_t1 > 150) {
			draw_step++;
			draw_t1 = draw_t2;
		}
		if (draw_step == 7&& !is_shooting)draw_step = 1;
		if (draw_step == 10&&reload_once)reload_over = true;
		if (draw_step == 13) {
			draw_step = 1;
			reload_once = true;
		}
	}
	void to_plant_draw() {
		int img_wide = im_watermelon[draw_step].getwidth();
		int img_height = im_watermelon[draw_step].getheight();
		putimagePng(start_x + (col+1) * LENGTH-img_wide, start_y + (row+1) * WIDTH-img_height, &to_plant);
	}
};


