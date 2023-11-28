#pragma once
#include"variable_setup.h"
template<typename T>
void Zombie_draw_help(std::list<T>& obj_list) {
	for (auto& p : obj_list) {
		if (p.path == 0)p.draw();
	}
	for (auto& p : obj_list) {
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
	}
}
void Zombie_draw() {
	Zombie_draw_help(zombie_list);
}