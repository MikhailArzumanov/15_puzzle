#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <windows.h>

sf::RenderWindow window(sf::VideoMode(720, 720), "15_puzzle");
sf::Clock the_clock;

std::string path;
sf::Texture img;
sf::Sprite the_sprite;
sf::RectangleShape rect(sf::Vector2f(180.f,180.f));


int table[4][4] =
{
	{0,1,2,3},
	{4,5,6,7},
	{8,9,10,11},
	{12,13,14,-1},
};

struct point {
	int i, j;

	point operator+(point another) {
		return point{ i + another.i,j + another.j };
	}
};

void swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void swap(point left, point right) {
	swap(table[left.i][left.j], table[right.i][right.j]);
}

point shifts[4]{
	{1,0},
	{0,1},
	{-1,0},
	{0,-1},
};

point current_space;

void shuffle(int amount) {
	while(amount-->0){
		int shift = rand() % 4;
		if ((shift == 1) && (current_space.j == 3) || (shift == 3) && (current_space.j == 0)) {
			shift = (shift + 2) % 4;
		}
		else if ((shift == 0) && (current_space.i == 3) || (shift == 2) && (current_space.i == 0)) {
			shift = (shift + 2) % 4;
		}
		point new_space = current_space + shifts[shift] ;
		swap(current_space, new_space);
		current_space = new_space;
	}
}
void draw() {
	window.clear();
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++) {
		int val = table[i][j];
		if (val >= 0) {
			the_sprite.setPosition(j * 180, i * 180);
			the_sprite.setTextureRect(sf::IntRect(180*(val%4), 180*(val/4), 180,180));
			window.draw(the_sprite);
		}
		else {
			rect.setPosition(j * 180, i * 180);
			window.draw(rect);
		}
	}
	window.display();
}

void mouse_button_process(sf::Event& event) {
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	if (x < 0 || x>720 || y < 0 || y>720)
		return;
	
	int cell_X = x / 180, cell_Y = y / 180;
	bool is_movable = false;
	std::cout <<"Current space: " << current_space.i << ' ' << current_space.j <<'\n';
	std::cout << "Cell_X: " << cell_X << '\n';
	std::cout << "Cell_Y: " << cell_Y << '\n';

	if (cell_Y > 0)
		is_movable |= (table[cell_Y - 1][cell_X] == -1);
	if (cell_Y < 3)
		is_movable |= (table[cell_Y + 1][cell_X] == -1);
	if (cell_X > 0)
		is_movable |= (table[cell_Y][cell_X-1] == -1);
	if (cell_X < 3)
		is_movable |= (table[cell_Y][cell_X+1] == -1);

	if (is_movable) {
		swap(current_space, point{ cell_Y, cell_X });
		current_space = point{ cell_Y, cell_X };
	}
}

void process_event(sf::Event& event) {
	switch (event.type) {
	case sf::Event::Closed:
		window.close();
		break;
	case sf::Event::MouseButtonPressed:
		mouse_button_process(event);
		break;
	}
}

void event_handler() {
	sf::Event event;
	while (window.pollEvent(event))
		process_event(event);
}


int main(){
	
	srand(time(0));
	std::cout << "Enter the path to the image:\n";
	std::cin >> path;
	img.loadFromFile(path);
	the_sprite.setTexture(img);
	window.clear();
	window.draw(the_sprite);
	window.display();
	Sleep(3000);
	current_space.i = 3;
	current_space.j = 3;
	shuffle(40);
	while (window.isOpen()) {
		float time = the_clock.getElapsedTime().asMilliseconds();
		if (time > 1000.f / 60.f) {
			the_clock.restart();
			event_handler();
			draw();
		}
	}

	std::cout << "Hello World!\n";
}