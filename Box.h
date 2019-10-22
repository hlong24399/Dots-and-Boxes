#pragma once
#include <SFML/Graphics.hpp>
#include <sfml/Window.hpp>
#include <iostream>
#include <utility>
#include "Board.h"
using namespace sf;
class Box
{
	friend class Board;
private:
	std::vector<std::pair<int, int>> edges;
public:
	Box() {
		std::cout << " Yep ";
	}
	void setEdges(int small, int big) {
		std::pair<int, int> anEdge;
		anEdge = std::make_pair(small, big);
		edges.push_back(anEdge);
	}
};

