#pragma once
#include"Plant.h"
using namespace std;
class Potato :public Plant
{
private:
	IMAGE im_potato[9];
	IMAGE im_boom[11];
	IMAGE to_plant;
	DWORD prepare_t1;
	DWORD prepare_t2;
	
	
public:
	bool ready_to_boom = false;
	bool is_boom = false;
	int boom_step = 1;
	Potato(int row, int col) :Plant(row, col) {
		type = 5;
		HP = 100;
		cost = 50;
		cold_time = 5;
		cold_count = 5;
		ready_to_plant = true;
		draw_step = 1;
		draw_t1 = GetTickCount();
		prepare_t1 = GetTickCount();
	}
	//设置图像
	void Set_image() {
		TCHAR filename[40];
		for (int i = 1; i < 9; i++)
		{
			_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Potato\\image%d.png"), i);
			loadimage(&im_potato[i], filename);
		}
		for (int i = 1; i < 10; i++)
		{
			_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Potato\\boom%d.png"), i);
			loadimage(&im_boom[i], filename);
		}
		_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Potato\\to_plant.png"));
		loadimage(&to_plant, filename);
	}
	//动画效果
	void draw() {
		draw_t2 = GetTickCount();
		if(!ready_to_boom)prepare_t2 = GetTickCount();
		if (is_boom) {
			int img_wide = im_boom[boom_step].getwidth() / 2-36;
			int img_height= im_boom[boom_step].getheight();
			putimagePng(start_x + col * LENGTH-img_wide, start_y + (row+1) * WIDTH-img_height, &im_boom[boom_step]);
		}
		if (prepare_t2 - prepare_t1 >= 10000)ready_to_boom = true;
		if (ready_to_boom&&!is_boom)putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &im_potato[draw_step]);
		else if(!is_boom)putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &im_potato[1]);
		//动画延时
		if (draw_t2 - draw_t1 > 150) {
			draw_step++;
			if (is_boom)boom_step++;
			draw_t1 = draw_t2;
		}
		if (draw_step == 9)draw_step = 4;
		if (boom_step == 10)HP = 0;
	}
	void to_plant_draw() {
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &to_plant);
	}
};


