#include <sfml/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Board.h"
#include <cmath>
using namespace sf;
bool notValid(int a, int b, int size) {
	if ((abs(b - a) == size || (abs(b - a) == 1 && std::max(a,b) % size != 0)) && (a < size * size && b < size * size) )	return false;
	std::cout << " Not Valid " << std::endl;
	return true;
}
struct PropOfAnB {
	int sum;
	int product;
};
bool isTaken(int a, int b, std::vector<PropOfAnB>inputStore) {
	bool SumValid = false, ProductValid = false;
	for (auto i : inputStore) {
		if ((a * b) == i.product && (a + b) == i.sum) return true;
	}
	return false; //Have to be false
}


int main() {
	
	RenderWindow window(VideoMode(screen_x,screen_y), " Dots and Boxes ", Style::Default);
	window.setPosition(Vector2i(1440,1440));
	window.setFramerateLimit(144);
	int edge{}, a{}, b{}, product{}, sum{};
	std::cout << " Enter the number of dots you want on an edge: ";
	//std::cin >> edge; ////Input length of edge
	edge = 3;
	const int totalLines = 2 * (edge * edge - edge); //////total num of lines
	std::cout << " Here is total line " << totalLines << std::endl; //////printout totalLines
	std::vector<PropOfAnB>selectedLines(totalLines);
	Board board(edge); /////////////////Print those dots----------------------------------------------
	int i{};
	while (window.isOpen()) {
		
		//for (int i = 0; i < totalLines; i++) { ///////PlayerSelection..................
			std::cout << " \n Select the dot that you want to connect: ";
			std::cin >> a >> b;
			while ((notValid(a, b, edge)) || (isTaken(a, b, selectedLines))) { ////Validation
					std::cout << " Wrong input " << std::endl;
					std::cin.clear();
					std::cin >> a >> b;
			}
			board.setChoice(a, b);
			selectedLines[i].product = a * b;
			selectedLines[i].sum = a + b;
			std::cout << " Data is in " << std::endl;
			std::cout << " Here is i " << i << std::endl;
			i++;
		//}
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::White);
		for ( auto i : board.getCircle()) {
			window.draw(i);			
		}
		window.display();
		board.PrintChoice();
	}
	return 0;
}
