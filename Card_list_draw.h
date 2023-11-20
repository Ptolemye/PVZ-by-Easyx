#pragma once
#ifndef CARD_LIST_DRAW_H
#define CARD_LIST_DRAW_H
#include"variable_setup.h"
#include"Mouse_control.h"
void Card_list_draw() {
	player.fresh_mouse_location();
	cardlist.draw();
	if (Get_card() >= 0) {
		rectangle(69 + 70 * Get_card(), 2, 69 + 70 * (Get_card() + 1), 72);
	}

}
#endif