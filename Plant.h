#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include<list>
#include"EasyXPng.h"
#include"Map.h"
class Plant {
public:
	int HP;
	int cost;
	int type;
	int row;
	int col;
	int draw_step;
	DWORD draw_t1;
	DWORD draw_t2;
	DWORD cold_t1;//用于冷却计时
	DWORD cold_t2;
	bool ready_to_plant;
	int cold_count;
	int cold_time;
public:
	Plant(int row,int col){
		this->row = row;
		this->col = col;
	}
	int Get_cost() {
		return cost;
	}
	void colding() {
		if (cold_count == 0) {
			ready_to_plant = true;
			cold_count = cold_time;
		}
		if (!ready_to_plant) {
			cold_t2 = GetTickCount();
			if (cold_t2 - cold_t1 > 1000) {
				cold_count--;
				cold_t1 = cold_t2;
			}
		}
		else {
			cold_t1 = GetTickCount();
			cold_t2 = GetTickCount();
		}
	}
};