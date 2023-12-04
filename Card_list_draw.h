#pragma once
#ifndef CARD_LIST_DRAW_H
#define CARD_LIST_DRAW_H
#include"variable_setup.h"
#include"Mouse_control.h"
template<typename T>
void Card_list_draw_help(int i,T &t) {
	int wide = 60 / t.cold_time;
	if(!t.ready_to_plant)cardlist.draw2(i,t.cold_count,wide);
}
void Card_list_draw() {
	player.fresh_mouse_location();
	cardlist.draw1();
	Card_list_draw_help(1, sunflower_function);
	Card_list_draw_help(2,Peashooter_function);
	Card_list_draw_help(3, wallnut_function);
	Card_list_draw_help(4, double_peashooter_function);
	Card_list_draw_help(5, potato_function);
	Card_list_draw_help(6, watermelon_function);
	//¿îÑ¡Ä£¿é
	if (Get_card() >= 0) {
		rectangle(69 + 70 * Get_card(), 2, 69 + 70 * (Get_card() + 1), 72);
	}

}
#endif