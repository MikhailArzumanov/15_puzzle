#include "handlers.hpp"

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