#pragma once
#include"Map.h"
#include"Player.h"
#include"Sunflower.h"
#include"Peashooter.h"
#include"Card_list.h"
#include"Wallnut.h"
#include"Zombie.h"
#include"Sun.h"
#include"Pea.h"
using namespace std;
extern Map map;
extern Player player;
extern list<Sunflower>sunflower_list;
extern list<Peashooter>peashooter_list;
extern list<Wallnut>wallnut_list;
extern list<Zombie>zombie_list;
extern list<Sun>sun_list;
extern list<Pea>pea_list;
extern Sunflower sunflower_function;
extern Peashooter Peashooter_function;
extern Wallnut wallnut_function;
extern int card_elected;
extern Card_list cardlist;
