#pragma once
#include"variable_setup.h"
void Konw() {
	putimagePng(100, 100, &konw);
	player.fresh_mouse_location();
	settextcolor(BLACK);
	outtextxy(150, 150, _T("本游戏相较于原版，节奏有所加快"));
	outtextxy(150, 180, _T("操作须知：鼠标挪动到阳光位置可以"));
	outtextxy(150, 210, _T("自动拾取，无需点击"));
	outtextxy(150, 240, _T("第一关：没什么难度"));
	outtextxy(150, 270, _T("第二关：前期用坚果和土豆地雷多攒阳光"));
	outtextxy(150, 300, _T("建议种两排向日葵，攒阳光种双发"));
	outtextxy(150, 330, _T("和西瓜（别种单发）"));
	outtextxy(150, 360, _T("第三关：模仿者向日葵忘记自己模仿了谁"));
	outtextxy(150, 390, _T("但是没关系，坚持180s就好"));
	outtextxy(150, 420, _T("按下空格退出此页面"));
	if (_kbhit()) {
		game = 0;
		while (_kbhit())
		{
			_getch();
		}
	}
}