#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
class Card_list {
public:
	IMAGE im_sf[20];
	void Set_image() {
		loadimage(&im_sf[1], L"image\\Card\\SF_card1.png");
		loadimage(&im_sf[2], L"image\\Card\\Peashooter_card1.png");
		loadimage(&im_sf[3], L"image\\Card\\Wallnut_card1.png");
		loadimage(&im_sf[6], L"image\\Card\\R.png");
	}
	void draw() {
		for (int i = 1; i < 10; i++) {
			putimagePng(70 + 70 * (i - 1), 5, &im_sf[i]);
		}
	}
};