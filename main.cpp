#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Board.h"
#include <cmath>
#include "Box.h"
using namespace sf;

void welcome();

Color c = Color(0,255,0, 200);
int main() {

	RenderWindow window(VideoMode(screen_size,screen_size ), " Dots and Boxes ", Style::Default);
	window.setPosition(Vector2i(1000,100));
	window.setFramerateLimit(144);
	int edge{}; ///////Size of the game
	int moveCount{};
	welcome();
	std::cin >> edge; ////Input length of edge
	//edge = 4;
	Board board(edge,window,c); ////Game starts
	while (window.isOpen()) {
		if (moveCount != edge * edge - edge) {			//Sentinel to end the game
			board.LineSelect();
			board.getBot();
			moveCount++;
		}
		else {
			board.printScore();
			std::cin.ignore();
			std::cin.get();
			return 0;
		}
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(c);
		board.Draw(window);
		window.display();

	}
	return 0;
}


void welcome() {
	std::cout << "welcome to Dots and Boxes game, you have to complete more squares on the boards than the bots to win the game. Start by choosing your board size, and make your move by choosing the two dots to form an edge!" << std::endl;
}
