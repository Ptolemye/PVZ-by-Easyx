#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
class Player {
private:
	int x;
	int y;
	MOUSEMSG m;
public:
	int money = 10000;
	//刷新位置坐标
	void fresh_mouse_location() {
		if (MouseHit()) {
			m = GetMouseMsg();
			x = m.x;
			y = m.y;
		}
	}
	int get_mouse_x() {
		return x;
	}
	int get_mouse_y() {
		return y;
	}
	//右键单击，标识方块
	bool if_click() {
		if (m.uMsg == WM_LBUTTONDOWN)return true;
		else return false;
	}
};

#endif