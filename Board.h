#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Box.h"

const float screen_size = 700;
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
private:
public: //////Variable
	Edge edge;
	int a{}, b{}, totalLines, moveCount{};
	float breadth{};
	int size{};
	std::vector<RectangleShape>rects;				///Save those Rectangle for drawing purpose
	std::vector<CircleShape>circle;					/////Save Dots
	std::vector<Choice>choice;						/////Save Choices
	std::vector<PropOfAnB>selectedLines;			/////Save sum and product to validate
	VertexArray vertex;								///Hold vertex	

public: /////////Func
	Board(int size, RenderWindow& win);
	void LineSelect();												////input Choice
	bool notValid(int a, int b, int size) const;					////Validation
	bool isTaken(int a, int b, std::vector<PropOfAnB>Sum_Product);	////Validation 
	void Draw(RenderWindow&);										////Draw lines and boxes	
	void setBoxes(int);												////Set those boxes

};
