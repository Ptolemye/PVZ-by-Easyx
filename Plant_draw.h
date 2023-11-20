#pragma once
#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include"Map.h"
#include"Player.h"
#include<iostream>
#include"Plant_sow.h"
void Plant_draw() {
	for (auto& p : sunflower_list) {
		p.draw();
	}
	for (auto& p : peashooter_list) {
		p.draw();
	}
	for (auto& p : wallnut_list) {
		p.draw();
	}
}