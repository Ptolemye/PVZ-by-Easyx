#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include<list>

class Sun {
public:
	int x;
	int y;
	int wide;
	static IMAGE im_sun;
	Sun(){}
	Sun(int x,int y) {
		this->x = x;
		this->y = y;
	}
	static void Set_image() {
		loadimage(&im_sun, _T("image\\Sun\\Sun.png"));
	}
	void draw() {
		putimagePng(x, y, &im_sun);
	}
};