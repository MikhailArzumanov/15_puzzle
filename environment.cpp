#include "environment.hpp"

sf::RenderWindow window(sf::VideoMode(720, 720), "15_puzzle");
sf::Clock the_clock;

std::string path;
sf::Texture img;
sf::Sprite the_sprite;
sf::RectangleShape rect(sf::Vector2f(180.f, 180.f));

int** table;
point current_space;

const int TABLE_TILES = 4;
const int SPACE_CODE = -1;

point point::operator+(point another) {
	return point{ i + another.i,j + another.j };
}

point shifts[4]{
	{1,0},
	{0,1},
	{-1,0},
	{0,-1},
};