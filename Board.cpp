#include "Board.h"
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
