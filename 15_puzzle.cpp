﻿#include "draw.hpp"
#include "game_gen.hpp"
#include "handlers.hpp"
#include "choose_level.hpp"

void cycle();
void tick();

void gameover() {
	window.close();
}

int WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
) {
	set_table();
	srand(time(0));

	//console_start();
	gui_start();
	while (window.isOpen())
		cycle();
}

void cycle() {
	float time = the_clock.getElapsedTime().asSeconds();
	if (time > 1/60.f)
		tick();
}

void tick() {
	the_clock.restart();
	event_handler();
	draw();
	if (is_it_solved())
		gameover();
}