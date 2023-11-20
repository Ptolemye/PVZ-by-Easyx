#pragma once
#ifndef INITIALLIZER_H
#define INITIALLIZER_H
#include"variable_setup.h"
inline void initiallizer() {
	initgraph(1000, 540);//640是画布宽度，480是画布高度
	map.Set_image();
	cardlist.Set_image();
}
#endif