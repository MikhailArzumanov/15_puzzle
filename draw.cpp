#include "draw.hpp"
void draw_space(int i, int j) {
	rect.setPosition(j * 180, i * 180);
	window.draw(rect);
}
void draw_tile(int i, int j, int val) {
	the_sprite.setPosition(j * 180, i * 180);
	the_sprite.setTextureRect(sf::IntRect(180 * (val % 4), 180 * (val / 4), 180, 180));
	window.draw(the_sprite);
}
void draw_cell(int i, int j) {
	int val = table[i][j];
	if (val >= 0)
		draw_tile(i, j, val);
	else draw_space(i, j);
}
void draw() {
	window.clear();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			draw_cell(i, j);
	window.display();
}