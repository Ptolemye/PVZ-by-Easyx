#pragma once
#ifndef INITIALLIZER_H
#define INITIALLIZER_H
#include"variable_setup.h"
inline void initiallizer() {
	initgraph(1000, 561);//640是画布宽度，480是画布高度
	map.Set_image();
	cardlist.Set_image();
	Zombie::Set_image();
	Conehead_Zombie::Set_image();
	Buckedhead_Zombie::Set_image();
	Sun::Set_image();
	loadimage(&im_start, _T("image\\Map\\R.png"));
	loadimage(&button, _T("image\\Map\\button.png"));
	loadimage(&im_txt, _T("image\\Map\\text.png"));
	loadimage(&game_lost, _T("image\\Map\\end.png"));
	loadimage(&head, _T("image\\Map\\head.png"));
	loadimage(&game_win, _T("image\\Map\\success.png"));
}
#endif