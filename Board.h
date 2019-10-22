#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
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
	float size{};
	std::vector<CircleShape>circle; /////Save Circle
	std::vector<Choice>choice; /////Save Choice
	std::vector<PropOfAnB>selectedLines; /////Save sum and product to validate
	VertexArray vertex; ///Hold vertex	
	std::vector<int>selectedDots;
public: /////////Func

	Board(int size, RenderWindow &win);
	void LineSelect(); ///input Choice
	bool notValid(int a, int b, int size) const;
	bool isTaken(int a, int b, std::vector<PropOfAnB>Sum_Product) ;
	void drawLines(RenderWindow &);
	bool isBoxed(int a, int b); ///////////////How
};
