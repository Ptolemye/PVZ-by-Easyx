#pragma once
#ifndef MOUSE_CONTROL_H
#define MOUSE_CONTROL_H
#include "variable_setup.h"
int Get_card() {
	static int result=-1;
	int x = player.get_mouse_x();
	int y = player.get_mouse_y();
	if (player.if_click()) {
		if (x > 0 && x < 500 && y>0 && y < 60)result= (x - 70) / 70;
	}
	return result;
}

#endif