#pragma once
#include"variable_setup.h"
#include"EasyXPng.h"
void Start() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			map.box_set(i, j, 0);
		}
	}
	sunflower_function.cost = 50;
	Peashooter_function.cost = 100;
	wallnut_function.cost = 50;
	double_peashooter_function.cost = 200;
	potato_function.cost = 25;
	watermelon_function.cost = 300;
	start_time = GetTickCount();
		time_passed = 0;
		sun_list.clear();
		peashooter_list.clear();
		wallnut_list.clear();
		sunflower_list.clear();
		potato_list.clear();
		double_peashooter_list.clear();
		watermelon_list.clear();
		zombie_list.clear();
		conehead_zombie_list.clear();
		bucked_zombie_list.clear();
		pea_list.clear();
		melon_list.clear();
		Peashooter_function.cold_count =0;
		wallnut_function.cold_count = 0;
		sunflower_function.cold_count = 0;
		potato_function.cold_count = 0;
		double_peashooter_function.cold_count = 0;
		watermelon_function.cold_count = 0;
		lost = false;
		win = false;
		player.money = 50;
		putimagePng(0, 0, &im_start);
		putimagePng(480, 450, &button);
		putimagePng(580, 450, &button);
		putimagePng(680, 450, &button);
		putimagePng(420, 380, &im_txt);//420,380
		putimagePng(780, 450, &button1);
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, _T("Ó×Ô²"));
		outtextxy(530, 390, _T("ÇëÑ¡Ôñ¹Ø¿¨"));
		outtextxy(510, 475, _T("1"));
		outtextxy(610, 475, _T("2"));
		outtextxy(710, 475, _T("3"));
		outtextxy(810, 475, _T("ÓÎÍæÐëÖª"));
		int x = player.get_mouse_x();
		int y = player.get_mouse_y();
		player.fresh_mouse_location();
		if (player.if_click()) {
			if (x>480&&x<560&&y>450&&y<530) {
				game = 1;
			}
			if (x > 580 && x < 660 && y>450 && y < 530) {
				game = 2;
			}
			if (x > 680 && x < 760 && y>450 && y < 530) {
				game = 3;
				player.money = 300;
				sunflower_function.cost = 0;
				Peashooter_function.cost = 0;
				wallnut_function.cost = 0;
				double_peashooter_function.cost = 0;
				potato_function.cost = 0;
				watermelon_function.cost = 0;
			}
			if (x > 810 && x < 1000 && y>450 && y < 540) {
				game = -1;
			}
		}
		
}