#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include"Map.h"
#include"Player.h"
#include"variable_setup.h"
template<typename T>
void Plant_help(int row, int col, int type,std::list<T>& obj_list) {
	T obj(row, col);
	obj.Set_image();
	obj_list.push_back(obj);
	map.box_set(row, col, type);
	player.money -= obj.Get_cost();
}
template<typename T>
void abolish_help(int row, int col, std::list<T>& obj_list) {
	auto p = obj_list.begin();
	while (p != obj_list.end()) {
		if (p->row == row && p->col == col)p=obj_list.erase(p);
		else p++;
	}
	map.box_set(row, col, 0);
}
template<typename T>
void to_plant_draw(int row, int col) {
	T p(row, col);
	p.Set_image();
	p.to_plant_draw();
}
void Plant_sow(int type) {
	player.fresh_mouse_location();
	int x = player.get_mouse_x();
	int y = player.get_mouse_y();
	int row = map.get_box_row(x, y);
	int col = map.get_box_col(x, y);
	
	//
	if (!map.is_box_planted(row, col) && map.in_box(row, col)) {
		if (type == 1)to_plant_draw<Sunflower>(row, col);
		if (type == 2)to_plant_draw<Peashooter>(row, col);
		if (type == 3)to_plant_draw<Wallnut>(row, col);
		if (type == 4)to_plant_draw<Double_Peashooter>(row, col);
		if (type == 5)to_plant_draw<Potato>(row, col);
		if (type == 6)to_plant_draw<Watermelon>(row, col);
	}
	if (type == 8)putimagePng(x-30, y-60, &cardlist.im_sf1[8]);
	if (player.if_click()) {
		//ʰȡ����
		auto p = sun_list.begin();
		while (p != sun_list.end()) {
			int mouse_x = player.get_mouse_x();
			int mouse_y = player.get_mouse_y();
			if (mouse_x > p->x && mouse_x< p->x + 40 && mouse_y > p->y && mouse_y < p->y + 40) {
				sun_list.erase(p++);
				player.money += 25;
				player.fresh_mouse_location();
				sow_lock = true;
				card_elected = -1;
			}
			else p++;
		}
		//ȷ����ͼ��δ����ֲ��������ڲ�ƺ��
		if (!map.is_box_planted(row, col)&&map.in_box(row,col) && !sow_lock) {
			//��ֲ���տ�
			if (type==1&&player.money>=50&&sunflower_function.ready_to_plant) {
				Plant_help(row, col, 1, sunflower_list);
				sunflower_function.ready_to_plant = false;
			}
			//��ֲ�㶹����
			if (type == 2&&player.money >= 100&&Peashooter_function.ready_to_plant) {
				Plant_help(row, col, 2, peashooter_list);
				Peashooter_function.ready_to_plant = false;
			}
			//�ּ��
			if (type == 3 && player.money >= 50&&wallnut_function.ready_to_plant) {
				Plant_help(row, col, 3, wallnut_list);
				wallnut_function.ready_to_plant = false;
			}
			//��ֲ˫������
			if (type == 4 && player.money >= 200 && double_peashooter_function.ready_to_plant) {
				Plant_help(row, col, 4, double_peashooter_list);
				double_peashooter_function.ready_to_plant = false;
			}
			//��ֲ����
			if (type == 5 && player.money >= 25 && potato_function.ready_to_plant) {
				Plant_help(row, col, 5, potato_list);
				potato_function.ready_to_plant = false;
			}
			//��ֲ����
			if (type == 6 && player.money >= 300 && watermelon_function.ready_to_plant) {
				Plant_help(row, col, 6, watermelon_list);
				watermelon_function.ready_to_plant = false;
			}
		}
		//ȥ��ֲ��
		if (type == 8) {
			if (map.is_box_planted(row, col) && map.in_box(row, col)) {
				int temp_type = map.box_get(row, col);
				if (temp_type == 1)abolish_help(row,col,sunflower_list);
				if (temp_type == 2)abolish_help(row,col,peashooter_list);
				if(temp_type == 3)abolish_help(row, col, wallnut_list);
				if (temp_type == 4)abolish_help(row, col, double_peashooter_list);
				if (temp_type == 5)abolish_help(row, col, potato_list);
				if (temp_type == 6)abolish_help(row, col, watermelon_list);
			}
		}
		
	}

}
