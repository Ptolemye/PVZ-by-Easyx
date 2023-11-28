#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include"Map.h"
#include"Player.h"
#include<iostream>
#include"Plant_sow.h"
#include"Plant_draw.h"
#include"Map_draw.h"
#include"Zombie_draw.h"
#include"Card_list_draw.h"
#include"initiallizer.h"
#include"Mouse_control.h"
#include"Update.h"
Map map;
Player player;
list<Sunflower>sunflower_list;
list<Peashooter>peashooter_list;
list<Wallnut>wallnut_list;
list<Zombie>zombie_list;
list<Pea>pea_list;
list<Sun>sun_list;
Sunflower sunflower_function(-1,-1);
Wallnut wallnut_function(-1, -1);
Peashooter Peashooter_function(-1,-1);
IMAGE Zombie::im_zombie1[6];
IMAGE Zombie::im_zombie1_eating[8];
IMAGE Sun::im_sun;
int card_elected;
Card_list cardlist;
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	initiallizer();
	BeginBatchDraw();
	while (1) {
		Update();
		Map_draw();
		Card_list_draw();
		Zombie_draw();
		Plant_draw();
		Plant_sow(Get_card() + 1);
		Sleep(10);
		FlushBatchDraw();
	}
}