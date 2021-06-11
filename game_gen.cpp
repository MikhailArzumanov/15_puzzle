#include "game_gen.hpp"

void console_start() {
	std::cout << "Enter the path to the image:\n";
	std::cin >> path;
	gen_game(path);
}

void gen_game(std::string path) {

	img.loadFromFile(path);
	the_sprite.setTexture(img);
	window.clear();
	window.draw(the_sprite);
	window.display();

	Sleep(3000);

	init_table();
	current_space.i = TABLE_TILES - 1;
	current_space.j = TABLE_TILES - 1;

	shuffle(400);
}