#include "draw.hpp"
#include "game_gen.hpp"
#include "handlers.hpp"

void cycle();
void tick();

int main(){
	set_table();
	srand(time(0));

	console_start();
	while (window.isOpen())
		cycle();
}

void cycle() {
	float time = the_clock.getElapsedTime().asMilliseconds();
	if (time > 50.f/3.f)
		tick();
}

void tick() {
	the_clock.restart();
	event_handler();
	draw();
}