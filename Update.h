#pragma once
#include"variable_setup.h"
#include <windows.h>
//½©Ê¬¹¥»÷£¨¸¨Öú£©
template<typename T>
void Zombie_attack_help(int row, int col, std::list<T>& obj_list) {
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
	for (auto& p : conehead_zombie_list) {
		int row = map.get_box_row(p.x, p.y);
		int col = map.get_box_col(p.x, p.y);
		if (p.path == i && map.in_box(row, col)) {
			return true;
		}
	}
	for (auto& p : bucked_zombie_list) {
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
			if (p_x + wide >= z_x&&p_x<=z_x+75&&!p->hit_enemy&&p->path==z->path&&z->HP>0) {
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
		if (p->draw_over) {
			obj_list.erase(p++);
		}
		else p++;
	}
}
//½©Ê¬¹¥»÷
template<typename T>
void Zombie_attack(std::list<T>& obj_list) {
	auto t = obj_list.begin();
	while (t != obj_list.end()) {
		int row = map.get_box_row(t->x, t->y);
		int col = map.get_box_col(t->x, t->y);
		int type = map.box_get(row, col);
		if (map.box_get(row, col) != 0 && t->HP > 0) {
			t->if_eating = true;
			if (t->draw_step_eating == 5) {
				if (type == 1)Zombie_attack_help(row, col, sunflower_list);
				if (type == 2)Zombie_attack_help(row, col, peashooter_list);
				if (type == 3)Zombie_attack_help(row, col, wallnut_list);
				if (type == 4)Zombie_attack_help(row, col, double_peashooter_list);
				if (type == 5)Zombie_attack_help(row, col, potato_list);
				if (type == 6)Zombie_attack_help(row, col, watermelon_list);
			}
		}
		else t->if_eating = false;
		t++;
	}
}
//ÌØÊâ½©Ê¬×ª»»
template<typename T>
void Zombie_transform(std::list<T>& obj_list) {
	auto p = obj_list.begin();
	while (p != obj_list.end()) {
		if (p->HP <= 270) {
			Zombie z(p->x, p->y, p->path);
			zombie_list.push_back(z);
			obj_list.erase(p++);
		}
		else p++;
	}
}
//Î÷¹ÏÕ¨ÁÑµÄ·¶Î§ÉËº¦
void kill_scale(int col, int row) {
	for (auto& p : zombie_list) {
		int z_col = map.get_box_col(p.x, p.y);
		if (p.path == row) {
			if (z_col >= col && z_col - col <= 2) {
				p.HP -= 30;
			}
		}
	}
	for (auto& p : conehead_zombie_list) {
		int z_col = map.get_box_col(p.x, p.y);
		if (p.path == row) {
			if (z_col >= col && z_col - col <= 2) {
				p.HP -= 30;
			}
		}
	}
	for (auto& p : bucked_zombie_list) {
		int z_col = map.get_box_col(p.x, p.y);
		if (p.path == row) {
			if (z_col >= col && z_col - col <= 2) {
				p.HP -= 30;
			}
		}
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
	auto p1 = melon_list.begin();
	while (p1 !=melon_list.end()) {
		if (p1->draw_over || p1->y >= (p1->path+1)*WIDTH+start_y-30) {
			melon_list.erase(p1++);
		}
		else p1++;
	}
	//Éú³É½©Ê¬
	//static DWORD t1 = GetTickCount();
	//static DWORD t3 = GetTickCount();
	//DWORD t2 = GetTickCount();
	//if (t2-t3>1000&&t2-t1>5000) {
	//	int path = rand()%5;
	//	Zombie z1(950, start_y + path * WIDTH, path);//start_y + path * WIDTH
	//	zombie_list.push_back(z1);
	//	path = rand() % 5;
	//	Conehead_Zombie z2(950, start_y + path * WIDTH, path);//start_y + path * WIDTH
	//	conehead_zombie_list.push_back(z2);
	//	path = rand() % 5;
	//	Buckedhead_Zombie z3(950, start_y + path * WIDTH, path);//start_y + path * WIDTH
	//	bucked_zombie_list.push_back(z3);
	//	t1 = t2;
	//}
	Zombie_attack(zombie_list);
	Zombie_attack(conehead_zombie_list);
	Zombie_attack(bucked_zombie_list);
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
	//Ë«·¢ÉäÊÖ·¢Éä
	for (auto& p :double_peashooter_list) {
		int path = p.row;
		int x = p.col * LENGTH + start_x;
		int y = path * WIDTH + start_y;
		if (enemy_check(path)) {
			p.is_shooting = true;
			if (p.reload_over) {
				Pea pea1(x + 60, y + 10, p.row);
				Pea pea2(x + 80, y + 10, p.row);
				pea1.Set_image();
				pea2.Set_image();
				pea_list.push_back(pea1);
				pea_list.push_back(pea2);
				p.reload_over = false;
			}
		}
		else p.is_shooting = false;
	}
	//ÍÁ¶¹À×±¬Õ¨
	for (auto& p : potato_list) {
		int row = p.row;
		int col = p.col;
		if (!p.is_boom&&p.ready_to_boom) {
			int z_row;
			int z_col;
			auto z1 = zombie_list.begin();
			while (z1!=zombie_list.end())
			{
				z_row = map.get_box_row(z1->x, z1->y);
				z_col= map.get_box_col(z1->x, z1->y);
				if (z_row == row &&( z_col == col||z_col+1==col)) {
					p.is_boom = true;
					zombie_list.erase(z1++);
				}
				else z1++;
			}
			auto z2 = conehead_zombie_list.begin();
			while (z2 != conehead_zombie_list.end())
			{
				z_row = map.get_box_row(z2->x, z2->y);
				z_col = map.get_box_col(z2->x, z2->y);
				if (z_row == row && (z_col == col || z_col + 1 == col)) {
					p.is_boom = true;
					conehead_zombie_list.erase(z2++);
				}
				else z2++;
			}
			auto z3 = bucked_zombie_list.begin();
			while (z3 != bucked_zombie_list.end())
			{
				z_row = map.get_box_row(z3->x, z3->y);
				z_col = map.get_box_col(z3->x, z3->y);
				if (z_row == row && (z_col == col || z_col + 1 == col)) {
					p.is_boom = true;
					bucked_zombie_list.erase(z3++);
				}
				else z3++;
			}
		}
	}
	//Î÷¹ÏÍ¶Éä
	for (auto& p : watermelon_list) {
		int path = p.row;
		int x = (p.col+1) * LENGTH + start_x-100;
		int y = path * WIDTH + start_y;
		if (enemy_check(path)) {
			p.is_shooting = true;
			int enemy_x=1000;
			for (auto& z : zombie_list) {
				if (z.path == path&&z.x>x&&z.HP>0) {
					if (z.x < enemy_x)enemy_x = z.x;
				}
			}
			for (auto& z : conehead_zombie_list) {
				if (z.path == path&&z.x > x && z.HP > 0) {
					if (z.x < enemy_x)enemy_x = z.x;
				}
			}
			for (auto& z : bucked_zombie_list) {
				if (z.path == path&& z.x > x && z.HP > 0) {
					if (z.x < enemy_x)enemy_x = z.x;
				}
			}
			int vx = (enemy_x - x+40) / 80;
			if (p.reload_over) {
				Melon melon(x, y, vx,p.row);
				melon.Set_image();
				melon_list.push_back(melon);
				p.reload_over = false;
				p.reload_once = false;
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
	for (auto& p : melon_list) {
		p.update();
	}
	//Ïû³ıËÀÍöÖ²Îï
	Plant_HP_Check(sunflower_list);
	Plant_HP_Check(peashooter_list);
	Plant_HP_Check(wallnut_list);
	Plant_HP_Check(double_peashooter_list);
	Plant_HP_Check(potato_list);
	Plant_HP_Check(watermelon_list);
	//ÖÖÖ²ÀäÈ´
	sunflower_function.colding();
	Peashooter_function.colding();
	wallnut_function.colding();
	double_peashooter_function.colding();
	potato_function.colding();
	watermelon_function.colding();
	//µ¯Ò©Åö×²
	bullet_hit(pea_list, zombie_list, 30);
	bullet_hit(pea_list, conehead_zombie_list, 30);
	bullet_hit(pea_list, bucked_zombie_list, 30);
	auto m = melon_list.begin();
	while (m!=melon_list.end())
	{
		int m_x = m->x;
		int m_y = m->y;
		for (auto& z1 :zombie_list){
			if (m_x + 35 > z1.x && m_x<z1.x + 60 && m_y + 28>z1.y && m_y < z1.y + 70 && !m->hit_enemy&&z1.path==m->path) {
				m->hit_enemy = true;
				z1.HP -= 90;
				int col = map.get_box_col(z1.x, z1.y);
				kill_scale(col, z1.path);
			}
		}
		for (auto& z2 : conehead_zombie_list) {
			if (m_x + 35 > z2.x && m_x<z2.x + 60 && m_y + 28>z2.y && m_y < z2.y + 70 && !m->hit_enemy && z2.path == m->path) {
				m->hit_enemy = true;
				z2.HP -= 90;
				int col = map.get_box_col(z2.x, z2.y);
				kill_scale(col, z2.path);
			}
		}
		for (auto& z3 : bucked_zombie_list) {
			if (m_x + 35 > z3.x && m_x<z3.x + 60 && m_y + 28>z3.y && m_y < z3.y + 70 && !m->hit_enemy && z3.path == m->path) {
				m->hit_enemy = true;
				z3.HP -= 90;
				int col = map.get_box_col(z3.x, z3.y);
				kill_scale(col, z3.path);
			}
		}
		m++;
	}
	//ÌØÊâ½©Ê¬->ÆÕÍ¨½©Ê¬
	Zombie_transform(conehead_zombie_list);
	Zombie_transform(bucked_zombie_list);
	//¼ì²â½©Ê¬ÊÇ·ñÍ»ÆÆ·ÀÏß
	for (auto& p : zombie_list) {
		if (p.x <= -20&&!win)lost = true;
	}
	for (auto& p : conehead_zombie_list) {
		if (p.x <= -20 && !win)lost = true;
	}
	for (auto& p : bucked_zombie_list) {
		if (p.x <= -20 && !win)lost = true;
	}
}