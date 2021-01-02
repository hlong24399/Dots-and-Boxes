#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Board.h"
#include <cmath>
#include "Box.h"
using namespace sf;

void welcome();
Color color = Color(0,255,0, 200);
int main() {

	RenderWindow window(VideoMode(screen_size,screen_size ), " Dots and Boxes ", Style::Default);
	window.setPosition(Vector2i(1000,100));
	window.setFramerateLimit(144);
	int edge{}; //Size of the game
	int moveCount{};
	welcome();
	// std::cin >> edge; //Input length of edge
	edge = 4;

	int ord{};
	int c = 1;
	Board board(edge,window,color); //Game starts
	while (window.isOpen()) {
		//Make the game let player keep going if a box is complete, same as the bot. Use on_streak bool to determine it.
		if (moveCount != 2*(edge * edge - edge)) {			//Sentinel to end the game
			switch(c) {
				case 1:
					std::cout << "case1";
					board.LineSelect();
					ord = 0;
					board.detect_box(ord);
					if (board.on_streak)
					{
						c = 1;
						break;
					}
					else {
						c = 2;
						break;
					}
				case 2:
					std::cout << "case2"	;
					board.getBot();
					ord = 1;
					board.detect_box(ord);
					if (board.on_streak)
					{
						c = 2;
						break;
					}
					else
					{
						c = 1;
						break;
					}
			}
			moveCount++;
			std::cout << moveCount;
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
		window.clear(color);
		board.Draw(window);
		window.display();

	}
	return 0;
}
