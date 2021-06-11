#include "handlers.hpp"

void click_cell_XY(int cell_X, int cell_Y) {
	bool is_movable = false;
	if (cell_Y > 0)
		is_movable |= (table[cell_Y - 1][cell_X] == -1);
	if (cell_Y < 3)
		is_movable |= (table[cell_Y + 1][cell_X] == -1);
	if (cell_X > 0)
		is_movable |= (table[cell_Y][cell_X - 1] == -1);
	if (cell_X < 3)
		is_movable |= (table[cell_Y][cell_X + 1] == -1);
	if (is_movable) {
		point p = point{ cell_Y, cell_X };
		swap(current_space, p);
		current_space = p;
	}
}
void mouse_button_process(sf::Event& event) {
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	if (x < 0 || x>720 || y < 0 || y>720)
		return;

	int cell_X = x / 180, cell_Y = y / 180;
	click_cell_XY(cell_X, cell_Y);
}