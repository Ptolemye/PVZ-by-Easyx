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
#include"Bullet_draw.h"
#include"Card_list_draw.h"
#include"initiallizer.h"
#include"Mouse_control.h"
#include"Update.h"
#include"Timer.h"
#include"Start.h"
#include"end_draw.h"
#include"round1.h"
#include"round2.h"
#include"round3.h"
#include"Konw.h"
Timer timer;
Map map;
Player player;
list<Sunflower>sunflower_list;
list<Peashooter>peashooter_list;
list<Double_Peashooter>double_peashooter_list;
list<Wallnut>wallnut_list;
list<Potato>potato_list;
list<Watermelon>watermelon_list;
list<Zombie>zombie_list;
list<Conehead_Zombie>conehead_zombie_list;
list<Buckedhead_Zombie>bucked_zombie_list;
list<Pea>pea_list;
list<Melon>melon_list;
list<Sun>sun_list;
Sunflower sunflower_function(-1,-1);
Wallnut wallnut_function(-1, -1);
Peashooter Peashooter_function(-1,-1);
Double_Peashooter double_peashooter_function(-1,-1);
Watermelon watermelon_function(-1, -1);
Potato potato_function(-1,-1);
IMAGE Zombie::im_zombie1[6];
IMAGE Zombie::im_zombie1_eating[8];
IMAGE Zombie::im_zombie2[6];
IMAGE Zombie::im_zombie2_eating[8];
IMAGE Zombie::im_zombie3[14];
IMAGE Conehead_Zombie::im_zombie1[6];
IMAGE Conehead_Zombie::im_zombie1_eating[8];
IMAGE Conehead_Zombie::im_zombie2[6];
IMAGE Conehead_Zombie::im_zombie2_eating[8];
IMAGE Conehead_Zombie::im_zombie3[6];
IMAGE Conehead_Zombie::im_zombie3_eating[8];
IMAGE Buckedhead_Zombie::im_zombie1[6];
IMAGE Buckedhead_Zombie::im_zombie1_eating[8];
IMAGE Buckedhead_Zombie::im_zombie2[6];
IMAGE Buckedhead_Zombie::im_zombie2_eating[8];
IMAGE Buckedhead_Zombie::im_zombie3[6];
IMAGE Buckedhead_Zombie::im_zombie3_eating[8];
IMAGE Sun::im_sun;
IMAGE im_start;
IMAGE button1;
IMAGE konw;
IMAGE button;
IMAGE im_txt;
IMAGE game_lost;
IMAGE game_win;
IMAGE head;
bool lost = false;
bool win = false;
bool sow_lock = false;
int game;
int card_elected;
int time_passed;
Card_list cardlist;
DWORD start_time;
using namespace std;
int main()
{
	game = 0;
	srand((unsigned int)time(NULL));
	initiallizer();
	BeginBatchDraw();
	while (1) {
		if(game==0)Start();
		else if (game == -1)Konw();
		else {
			if (game == 1)round1();
			if (game == 2)round2();
			Update();
			Map_draw();
			if (game == 3)round3();
			Card_list_draw();
			Plant_draw();
			Zombie_draw();
			bullet_draw();
			if (game == 3) {
				card_elected=rand() % 5;
			}
			else {
				card_elected = Get_card();//改
			}
			Plant_sow(Get_card());
			end_draw();
		}
		timer.Sleep(10);
		FlushBatchDraw();
	}
}