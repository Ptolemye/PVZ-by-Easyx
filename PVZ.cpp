#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include"Map.h"
#include"Player.h"
#include<iostream>
#include"Plant_sow.h"
#include"Plant_draw.h"
#include"Map_draw.h"
#include"Card_list_draw.h"
#include"initiallizer.h"
#include"Mouse_control.h"
Map map;
Player player;
list<Sunflower>sunflower_list;
list<Peashooter>peashooter_list;
list<Wallnut>wallnut_list;
int card_elected;
Card_list cardlist;
using namespace std;
int main()
{
	initiallizer();
	BeginBatchDraw();
	while (1) {
		Map_draw();
		Card_list_draw();
		Plant_draw();
		Plant_sow(Get_card() + 1);
		Sleep(10);
		FlushBatchDraw();
	}
}