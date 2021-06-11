#pragma once
#include "libs.hpp"

extern	sf::RenderWindow window;
extern	sf::Clock the_clock;

extern	std::string path;
extern	sf::Texture img;
extern	sf::Sprite the_sprite;
extern	sf::RectangleShape rect;

struct point {
	int i, j;
	point operator+(point another);
};
extern const int TABLE_TILES;
extern const int SPACE_CODE;

extern int** table;
extern point current_space;

extern point shifts[4];

void set_table();
void init_table();
void swap(int& a, int& b);
void swap(point left, point right);