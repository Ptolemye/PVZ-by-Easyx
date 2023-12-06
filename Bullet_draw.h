#pragma once
#include"variable_setup.h"
void bullet_draw() {
	for (auto& p : pea_list) {
		p.draw();
	}
	for (auto& p : melon_list) {
		p.draw();
	}
}