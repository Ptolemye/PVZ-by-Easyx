#pragma once
#include"Plant.h"
using namespace std;
class Wallnut :public Plant
{
private:
	IMAGE im_wallnut[6];
	IMAGE to_plant;
public:
	Wallnut(int row, int col) :Plant(row, col) {
		type = 3;
		HP = 50;
		cost = 50;
		draw_step = 1;
		draw_t1 = GetTickCount();
	}
	//设置图像
	void Set_image() {
		TCHAR filename[80];
		for (int i = 1; i < 6; i++)
		{
			_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Wallnut\\image%d.png"), i);
			loadimage(&im_wallnut[i], filename);
		}
		_stprintf_s(filename, _T("D:\\PVZ\\PVZ\\image\\Wallnut\\to_plant.png"));
		loadimage(&to_plant, filename);
	}
	//动画效果
	void draw() {
		draw_t2 = GetTickCount();
		putimagePng(start_x + col * LENGTH, start_y + row * WIDTH, &im_wallnut[draw_step]);
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


