#include "Board.h"
#include <iostream>
//Create grid
Board::Board(int size) {
	CircleShape aCircle;
	//Print those dots----------------------------------------------
	for (int i = 0; i < size * size; i++) {
		circle.push_back(aCircle);
		circle[i].setRadius(10);
		circle[i].setPosition((40.f + (i % size) * screen_x / size), (40.f + (i / size) * screen_y / size));
		circle[i].setFillColor(Color::Red);
		circle[i].setOrigin(5, 5);

	}
}
std::vector<CircleShape> Board::getCircle() {        //return vector of dots
	return circle;
}

void Board::setChoice(int a, int b)
{
	Choice aChoice;
	aChoice.a = a;
	aChoice.b = b;
	choice.push_back(aChoice);
}

void Board::PrintChoice()
{
	for (auto i : choice) std::cout << i.a << " ---------- " << i.b << std::endl;
}
