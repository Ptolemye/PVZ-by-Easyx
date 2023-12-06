#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include<list>
#include"variable_setup.h"
int second_count() {
	DWORD t = GetTickCount();
	return (t - start_time) / 1000;
}
