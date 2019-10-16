#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
const int screen_x = 600;
const int screen_y = 600;
using namespace sf;
class Board {
private:
	std::vector<CircleShape>circle;
public:
	Board(int size);
	std::vector<CircleShape> getCircle();//return vector of dots
};
