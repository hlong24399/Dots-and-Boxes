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
struct PropOfAnB {
	int sum;
	int product;
};

class Board {
	
public: //////Variable
	int a{}, b{}, size{}, totalLines;
	std::vector<CircleShape>circle; /////Save Circle
	std::vector<Choice>choice; /////Save Choice
	std::vector<PropOfAnB>selectedLines; /////Save sum and product to validate
	VertexArray vertex;	
public: /////////Func

	Board(int size);
	void LineSelect(); ///input Choice
	void printLine(); //Print choice
	bool notValid(int a, int b, int size);
	bool isTaken(int a, int b, std::vector<PropOfAnB>Sum_Product);
	VertexArray drawLines(int i);
};
