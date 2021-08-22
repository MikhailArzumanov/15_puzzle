#include <vector>
#include <string>
#include <fstream>
#include "environment.hpp"
#include <SFML/Graphics.hpp>
#include "game_gen.hpp"


std::vector<std::string> images_paths;
std::string list_path = "images_list.txt";


void get_links_to_images() {
	std::ifstream in(list_path);
	std::string tmp_path;
	while (!in.eof()) {
		in >> tmp_path;
		images_paths.push_back(tmp_path);
	}
}

void draw_main_menu() {

	window.clear();
	for (int i = 0; i < images_paths.size(); i++) {
		int y_offset = (i/4)*180;
		int x_offset = (i%4)*180;
		std::string path = images_paths[i];
		sf::Texture tmp_texture;
		tmp_texture.loadFromFile(path);
		sf::Sprite tmp_sprite(tmp_texture);

		tmp_sprite.setScale(0.25f, 0.25f);
		tmp_sprite.setPosition(x_offset, y_offset);
		window.draw(tmp_sprite);
	}
	window.display();
}


bool handle_click(sf::Event mouse_event) {
	int x = mouse_event.mouseButton.x;
	int y = mouse_event.mouseButton.y;
	int i = x/180 + 4*(y/180);
	if(i >= images_paths.size())
		return false;
	path = images_paths[i];
	return true;
}

void gui_start() {
	get_links_to_images();
	draw_main_menu();
	bool was_choosen = false;
	while(!was_choosen) {
		sf::Event e;
		while(window.pollEvent(e)){
			if (e.type == sf::Event::MouseButtonPressed) {
				if (handle_click(e))
					was_choosen = true;
			}
		}
	}
	gen_game(path);

}