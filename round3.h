#pragma once
#include"variable_setup.h"
#include"Second_count.h"
void round3() {
	static bool lock1=false;
	static bool lock2=false;
	static DWORD t1 = GetTickCount();
	static DWORD t2;
	TCHAR filename[15];
	int second = second_count();
	_stprintf_s(filename, _T("Time:%d"), second);
	settextstyle(40, 0, _T("ºÚÌå"));
	outtextxy(750, 50, filename);
	int gap = 4000 - 10 * second;
	t2 = GetTickCount();
	if (t2 - t1 >= gap) {
		int row = rand() % 5;
		int type = 1 + rand() % 3;
		if (type == 1) {
			zombie_list.push_back(Zombie(950, map.get_y(row), row));
		}
		if (type == 2) {
			conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(row), row));
		}
		if (type == 3) {
			bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(row), row));
		}
		t1 = t2;
	}
	if (second == 180) {
		win = true;
		for (auto& p : conehead_zombie_list) {
			p.HP = 0;
		}
		for (auto& p : bucked_zombie_list) {
			p.HP = 0;
		}
	}
	if (second == 181) {
		for (auto& p : zombie_list) {
			p.HP = 0;
		}
	}
}