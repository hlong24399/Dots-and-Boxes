#include <sfml/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Board.h"
#include "Box.h"
#include <cmath>
using namespace sf;
int main() {

	RenderWindow window(VideoMode(screen_size, screen_size), " Dots and Boxes ", Style::Default);
	window.setPosition(Vector2i(1000, 10));
	window.setFramerateLimit(60);
	int edge{}; ///////Size of the game
	std::cout << " Enter the number of dots you want on an edge: ";

	//std::cin >> edge; ////Input length of edge
	edge = 5;

	Board board(edge,window); ////Game starts
	while (window.isOpen()) {
		board.LineSelect();
		
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		board.drawLines(window);
		window.display();

	}
	return 0;
}


