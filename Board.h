#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
const int screen_x = 1000;
const int screen_y = 1000;
using namespace sf;
struct Choice {
	int a;
	int b;
};
class Board {
public:
	std::vector<CircleShape>circle;
	std::vector<Choice>choice;
public:
	Board(int size);
public:
	std::vector<CircleShape> getCircle();//return vector of dots
	void setChoice(int a, int b);
	void PrintChoice();
};
