#pragma once
#include"variable_setup.h"
void Konw() {
	putimagePng(100, 100, &konw);
	player.fresh_mouse_location();
	settextcolor(BLACK);
	outtextxy(150, 150, _T("����Ϸ�����ԭ�棬���������ӿ�"));
	outtextxy(150, 180, _T("������֪�����Ų��������λ�ÿ���"));
	outtextxy(150, 210, _T("�Զ�ʰȡ��������"));
	outtextxy(150, 240, _T("��һ�أ�ûʲô�Ѷ�"));
	outtextxy(150, 270, _T("�ڶ��أ�ǰ���ü�����������׶�������"));
	outtextxy(150, 300, _T("�������������տ�����������˫��"));
	outtextxy(150, 330, _T("�����ϣ����ֵ�����"));
	outtextxy(150, 360, _T("�����أ�ģ�������տ������Լ�ģ����˭"));
	outtextxy(150, 390, _T("����û��ϵ�����180s�ͺ�"));
	outtextxy(150, 420, _T("���¿ո��˳���ҳ��"));
	if (_kbhit()) {
		game = 0;
		while (_kbhit())
		{
			_getch();
		}
	}
}