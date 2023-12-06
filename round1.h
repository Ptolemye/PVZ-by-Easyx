#pragma once
#include"variable_setup.h"
#include"Second_count.h"
void round1() {
	int row = rand() % 5;
	int y = map.get_y(row);
	static bool lock1 = false;
	static bool lock2 = false;
	static bool sun_lock = false;
	if (second_count() % 7 == 0 && rand() % 2 == 1&&!sun_lock) {
		sun_list.push_back(Sun(400 + rand() % 400, 200 + rand() % 300));
		sun_lock = true;
	}
	if (second_count() % 3 == 0 && second_count() % 7!= 0) {
		sun_lock = false;
	}
	if (second_count() == 15&&!lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(3), 3));
		lock1 = true;
	}
	if (second_count() == 37&&!lock2){
		zombie_list.push_back(Zombie(950, map.get_y(4), 4));
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		zombie_list.push_back(Zombie(950, map.get_y(2), 2));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 50 && !lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(2), 2));
		zombie_list.push_back(Zombie(950, map.get_y(3), 3));
		zombie_list.push_back(Zombie(950, map.get_y(2), 2));
		zombie_list.push_back(Zombie(950, map.get_y(4), 4));
		lock2 = false;
		lock1 = true;
	}
	if (second_count() == 66 && !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		zombie_list.push_back(Zombie(950, map.get_y(0), 0));
		zombie_list.push_back(Zombie(950, map.get_y(0), 0));
		zombie_list.push_back(Zombie(950, map.get_y(4), 4));
		lock2 = true;
		lock1 = false;
	}
	if (second_count() == 81 && !lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		zombie_list.push_back(Zombie(950, map.get_y(2), 2));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(3), 3));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(4), 4));
		lock2 = false;
		lock1 = true;
	}
	if (second_count() == 100 && !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(3), 3));
		zombie_list.push_back(Zombie(950, map.get_y(4), 4));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(2), 2));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(1), 1));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(0), 0));
		lock1 = false;
		lock2 = true;
	}
	if (second_count() == 104 && !lock1) {
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(4), 4));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(3), 3));
		lock2 = false;
		lock1 = true;
	}
	if (second_count() == 115 && !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		zombie_list.push_back(Zombie(950, map.get_y(3), 3));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(2), 2));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(3), 3));
		lock1 = false;
		lock2 = true;
	}
	if (second_count() == 140 && !lock1) {
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		zombie_list.push_back(Zombie(950, map.get_y(3), 3));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(2), 2));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(3), 3));
		lock2 = false;
		lock1= true;
	}
	if (second_count() == 144&& !lock2) {
		zombie_list.push_back(Zombie(950, map.get_y(4), 4));
		zombie_list.push_back(Zombie(950, map.get_y(1), 1));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(3), 3));
		conehead_zombie_list.push_back(Conehead_Zombie(950, map.get_y(0), 0));
		lock1 = false;
		lock2 = true;
	}
	if (second_count() >= 180) {
		win = true;
		for (auto& p : zombie_list) {
			win = false;
		}
		for (auto& p : conehead_zombie_list) {
			win = false;
		}
	}
}