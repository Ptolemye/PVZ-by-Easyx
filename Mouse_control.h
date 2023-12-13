#pragma once
#ifndef MOUSE_CONTROL_H
#define MOUSE_CONTROL_H
#include "variable_setup.h"
int Get_card() {
	static int result=-1;
	int x = player.get_mouse_x();
	int y = player.get_mouse_y();
	if (player.if_click()) {
		if (x > 0 && x < 700 && y>0 && y < 60) {
			result = (x - 70) / 70 + 1;
			sow_lock = false;
		}
		if (game == 1) {
			if (result > 3 && result != 8)result = -1;
		}
		if (game == 2) {
			if (result > 6 && result != 8)result = -1;
		}
		if (game == 3) {
			if (result > 1 && result != 8)result = -1;
		}
	}
	if (lost||win)result = -1;
	return result;
}

#endif