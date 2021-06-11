#include "game_gen.hpp"

void rand_shift() {
	int shift = rand() % 4;
	point new_space = current_space + shifts[shift];
	if ((new_space.i > 3) || (new_space.i < 0) || (new_space.j > 3) || (new_space.j < 0)) {
		shift = (shift + 2) % 4;
		new_space = current_space + shifts[shift];
	}

	swap(current_space, new_space);
	current_space = new_space;
}
void shuffle(int amount) {
	while (amount-- > 0)
		rand_shift();
}