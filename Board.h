#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Box.h"
const float screen_size = 1000;
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
	int a{}, b{}, totalLines, moveCount{};
	int size{};
	std::vector<CircleShape>circle; /////Save Circle
	std::vector<Choice>choice; /////Save Choice
	std::vector<PropOfAnB>selectedLines; /////Save sum and product to validate
	VertexArray vertex; ///Hold vertex	
	std::vector<int>selectedDots;
	Box box;
public: /////////Func

	Board(int size, RenderWindow &win); 
	void LineSelect(); ///input Choice
	bool notValid(int a, int b, int size) const; //Validation
	bool isTaken(int a, int b, std::vector<PropOfAnB>Sum_Product); //Validation 
	void drawLines(RenderWindow &); //Draw those lines
};
