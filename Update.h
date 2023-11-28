#pragma once
#include"variable_setup.h"
#include <windows.h>
template<typename T>
void Zombie_attack(int row, int col, std::list<T>& obj_list) {
	auto p = obj_list.begin();
	while (p != obj_list.end()) {
		if (p->row == row && p->col == col)p->HP -= 3;
		p++;
	}
}
template<typename T>
void Plant_HP_Check(std::list<T>& obj_list) {
	auto p = obj_list.begin();
	while (p != obj_list.end()) {
		if (p->HP <= 0) {
			map.box_set(p->row, p->col, 0);
			obj_list.erase(p++);
		}
		else p++;
	}
}
//¼ì²âÂ·¾¶ÉÏÊÇ·ñÓĞ½©Ê¬
bool enemy_check(int i) {
	for (auto& p : zombie_list) {
		int row = map.get_box_row(p.x, p.y);
		int col = map.get_box_col(p.x, p.y);
		if (p.path == i && map.in_box(row, col)) {
			return true;
		}
	}
	return false;
}
//µ¯Ò©Åö×²
template<typename T1,typename T2>
void bullet_hit(std::list<T1>& list1, std::list<T2>& list2,int damage) {
	auto p = list1.begin();
	int p_x;
	int wide;
	int z_x;
	while (p != list1.end()) {
		p_x = p->x;
		wide = p->wide;
		auto z = list2.begin();
		while (z != list2.end()) {
			z_x = z->x;
			if (p_x + wide >= z_x&&p_x<=z_x+75&&!p->hit_enemy&&p->path==z->path) {
				z->HP -= damage;
				p->hit_enemy = true;
				p->t1 = GetTickCount();
			}
			z++;
		}
		p++;
	}
}
//½©Ê¬Ïû³ı
template<typename T>
void enemy_clean(std::list<T>& obj_list) {
	auto p = obj_list.begin();
	while (p != obj_list.end()) {
		if (p->HP <= 0) {
			obj_list.erase(p++);
		}
		else p++;
	}
}
void Update() {
	//Ïû³ıËÀÍö½©Ê¬
	enemy_clean(zombie_list);
	//µ¯Ò©Ïû³ı
	auto p = pea_list.begin();
	while (p != pea_list.end()) {
		if (p->draw_over || p->x > 900) {
			pea_list.erase(p++);
		}
		else p++;
	}
	//Éú³É½©Ê¬
	static DWORD t1 = GetTickCount();
	static DWORD t3 = GetTickCount();
	DWORD t2 = GetTickCount();
	if (t2-t3>15000&&t2-t1>20000) {
		int path = rand()%5;
		Zombie z(950, start_y + path * WIDTH, path);//start_y + path * WIDTH
		zombie_list.push_back(z);
		t1 = t2;
	}
	//½©Ê¬¹¥»÷
	auto t = zombie_list.begin();
	while (t != zombie_list.end()) {
		int row = map.get_box_row(t->x, t->y);
		int col = map.get_box_col(t->x, t->y);
		int type = map.box_get(row, col);
		if (map.box_get(row, col) != 0) {
			t->if_eating = true;
			if (t->draw_step_eating == 5) {
				if (type == 1)Zombie_attack(row, col, sunflower_list);
				if (type == 2)Zombie_attack(row, col, peashooter_list);
				if (type == 3)Zombie_attack(row, col, wallnut_list);
			}
		}
		else t->if_eating = false;
		t++;
	}
	//Íã¶¹ÉäÊÖ·¢ÉäÍã¶¹
	for (auto& p : peashooter_list) {
		int path = p.row;
		int x = p.col * LENGTH + start_x;
		int y = path * WIDTH + start_y;
		if (enemy_check(path)) {
			p.is_shooting = true;
			if (p.reload_over) {
				Pea pea(x + 60, y+10,p.row);
				pea.Set_image();
				pea_list.push_back(pea);
				p.reload_over = false;
			}
		}
		else p.is_shooting = false;
	}
	//ÏòÈÕ¿ûÉú²úÑô¹â
	for (auto& p : sunflower_list) {
		if (p.produce_sun()) {
			Sun s(p.col * LENGTH + start_x,p.row * WIDTH + start_y+50);
			sun_list.push_back(s);
		}
	}
	//µ¯Ò©Ç°½ø
	for (auto& p : pea_list) {
		p.x += 3;
	}

	//Ïû³ıËÀÍöÖ²Îï
	Plant_HP_Check(sunflower_list);
	Plant_HP_Check(peashooter_list);
	Plant_HP_Check(wallnut_list);
	//ÖÖÖ²ÀäÈ´
	sunflower_function.colding();
	Peashooter_function.colding();
	wallnut_function.colding();
	//µ¯Ò©Åö×²
	bullet_hit(pea_list, zombie_list, 30);
	

}