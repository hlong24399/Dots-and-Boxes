#include <sfml/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Board.h"
#include <cmath>
#include "Box.h"
using namespace sf;

int main() {

	RenderWindow window(VideoMode(screen_size,screen_size ), " Dots and Boxes ", Style::Default);
	window.setPosition(Vector2i(1000,100));
	window.setFramerateLimit(144);
	int edge{}; ///////Size of the game
	int boxIndex{};
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
		window.clear(Color::Cyan);
		board.Draw(window);
		window.display();
		
	}
	return 0;
}

