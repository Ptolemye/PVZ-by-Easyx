#pragma once
#ifndef INITIALLIZER_H
#define INITIALLIZER_H
#include"variable_setup.h"
inline void initiallizer() {
	initgraph(1000, 561);//640�ǻ�����ȣ�480�ǻ����߶�
	map.Set_image();
	cardlist.Set_image();
	Zombie::Set_image();
	Conehead_Zombie::Set_image();
	Buckedhead_Zombie::Set_image();
	Sun::Set_image();
}
#endif