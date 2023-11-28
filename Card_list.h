#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
class Card_list {
public:
	IMAGE im_sf1[20];
	IMAGE im_sf2[20];
	void Set_image() {
		loadimage(&im_sf1[1], L"image\\Card\\SF_card1.png");
		loadimage(&im_sf1[2], L"image\\Card\\Peashooter_card1.png");
		loadimage(&im_sf1[3], L"image\\Card\\Wallnut_card1.png");
		loadimage(&im_sf2[3], L"image\\Card\\Wallnut_card2.png");
		loadimage(&im_sf1[6], L"image\\Card\\R.png");
	}
	void draw1() {
		for (int i = 1; i < 7; i++) {
			putimagePng(70 + 70 * (i - 1), 5, &im_sf1[i]);
		}
	}
	void draw2(int i,int t,int wide) {
		fillrectangle(70 + 70 * (i - 1), 65-t * wide,65+70*i,65);
	}
};