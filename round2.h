#pragma once
#include"variable_setup.h"
#include"Second_count.h"
void round2() {
	static bool lock1 = false;
	static bool lock2 = false;
	static bool sun_lock = false;
	if (second_count() % 7 == 0 && rand() % 2 == 1 && !sun_lock) {
		sun_list.push_back(Sun(400 + rand() % 400, 200 + rand() % 300));
		sun_lock = true;
	}
	if (second_count() % 3 == 0 && second_count() % 7 != 0) {
		sun_lock = false;
	}
	if (second_count() == 18&&!lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(3), 3));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(2), 2));
		lock1 = true;
	}
	if (second_count() == 30&& !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 36&& !lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(0), 0));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 39 && !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(2), 2));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(4), 4));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 49&& !lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(0), 0));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 59&& !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(3), 3));
		zombie_list.push_back(Zombie(950, map.get_y(4), 4));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(1), 1));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 79&& !lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		zombie_list.push_back(Zombie(950, map.get_y(2), 2));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(4), 4));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(3), 3));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(0), 0));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 88 && !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(0), 0));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(1), 1));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(4), 4));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 98 && !lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(3), 3));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(0), 0));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 106 && !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(4), 4));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(0), 0));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 114 && !lock1) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(2), 2));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(3), 3));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 127 && !lock2) {
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(0), 0));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(4), 4));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(3), 3));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 138 && !lock1) {
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(1), 1));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(0), 0));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(4), 4));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 144 && !lock2) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(3), 3));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 146 && !lock1) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(2), 2));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 150 && !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(0), 0));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(4), 4));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 154 && !lock1) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(2), 2));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 157 && !lock2) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(1), 1));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 163 && !lock1) {
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(1), 1));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(0), 0));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(4), 4));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 179&& !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(4), 4));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(0), 0));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 187 && !lock1) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(2), 2));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(1), 1));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 192 && !lock2) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(0), 0));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(3), 3));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 200 && !lock1) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(4), 4));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(1), 1));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(3), 3));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 206&& !lock2) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(0), 0));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(2), 2));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(4), 4));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(3), 3));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 208 && !lock1) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(2), 2));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(1), 1));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(3), 3));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(4), 4));
		lock1 = true;
		lock2 = false;
	}
	if (second_count() == 212 && !lock2) {
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(0), 0));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(2), 2));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(4), 4));
		bucked_zombie_list.push_back(Buckedhead_Zombie(950, map.get_y(3), 3));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() >= 240) {
		win = true;
		lock1 = false;
		lock2 = false;
		for (auto& p : zombie_list) {
			win = false;
		}
		for (auto& p : conehead_zombie_list) {
			win = false;
		}
		for (auto& p : bucked_zombie_list) {
			win = false;
		}
	}
}