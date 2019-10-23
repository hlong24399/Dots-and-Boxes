#pragma once
#include <SFML/Graphics.hpp>
#include <sfml/Window.hpp>
#include <iostream>
#include <utility>

using namespace sf;


class Box
{
	friend class Board;
public:
	std::vector<std::pair<int, int>> edges;

public:
	Box() {
		std::cout << " Yep ";
	}
	void printBox() {
		std::cout << " Here is what inside the box " << std::endl;
		for (auto i : edges) {
			std::cout << i.first << " --------- " << i.second << std::endl;
		}
	}
	/*-Idea for edgeChecking-----------------------------------------------------
bool isSquareComplete(int x, int y) {
	return linesX[x][y] && linesX[x + 1][y] && linesY[x][y] && linesY[x][y + 1];
}*/
	void isBoxed() {
		bool top = false, bottom = false, right = false, left = false;
		

	}
};
