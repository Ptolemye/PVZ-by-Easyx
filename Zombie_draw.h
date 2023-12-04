#pragma once
#include"variable_setup.h"
template<typename T>
void Zombie_draw_help(std::list<T>& obj_list,int i) {
	for (auto& p : obj_list) {
		if (p.path == i)p.draw();
	}
	/*for (auto& p : obj_list) {
		if (p.path == 1)p.draw();
	}
	for (auto& p : obj_list) {
		if (p.path == 2)p.draw();
	}
	for (auto& p : obj_list) {
		if (p.path == 3)p.draw();
	}
	for (auto& p : obj_list) {
		if (p.path == 4)p.draw();
	}*/
}
void Zombie_draw() {
	for (int i = 0; i < 5; i++) {
		Zombie_draw_help(zombie_list,i);
		Zombie_draw_help(conehead_zombie_list,i);
		Zombie_draw_help(bucked_zombie_list, i);
	}
}