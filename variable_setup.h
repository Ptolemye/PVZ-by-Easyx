#pragma once
#include"Map.h"
#include"Player.h"
#include"Sunflower.h"
#include"Peashooter.h"
#include"Double_Peashooter.h"
#include"Potato.h"
#include"Watermelon.h"
#include"Card_list.h"
#include"Wallnut.h"
#include"Zombie.h"
#include"Conehead_Zombie.h"
#include"Buckedhead_Zombie.h"
#include"Sun.h"
#include"Pea.h"
#include"Melon.h"
using namespace std;
extern Map map;
extern Player player;
extern list<Sunflower>sunflower_list;
extern list<Peashooter>peashooter_list;
extern list<Double_Peashooter>double_peashooter_list;
extern list<Wallnut>wallnut_list;
extern list<Potato>potato_list;
extern list<Watermelon>watermelon_list;
extern list<Zombie>zombie_list;
extern list<Conehead_Zombie>conehead_zombie_list;
extern list<Buckedhead_Zombie>bucked_zombie_list;
extern list<Sun>sun_list;
extern list<Pea>pea_list;
extern list<Melon>melon_list;
extern Sunflower sunflower_function;
extern Peashooter Peashooter_function;
extern Wallnut wallnut_function;
extern Potato potato_function;
extern Double_Peashooter double_peashooter_function;
extern Watermelon watermelon_function;
extern int card_elected;
extern Card_list cardlist;
extern int game;
extern IMAGE im_start;
extern IMAGE button;
extern IMAGE head;
extern IMAGE im_txt;
extern IMAGE game_lost;
extern IMAGE game_win;
extern int time_passed;
extern bool lost;
extern bool win;
extern DWORD start_time;
extern bool sow_lock;