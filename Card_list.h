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
		loadimage(&im_sf1[4], L"image\\Card\\Double_Peashooter_card.png");
		loadimage(&im_sf1[5], L"image\\Card\\Potato_card.png");
		loadimage(&im_sf1[6], L"image\\Card\\Watermelon_card.png");
		loadimage(&im_sf1[8], L"image\\Card\\R.png");
		loadimage(&im_sf1[9], L"image\\Card\\SF_card2.png");
	}
	void draw1(int t) {
		for (int i = 1; i < t; i++) {
			 putimagePng(70 + 70 * (i - 1), 5, &im_sf1[i]);
		}
		if(t==0)putimagePng(70 , 5, &im_sf1[9]);
		putimagePng(560, 5, &im_sf1[8]);
	}
	void draw2(int i,int t,int wide) {
		setfillcolor(RGB(255,255,255));
		fillrectangle(70 + 70 * (i - 1), 65-t * wide,65+70*i,65);
	}
};