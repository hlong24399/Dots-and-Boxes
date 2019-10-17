#include <sfml/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Board.h"
#include <cmath>
using namespace sf;

int main() {

	RenderWindow window(VideoMode(screen_x, screen_y), " Dots and Boxes ", Style::Default);
	window.setPosition(Vector2i(700,100));
	window.setFramerateLimit(144);
	int edge{}; ///////Size of the game
	std::cout << " Enter the number of dots you want on an edge: ";
	
	//std::cin >> edge; ////Input length of edge
	edge = 3;
	
	Board board(edge); ////Game starts
	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::White);
		//window.draw(vertex);
		window.display();
		
	}
	return 0;
}

