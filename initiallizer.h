#pragma once
#ifndef INITIALLIZER_H
#define INITIALLIZER_H
#include"variable_setup.h"
inline void initiallizer() {
	initgraph(1000, 540);//640�ǻ�����ȣ�480�ǻ����߶�
	map.Set_image();
	cardlist.Set_image();
}
#endif