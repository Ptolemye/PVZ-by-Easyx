#pragma once
#ifndef MAP_H
#define MAP_H
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#define start_x 60
#define start_y 75
#define LENGTH 72
#define WIDTH 85
//651*425 起始60*75 单个方块72*85
class Map {
private:
	IMAGE im_map;
	IMAGE im_table1;
	IMAGE im_table2;
	int box[5][9] = { 0 };
public:
	Map(){}
	void Set_image() {
		loadimage(&im_map, L"image\\Map\\bk1.png");
		loadimage(&im_table1, L"image\\Map\\table.png");
		loadimage(&im_table2, L"image\\Map\\table2.png");
	}
	void draw(){
		putimage(0, 0, &im_map);
		putimage(0, 0, &im_table1);
		putimage(430, 0, &im_table2);

	}
	//方块定位
	int get_box_row(int x,int y) {
		if (y - start_y < 0)return -1;
		return (y - start_y) / WIDTH;
	}
	int get_box_col(int x,int y) {
		if (x - start_x < 0)return -1;
		return (x - start_x) / LENGTH;
	}
	void box_set(int row,int col,int type) {
		box[row][col] = type;
	}
	int box_get(int row, int col) {
		if (!in_box(row, col))return 0;
		return box[row][col];
	}
	bool is_box_planted(int row,int col) {
		if (box[row][col] == 0)return false;
		else return true;
	}
	bool in_box(int row,int col) {
		if (row < 5 && col < 9&&row>=0&&col>=0)return true;
		else return false;
	}
};

#endif