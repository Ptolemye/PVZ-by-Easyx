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
public:
	Plant(int row,int col){
		this->row = row;
		this->col = col;
	}
	int Get_cost() {
		return cost;
	}
};