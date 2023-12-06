#pragma once
#include"variable_setup.h"
void end_draw() {
	static DWORD t1;
	static DWORD t2;
	if (lost||win) {
		if (lost) {
			t2 = GetTickCount();
			if (t2 - t1 < 3000) {
				putimagePng(250, 200, &game_lost);
			}
			else game = 0;
		}
		if (win) {
			t2 = GetTickCount();
			if (t2 - t1 < 3000) {
				putimagePng(250, 200, &game_win);
			}
			else game = 0;
		}
	}
	else {
		t1 = GetTickCount();
		t2 = GetTickCount();
	}
}